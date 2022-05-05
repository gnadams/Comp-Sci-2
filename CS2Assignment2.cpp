/*
   COPYRIGHT (C) 2022 Gregory Adams (gna5) All rights reserved.
   CSII assignment Dos
   Author.  Gregory Adams
            gna5@uakron.edu
   Version. 1.01 01.01.2022
   Purpose: This program is the test cases for the  assignment
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class myInteger
{


public:




    myInteger(); // default constructor
    myInteger(int); // basically default constructor

    myInteger(string); // constuctor for converting chars into ints

    friend std::ostream& operator << (std::ostream& out, const myInteger&); // pre: myInteger | post:
    const static size_t maxSize = 40;

    myInteger& operator= (const myInteger&); // pre: myInt = myInt| post: the object is set equal by reference


    myInteger operator+ (const myInteger&);  // pre: myInt + myInt | post: returns the sum as myInteger
    myInteger operator+ (const string& str); // pre: myInt + string | post: returns the sum as myInteger

    myInteger operator- (const myInteger& rObj); // pre: myInt - myInt | post: returns the difference as myInteger
    myInteger operator- (const string& str); // pre: myInt - string | post: returns the difference as myInteger

    ~myInteger(); // deconstructor


private:

    short* ptr; // pointer to first element of pointer-based array of shorts

};



// As always with drivers: make sure that the program runs successfully with
// the following b/c that's what will be the test
int main()
{


    myInteger n1{ 7654321 };

    myInteger n2{ 7891234 };

    myInteger n3{ "99999999999999999999999999999" };
    myInteger n4{ "1" };
    myInteger n5;

    cout << "n1 is " << n1 << "\nn2 is " << n2
        << "\nn3 is " << n3 << "\nn4 is " << n4
        << "\nn5 is " << n5 << endl << endl;

    cout << "*-----------------*" << endl;
    cout << " addition cases" << endl;
    cout << "*-----------------*" << endl << endl;
    cout << (n1 + n2) << endl;

    n5 = n1 + n2;
    cout << n1 << " + " << n2 << " = " << n5 << "\n\n";

    cout << n3 << " + " << n4 << "\n= " << (n3 + n4) << "\n\n";

    n5 = n1 + 9;
    cout << n1 << " + " << 9 << " = " << n5 << "\n\n";

    n5 = n2 + "10000";
    cout << n2 << " + " << "10000" << " = " << n5 << endl << endl;

    cout << "*-----------------*" << endl;
    cout << " subtraction cases" << endl;
    cout << "*-----------------*" << endl << endl;;
    cout << (n2 - n1) << endl;

    n5 = n2 - n1;
    cout << n2 << " - " << n1 << " = " << n5 << "\n\n";

    cout << n3 << " - " << n4 << "\n= " << (n3 - n4) << "\n\n";

    n5 = n1 - 9;
    cout << n1 << " - " << 9 << " = " << n5 << "\n\n";

    n5 = n2 - "10000";
    cout << n2 << " - " << "10000" << " = " << n5 << endl;
    cout << " \nEnd of program \n";

}
// HERE are the methods - WRITE these for FULL credit

// default constructor; conversion constructor that converts
// an integer into a myInteger object
myInteger::myInteger()  // if the object is called and nothing is given, ptr will delete and set ptr to null
{
    ptr = new short[maxSize];
    for (int i = 0; i < maxSize; ++i) // by default if no number is initialized set everything to 0
    {
        ptr[i] = 0;
    }

}

/// pre: myInteger{integer}
/// post: allocates size 40 array of shorts and initialize to 0
myInteger::myInteger(int myInt)
{

    string temp = std::to_string(myInt); // converting the original int to a string
                                        // so that I can access each individual digit

    size_t size = temp.length();       // using the string I can get the size of the integer
    ptr = new short[maxSize];

    for (int i = 0; i < (maxSize - size); ++i)
    {
        ptr[i] = 0; // sets all the leading digits before our real number to 0

    }

    for (int i = 0; i < size; ++i)
    {                                   // ptr sub maxSize - size gives us the new spot in the array behind all of the leading zeros
        ptr[maxSize - size + i] = int(temp[i] - 48);    // int converts to ascii value, to combat this is subtract 48
    }
}


// conversion constructor that converts a character string
// representing a large integer into a myInteger object

myInteger::myInteger(string myString)
{
    size_t size = myString.size();

    ptr = new short[maxSize];

    for (int i = 0; i < (maxSize - size); ++i)
    {
        ptr[i] = 0; // sets all the leading digits before our real number to 0

    }

    for (int i = 0; i < size; ++i)
    {
        ptr[maxSize - size + i] = int(myString[i] - 48);
    }
}



// destructor for class myInteger

myInteger::~myInteger()
    {
        delete[] ptr;
        ptr = nullptr;
    }

// assignment overload b/c it is dynamic
// lhs: object, rhs: object
// overloaded assignment operator;
// const return avoids: (a1 = a2) = a3
/// Pre: myInteger = myInteger
/// Post: returns lhs MyInteger by reference

myInteger& myInteger::operator= (const myInteger &myObj)
{
	if (&myObj == this) // check to see if it's itself
		return *this;

	if (ptr == nullptr) // allocate if data is not allocated
	{
		ptr = new short[maxSize];
	}
	for (int i = 0; i < maxSize; i++) // copy all of the data
	{
		ptr[i] = myObj.ptr[i];
	}
}


// addition operator; myInteger + myInteger

/// pre: myInteger + myInteger
/// post: returns sum as myInteger
myInteger myInteger::operator+ (const myInteger& rObj)
{
    myInteger sum;
    sum.ptr = new short[maxSize];

    for (auto i = 0; i < maxSize; ++i)
    {
        sum.ptr[i] = 0;
    }

    bool carry = false;
    for (int i = maxSize - 1; i >= 0; --i) // run for loop in opposite order
    {

        if (carry == true)   // IF there is a carry over from the previous digit
        {
            sum.ptr[i] = this->ptr[i] + rObj.ptr[i] + 1; // 1 from the previous number will be added
        }
        else
        {
            sum.ptr[i] = this->ptr[i] + rObj.ptr[i]; // if no carry, this will be added as normal
        }
        if (sum.ptr[i] > 9) // if the number is 10 or greater, there has to be a carry
        {
            sum.ptr[i] = sum.ptr[i] - 10; //  10 is subtracted to get a single digit
            carry = true;               // a 1 will be added to the next higher digit
        }
        else
        {
            carry = false;
        }
    }

    return sum;
}


// addition operator; myInteger + int
// addition operator;
// myInteger + string that represents large integer value
/// pre: myInteger + string
/// post: returns sum as myInteger
myInteger myInteger::operator+ (const string& str)
{
    myInteger strToInt;  // holds the converted values from the string
    myInteger sum;      // holds the sum
    int length = str.length(); // gets the length of the string to handle the allocation
    for (auto i = 0; i <40; ++i)
    {
        strToInt.ptr[i] = 0; // sets arrays to 0 by default
        sum.ptr[i] = 0;
    }
    for (auto i = 0; i < length; ++i) // for loop counts from 0 up to however long the string is
    {


        strToInt.ptr[maxSize - i] = int(str[length - 1 - i] - 48); // 39 is the max size of the array, and length - 1 is the max size
                                                              // subtracting the size - i makes the array add characters from the back

    }

    /// ^^ above part is just getting the string into int array format

    bool carry = false; // bool used for carrying or not

    for (auto i = (40 - 1); i >= 0; --i) // i starts at 39 and runs down to 0
    {

      if (carry == true)   // IF there is a carry over from the previous digit
        {
            sum.ptr[i] = this->ptr[i] + strToInt.ptr[i] + 1; // 1 from the previous number will be added
        }
        else
        {
            sum.ptr[i] = this->ptr[i] + strToInt.ptr[i]; // if no carry, this will be added as normal
        }
        if (sum.ptr[i] > 9) // if the number is 10 or greater, there has to be a carry
        {
            sum.ptr[i] = sum.ptr[i] - 10; //  10 is subtracted to get a single digit
            carry = true;               // a 1 will be added to the next higher digit
        }
        else
        {
            carry = false;
        }

    }

    return sum;

}

// subtraction operator; myInteger - myInteger
/// pre: myInteger - myInteger
/// post: returns difference in myInteger
myInteger myInteger::operator- (const myInteger& rObj)
{
    myInteger dif;
    dif.ptr = new short[40];

    for (auto i = 0; i < 40; ++i)
    {
        dif.ptr[i] = 0;
    }

    bool carry = false;
    for (int i = 39; i >= 0; --i)
    {

        if (carry == true)   // IF there is a carry over from the previous digit
        {
            dif.ptr[i] = this->ptr[i] - rObj.ptr[i] - 1; // 1 from the previous number will be subbed
        }
        else
        {
            dif.ptr[i] = this->ptr[i] - rObj.ptr[i]; // if no carry, this will be subbed as normal
        }
        if (dif.ptr[i] < 0) // if the number is less than 0, there has to be a carry
        {
            dif.ptr[i] = dif.ptr[i] + 10; //  10 is Added to get a single digit
            carry = true;               // a 1 will be subbed from the next higher digit
        }
        else
        {
            carry = false;
        }
    }

    return dif;
}



// subtraction operator; myInteger - int
// subtraction operator;
// myInteger - string that represents large integer value
/// pre: myInteger - string
/// post: returns difference inside myInteger

myInteger myInteger::operator- (const string& str)
{
    myInteger strToInt;  // holds the converted values from the string
    myInteger dif;      // holds the difference
    int length = str.length(); // gets the length of the string to handle the allocation
    for (auto i = 0; i <40; ++i)
    {
        strToInt.ptr[i] = 0; // sets arrays to 0 by default
        dif.ptr[i] = 0;
    }
    for (auto i = 0; i < length; ++i) // for loop counts from 0 up to however long the string is
    {
        strToInt.ptr[39 - i] = int(str[length - 1 - i] - 48); // 39 is the max size of the array, and length - 1 is the max size
                                                              // subtracting the size - i makes the array add characters from the back
    }

    /// ^^ above part is just getting the string into int array format

    bool carry = false;
    for (int i = 39; i >= 0; --i)
    {
        if (carry == true)   // IF there is a carry over from the previous digit
        {
            dif.ptr[i] = this->ptr[i] - strToInt.ptr[i] - 1; // 1 from the previous number will be subbed
        }
        else
        {
            dif.ptr[i] = this->ptr[i] - strToInt.ptr[i]; // if no carry, this will be subbed as normal
        }
        if (dif.ptr[i] < 0) // if the number is less than 0, there has to be a carry
        {
            dif.ptr[i] = dif.ptr[i] + 10; //  10 is Added to get a single digit
            carry = true;               // a 1 will be subbed from the next higher digit
        }
        else
        {
            carry = false;
        }
    }

    return dif;


}
/// pre : myInteger
/// post : ostream&
// overloaded output operator
std::ostream& operator << (std::ostream& out, const myInteger& myNum)
{
   bool zero = true;    // this bool is true by default so
   int lastZero;            // if all 0s are detected the if loop later will run
    for (int i = 0; i < myNum.maxSize; ++i)
    {
        if (myNum.ptr[i] != 0)
        {
            lastZero = i;
            zero = false; // if a number not 0 is found this is set to false
            break;
        }
    }

    if (zero)
    {
        out << myNum.ptr[0];
        return out;

    }

    for (int i = lastZero; i < myNum.maxSize; ++i)
    {

        out << myNum.ptr[i];
    }

    return out;
}
