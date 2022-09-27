//
//   COPYRIGHT (C) gna5@uakron.edu>, 2022  All rights reserved.
//   Gregory Adams 
//   Purpose: This is myCode and is based upon what we study for Comp Sci
//
#define _CRT_SECURE_NO_WARNINGS
#include <cassert>
#include <iosfwd>
#include <iostream>
#include <iomanip>
#include <memory>
#include <cstring>

//Global constants

// *************************************************
// PLACE ALL OF THIS PROGRAM'S prototypes and Declarations here
//
// This code would normally go into a dot hpp file
//
// SPECIFICATION HERE
//
// *************************************************

class myType
{
public:
    myType(); // Default construction; the default value shall be the empty object.

    myType(const char*);
    //Pre: pointer must not be a null pointer
    //Post: will initialize an object to a object literal

    myType(const char*, std::size_t);
    //Pre: c-object must not be null and have valid size as size_t
    //Post: will initialize object to the amount of characters in a literal

    // code the remainder of the method prototypes ...
    bool empty() const;

    short size();

    char* data();

    void clear();

    myType(const myType&);

    myType& operator=(const myType& obj);
    myType& operator=(const char[]);
    myType& operator+=(const myType&);

    bool operator==(const char* cha);

    bool operator==(const myType& obj) const; // compares object with an object
    bool operator!=(const myType& obj) const; // compares object with an object

    bool operator<(const myType& obj); // greator or lessthan / equal to operator overloading
    bool operator>(const myType& obj); // compares 2 objects together
    bool operator<=(const myType& obj);
    bool operator>=(const myType& obj);

    operator short int();

    size_t find(char) const;
    char* subpart(short, short) const;
    void copier(myType&);

    ~myType() //deconstructor
    {
        delete[] typeVar;
        typeVar = nullptr;
    }

    // Defines the npos value. for the myType class
    static constexpr std::size_t npos = -1;

private:
    char* typeVar;
    short typeLength;
};

int
main()
{

    // these are declarations - prefer this or std:: prefix
    using std::setw;
    using std::left;
    using std::right;
    short points = 0;
    char myChrs[] = { '1', '8', '4', ' ', 'd', 'i', 'v', ' ', '6', '\0' };
    // Check the default contstructor (ctor).
    {
        myType t0;
        assert(t0.empty());
        std::cout << "default ctor and empty passed " << std::endl;
        points += 2;
    }

    // A member function to return the length of the object.
    // Returns a std::size_t (unsigned integer) value. The size() function
    // shall not modify the object t1.
    //
    // This operation shall be constant time (i.e., you cannot traverse the
    // underlying object to compute the length).

    {
        myType t1 = "365 div 7";
        std::size_t n = t1.size();
        std::cout << "Size is " << n << std::endl;
        points += 2;
    }



    // object ctor
    {
        char const* str = "402 add 5009";
        myType t2 = str;
        assert(t2.data() != str);
        assert(strcmp(t2.data(), str) == 0);
        std::cout << "object ctor passed " << std::endl;
        points += 2;
    }


    // Raw C-object access, which returns the underlying array of
    // characters as a pointer. This member function shall not modify its
    // object.
    {
        myType t3 = "5764 div 9";
        char const* p1 = t3.data();
        std::cout << "object raw ptr access passed " << std::endl;
        points += 2;
    }

    // Copy ctor
    // Initialization by a c-string array. The initialized object (t1)
    // shall be equal to the char array after initialization.
    {
        myType t1 = myChrs;
        assert(!strcmp(t1.data(), myChrs));
        std::cout << "copy ctor passed " << std::endl;
        points += 2;
    }



    // copy ctor plus
    // Initialization by a literal. The initialized object (t4)
    // shall be equal to the literal after initialization.
    // The literal shall not be a null pointer. You must assert
    // this property.
    // Copy construction. The initialized object (t5) shall be equal to
    // the original (t4) after initialization.


    {
        myType t4 = "900 mlt 9";
        myType t5 = t4;
        assert(strcmp(t4.data(), t5.data()) == 0);
        std::cout << "copy ctor plus passed " << std::endl;
        points += 2;
    }



    // Initialization by a bounded literal. The initialized object (t2)
    // shall be equal to the first n characters of the given literal.
    // The object shall not be null and shall have at least length n.
    // You must assert this property. Hint: use std::strnlen and be aware
    // that it may not insert a null-terminator.
    {
        myType t2("76 sub 75", 6); // t2 is equal to "76 sub".
        assert(!strcmp(t2.data(), "76 sub"));
        std::cout << "portion ctor passed " << std::endl;
        points += 2;

    }


    // Copy assignment. After assignment, the assigned object on the left (t1)
    // shall be equal to the value on the right (t2).
    {
        //
        myType t1 = "99 sub 0";
        myType t2;
        t2 = t1;
        assert(strcmp(t1.data(), t2.data()) == 0);
        std::cout << "copy assignment passed " << std::endl;
        points += 2;


        // Compound @@ addition/assignment (concatenation). Compounds (adds)
        // the left and right values to form the updated t4 @@.
        myType t4("727 mlt 3");
        myType t5("3 mlt 3");
        t4 += t5;
        std::cout << "compound assignment passed " << std::endl;
        points += 2;

    }


    // Assignment to an object. After assignment, the object on the left (t1)
    // shall be equal to the object literal on the right.
    {
        myType t1;
        t1 = "32767 sub -32768";
        assert(!strcmp(t1.data(), "32767 sub -32768"));
        std::cout << "object literal assignment passed " << std::endl;
        points += 2;
    }

    // Assignment to an object. After assignment, the object on the left (t1)
    // shall be equal to the c-string on the right.
    {
        myType t1;
        t1 = myChrs;
        assert(!strcmp(t1.data(), myChrs));
        std::cout << "object cstring assignment passed " << std::endl;
        points += 2;
    }


    // self assign
    {
        myType t1 = "-32767 sub 32767";
        t1 = t1;
        std::cout << "object literal assignment passed " << std::endl;
        points += 2;
    }


    // A member function to determine make an object is empty.
    // the object is cleared of any and all values (emptied)
    {
        myType t1 = "-32767 sub 32767";
        t1.clear();
        assert(t1.empty());
        std::cout << "clear passed " << std::endl;
        points += 2;
    }

    // A member function to determine if a object is empty. Returns true
    // if t1 is the empty object. The empty() function shall not modify
    // the object t1 (i.e., the member function must be const).
    {
        myType const t1;
        assert(t1.empty());
        myType const t2 = "";
        assert(t2.empty());
        std::cout << "empty passed " << std::endl;
        points += 2;
    }
    /*
    // Character access. Support reading and writing of characters using
    // the subscript operator. Both operators take a std::size_t argument n,
    // such that n >= 0 and n < size(). You must assert that the index is
    // in bounds.
    {
        myType t1 = "767 sub 768";
        t1[0] = '7';
        assert(t1[0] == '7');

        myType const t2 = "95 div 5";
        assert(t2[0] != 't');
        std::cout << "index accessing passed " << std::endl;
        points += 2;
    }
    */
    // A member function that returns the index of the first character
    // in the object. This shall return a std::size_t value. If no such
    // character exists, return npos. Hint: see std::strchr.
    //
    // Note that npos is already defined within your class.
    //
    // This function shall not modify its object.
    {
        myType const t1 = "85 sub 40";
        assert(t1.find('s') == 3);
        assert(t1.find('x') == t1.npos);
        std::cout << "find passed " << std::endl;
        points += 2;
    }

    // A member function that creates a subpart comprising all of the
    // characters starting at an index i and containing n characters. The
    // index i shall be a valid position in the object. You must assert
    // this condition. If n is larger than the number of characters past i
    // then all characters after i are copied to the the output.
    // Hint: use your bounded C-object constructor.
    //
    // This function shall not modify its object.
    {
        myType const t1 = "700 mlt 7";
        myType t2 = t1.subpart(0, 3);
        myType t3 = t1.subpart(4, 3);
        assert(t2 == "700");
        assert(t3 == "mlt");
        std::cout << "object subpart passed " << std::endl;
        points += 2;
    }

    // Equality comparisons. Two objects compare equal when they have the
    // same sequence of characters. Hint: see std::strcmp.
    {
        myType const t1 = "855 sub 854";
        myType const t2 = "7 add 7";
        assert(t1 == t1);
        assert(t1 != t2);
        std::cout << "object equality comparison passed " << std::endl;
        points += 2;
    }

    // ordering. One object compares less than another when it lexicographically
    // precedes it. Hint: see std::strcmp
    {
        myType t1 = "855 sub 854";
        myType t2 = "854 sub 855";
        assert(t2 < t1);
        assert(t1 > t2);
        assert(t1 <= t1);
        assert(t1 >= t1);
        std::cout << "lexicographic ordering passed " << std::endl;
        points += 2;
    }
    /*
    // concatenation @@. Must be same operator or flag as error. Notice the method
    // performs the mathematical expression and places the result in the appropriate
    // positions. Notice t1 and t2 operations performed, result replaced the t1 or t2
    // and operator retained.

    {
        myType t1 = "9303 div 3";
        myType t2 = "3 div 1";
        myType t3 = t1 + t2;  // t3 is from (left) 3/9303 and (right) 1/3
        myType t4 = "3101 div 3";
        assert(t3 == t4);
        myType t5 = "7 sub 2";
        myType t6 = t3 + t5; // this should generate an error message from the function
        std::cout << "logical concatenation passed " << std::endl;
        points += 4;
    }

    // self concatenation
    {
        myType t1 = "843 add 7";
        t1 += t1;
        myType t2 = "843 add 7";
        assert(t1 == t2);
        std::cout << "self-concatenation avoided " << std::endl;
        points += 2;
    }
    // computational conversion @@ - convert the cstring into an expression and
    // return the result as a short integer
    */
    {
        myType t1 = "843 add 7";
        short answer1 = t1;
        std::cout << "Addition = " << answer1 << std::endl;
        myType t2 = "857 sub 7";
        short answer2 = t2;
        std::cout << "Addition = " << answer2 << std::endl;
        assert(answer1 == answer2); // should be true
        std::cout << "computational conversions passed" << std::endl;
        points += 6;

    }

    std::cout << "Total points based on results: " << points << std::endl;
    std::cout << "end of myType testing" << std::endl;
    std::cin.get();

}


/*
// This code hereafter would normally go into a dot cpp file

std::ostream& operator<<(std::ostream& input, myType const& rhs)
{
    input << rhs.typeVar;
    return input;
}

*/

// PLACE CODE HERE
myType::myType()
{

    typeVar = nullptr; // default constructor
    typeLength = 0;
}

myType::myType(const char* myChar) // copier for setting a c-string to an object
{
    typeLength = strlen(myChar);
    typeVar = new char[typeLength + 1];
    strcpy(typeVar, myChar);
    typeVar[typeLength] = '\0';


}


//Pre: c-object must not be null and have valid size as size_t
//Post: will initialize object to the amount of characters in a literal


myType::myType(const char* myChar, std::size_t size)
{
    delete[] typeVar; // deleting typeVar so we can resize the c-string
    typeVar = nullptr;

    typeLength = size;
    typeVar = new char[size + 1];
    for (int i = 0; i < typeLength; ++i)
    {

        typeVar[i] = myChar[i];
    }

    typeVar[typeLength] = '\0';

}


// object functions

void myType::clear()
{
    delete[] typeVar;
    typeVar = nullptr;
    typeLength = 0;
}


bool myType::empty() const
{
    if (typeLength == 0)
    {
        return true;
    }
    std::cout << "False" << std::endl;
    return false;

}

short myType::size()
{
    return  typeLength;
}

char* myType::data()
{
    return typeVar;
}



myType::myType(const myType& myObj) // Constructor copier, for copying an object to another object
{

    delete[] typeVar;
    typeLength = strlen(myObj.typeVar);
    typeVar = new char[typeLength + 1];
    strcpy(typeVar, myObj.typeVar);
    typeVar[typeLength] = '\0';

}

void myType::copier(myType& myObj)
{
    delete[] typeVar;
    typeLength = strlen(myObj.typeVar);
    typeVar = new char[typeLength + 1];
    strcpy(typeVar, myObj.typeVar);
    typeVar[typeLength] = '\0';
}


myType& myType::operator=(const myType& rObj) // Copying an object from another object
{
    delete[] typeVar;
    typeLength = strlen(rObj.typeVar);
    typeVar = new char[typeLength + 1];
    strcpy(typeVar, rObj.typeVar);
    typeVar[typeLength] = '\0';
    return *this;
}

myType& myType::operator+=(const myType& obj) // obj += obj
{
    short tempLength1 = (strlen(typeVar));
    short tempLength2 = strlen(obj.typeVar);
    char* tempString = new char[tempLength1 + tempLength2 + 1];

    for (int i = 0; i < tempLength1; ++i)
    {
        tempString[i] = typeVar[i];
    }
    for (int j = tempLength1; j < tempLength2; ++j)
    {
        tempString[j] = typeVar[j];
    }
    delete[] typeVar;
    typeVar = new char[tempLength1 + tempLength2 + 1];
    strcpy(typeVar, tempString);
    return *this;
}

myType& myType::operator=(const char larry[])
{
    delete[] typeVar;   // deletes the current typeVar so we can allocate more/less space
    typeLength = strlen(larry); // new typeLength
    typeVar = new char[typeLength + 1]; // must be +1 for the null terminator
    strcpy(typeVar, larry);
    typeVar[typeLength] = '\0'; // need the null terminator
    return *this;
}


size_t myType::find(char cha) const
{
    size_t length = strlen(typeVar);
    for (auto i = 0; i < length; ++i)
    {
        if (typeVar[i] == cha) // if the current char is = to our character, then we have found the first char
        {
            return i;
        }
    }
    return npos;
}


char* myType::subpart(short first, short second) const
{
    int range = strlen(typeVar);
    assert(first >= 0 && second <= range); // asserting that index is in range

    char* tempVar = new char[second + 1]; // creates a smaller c-string
    for (auto i = first; i < (first + second); ++i)
    {
        tempVar[i - first] = typeVar[i];
    }
    tempVar[second] = '\0';
    return tempVar;
}

bool myType::operator==(const char* cha) // Comparing object == string literal
{
    int len = strlen(typeVar);
    for (auto i = 0; i < len; ++i)
    {
        if (typeVar[i] != cha[i])
        {
            return false; // returns false if any char is not equal
        }
    }
    return true;  // if the for loop has been exited without returning anything, then the 2 strings must be equal
}

bool myType::operator==(const myType& obj) const
{
    for (auto i = 0; i < typeLength; ++i)
    {
        if (typeVar[i] != obj.typeVar[i])
        {
            return false; // returns false if any char is not equal
        }
    }
    return true;
}

bool myType::operator!=(const myType& obj) const
{
    for (auto i = 0; i < typeLength; ++i)
    {
        if (typeVar[i] != obj.typeVar[i])
        {
            return true; // returns false if any char is not equal
        }
    }
    return false;
}



////////////

bool myType::operator<(const myType& right)
{
    if ((strcmp(typeVar, right.typeVar)) < 0) //
    {
        return true; // if typeVar is < than rightside object return true!
    }
    return false;
}
bool myType::operator>(const myType& right)
{
    if ((strcmp(typeVar, right.typeVar)) > 0) //
    {
        return true; // if typeVar is > than rightside object return true!
    }
    return false;
}
bool myType::operator<=(const myType& right)
{
    if ((strcmp(typeVar, right.typeVar)) <= 0) //
    {
        return true; // if typeVar is <= than rightside object return true!
    }
    return false;
}
bool myType::operator>=(const myType& right)
{
    if ((strcmp(typeVar, right.typeVar)) >= 0) //
    {
        return true; // if typeVar is >= than rightside object return true!
    }
    return false;
}

myType::operator short int()
{
    short max = typeLength - 2; // the typeLength has to be less than 2, if IT's less than 2 then my function down below could go out of index and break
    short leftNum; // will hold the left number as a short integer form
    short rightNum; // will hold the right number as a short integer form
    char* ptr; // i need a pointer to make strtol to work
    char* rightSide; // this holds the c-string for the right side numbers
    for (auto i = 0; i < max; ++i)
    {
        if ((typeVar[i] == 'a') && (typeVar[i + 1] == 'd') && (typeVar[i + 2] == 'd'))// IF "ADD" in a row is found
        {                                                                              // this is run
            leftNum = strtol(typeVar, &ptr, 10 );
            int x = i;            rightSide = new char[3];
            /// to access the right side digit we will have to make a new c-string
            for (auto j = 0; j < 3; ++j)
            {
                rightSide[j] = typeVar[i + j + 3]; //we need to make a new c-string because strtol collects integers
            }                                       // till it sees a space, so this is my way of using substr kind of
            rightNum = strtol(rightSide, &ptr, 10); // converts c-string to integer


            return (leftNum + rightNum);

        }

        if ((typeVar[i] == 's') && (typeVar[i + 1] == 'u') && (typeVar[i + 2] == 'b')) // IF "SUB" in a row is found
        {                                                                               // this is ran

            leftNum = strtol(typeVar, &ptr, 10);
            int x = i;            rightSide = new char[3];
            /// to access the right side digit we will have to make a new c-string
            for (auto j = 0; j < 3; ++j)
            {
                rightSide[j] = typeVar[i + j + 3];
            }
            rightNum = strtol(rightSide, &ptr, 10); // converts the c-string to an integer

            return (leftNum - rightNum);

        }

    }


}
