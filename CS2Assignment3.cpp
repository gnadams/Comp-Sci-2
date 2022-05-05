//
//   COPYRIGHT (C) gna5@uakron.edu, 2022  All rights reserved.
//   Gregory Adams
//   Purpose: This is myCode and is based upon what we study for Comp Sci
//
#include <cassert>
#include <iosfwd>
#include <iostream>
#include <iomanip>
#include <limits>  // numeric_limits<std::streamsize> for validations
#include <map>
#include <vector>
#include <string>

// these are declarations - prefer this or std:: prefix
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::right;
using std::string;
using std::vector;

static int uChoose = 0;

// TASK A class definition
class CheckedPtr
{
public:
    // no default constructor; CheckedPtrs must be bound to an object
    CheckedPtr(int* b, int* e) : beg(b), end(e), curr(b) { }
    // dereference and increment operations
    CheckedPtr operator++();       // postfix operators
    CheckedPtr operator--();
    int &operator[](int);
    int operator*();

private:
    int* beg;   // pointer to beginning of the array
    int* end;   // one past the end of the array
    int* curr;  // current position within the array
};
// postfix: increment/decrement object but return unchanged value
CheckedPtr CheckedPtr::operator++()
{
    // no check needed here, the call to prefix increment will do the check
    if (curr == end - 1)
    {
        curr = beg;
    }
    else
    {
        ++curr;
    }

}
CheckedPtr CheckedPtr::operator--()
{
    if (curr == beg)
    {
        curr = end;
    }
    else
    {
        --curr;
    }

}

int &CheckedPtr::operator[](int index)
{
    if (beg + index > end) // if out of range, the last digit is returned
    {
        curr = end;
    }
    else
    {
        curr = beg + index;
    }
    return *curr; // returns the int value
}

int CheckedPtr::operator*()
{
    return *curr; //returns the value of the current position
}

// prototypes

// task B prototype
void reverse(std::string&);
// TASK C
template <typename T>
// printVector function
void printVector(const vector<T>&);
// palindrome function
template <typename T>
bool palindrome(const vector<T>&);


// todos
// TASK B function to print the reverse string
// TASK C function template printVector definition
// TASK C function template palindrome definition
// TASK D functions for map of Apps

/*
Class Apps:
data members — game name(string), game type (string) and cost of game (float).
Data members initialization rules: the default for the name is "No Name", the
default for the type is "Unknown", and the price is 15. All names pass by reference.
*/
class Apps
{

private:
    std::string name;
    std::string type;
    float cost;

public:
    // ********************************************************************
    // Constructor prototypes (code for constructors goes below, in task D)
    // ********************************************************************
    Apps()
    {
    }
    Apps(float price, string stype)
    {
        type = stype;
        cost = price;
    }
    Apps(string sname, string stype)
    {
        name = sname;
        type = stype;
    }
    Apps(string sname)
    {
        name = sname;
    }
    Apps(string sname, string stype, float price)
    {
        name = sname;
        type = stype;
        cost = price;
    }


    //Precondition: Takes nothing
    //Post-Condition: Returns the name as a string
    string getName() const
    {
        return name;
    }
    //Precondition: Takes a string as an input
    //Post-Condition: Returns nothing, but changes name value in class
    void setName(string newName)
    {
        name = newName;
    }
    //Precondition: Takes nothing
    //Post-Condition: Returns the type as a string
    string getType() const
    {
        return type;
    }
    //Precondition: Takes a string as an input
    //Post-Condition: Returns nothing, but changes type value in class
    void setType(string newType)
    {
        type = newType;
    }
    //Precondition: Takes nothing
    //Post-Condition: Returns the cost as a float
    float getCost() const
    {
        return cost;
    }
    //Precondition: Takes a float as an input
    //Post-Condition: Returns nothing, but changes cost value in class.
    void setCost(float newCost)
    {
        cost = newCost;
    }

};

int
mainMenu();

void
taskA();

void
taskB();

void
taskC();

void
taskD();


struct Test_myCode
{
    void
        default_beg()
    {
        uChoose = mainMenu();
        assert(!(std::cin.fail()));
        std::cout << " Main menu passed " << std::endl;
    }
    void
        whatAction()
    {
        switch (uChoose)
        {
        case (1):
            taskA();
            break;
        case (2):
            taskB();
            break;
        case (3):
            taskC();
            break;
        case (4):
            taskD();
            break;
        case (5):
            //taskE();
            break;
        case (6):
            //taskF();
            break;
        case (7):
            //taskG();
            break;
        case (8):
            //taskH();
            break;
        default:
            cout << "no case";
        }
    }

    // The test runner for this test class.
    void
        run()
    {
        default_beg();
        whatAction();
    }

};


int
main()
{
    Test_myCode test;
    while (true)
    {
        test.run();
    }

}



int
mainMenu()
{
    // heading, input section
    cout << endl;
    cout << setw(68) << "__________________________________________________________________ " << endl;
    cout << setw(68) << "|------------------------------------------------------------------|" << endl;
    cout << setw(68) << "|               Greg Adams - My Programming World                  |" << endl;
    cout << setw(68) << "|                  Excellently coded solutions                     |" << endl;
    cout << setw(68) << "|__________________________________________________________________|" << endl;
    cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "   MAIN MENU"
        << right << setw(2) << "|" << endl;
    cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "1) Task A"
        << right << setw(2) << "|" << endl;
    cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "2) Task B"
        << right << setw(2) << "|" << endl;
    cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "3) Task C"
        << right << setw(2) << "|" << endl;
    cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "4) Task D"
        << right << setw(2) << "|" << endl;
    cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "5) Open"
        << right << setw(2) << "|" << endl;
    cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "6) Open"
        << right << setw(2) << "|" << endl;
    cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "7) Open"
        << right << setw(2) << "|" << endl;
    cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "8) Open"
        << right << setw(2) << "|" << endl;
    cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "Ctrl-c to Quit"
        << right << setw(2) << "|" << endl;
    cout << setw(68) << "|__________________________________________________________________|" << endl;
    cout << endl;
    int userChoice = 0;
    // take and validate the user entry

    cout << "Enter the code that you wish to generate, or quit to exit: "; // output stream a message
    cin >> userChoice;
    return userChoice;
}

// PLACE CODE HERE FOR EACH TASK
// TASK A CODE
const size_t SIZE = 10;
void
taskA()
{

    int* iaPtr = new int[SIZE];                // allocates an array of ints
    for (int i = 0; i < SIZE; ++i)
    {
        iaPtr[i] = i + i;                        // put some values in the array
    }
    std::cout << "Here is what the array we are copying from has - we will overlay this!" << std::endl;
    for (int i = 0; i < SIZE; ++i)
    {
        cout << iaPtr[i] << " ... ";
    }
    std::cout << std::endl;
    CheckedPtr intCParray(iaPtr, iaPtr + SIZE);  // intCParray  points to an array of ints


    // putting in random values into the array
    for (auto i = 0; i < SIZE; ++i)
    {
       intCParray[i] = rand() % 9;
    }
    intCParray[0];
    cout << "iterating through and using dereference overload " << std::endl;
    for (auto i = 0; i < SIZE; ++i)
    {
        cout << *intCParray << ' ';
        ++intCParray;
    }
    cout << std::endl;
    cout << "iterating through using [] overload : \n";
    for (auto i = 0; i < SIZE; ++i)
    {

        cout << intCParray[i] << ' ';
    }

    cout << "end of task A" << endl;
    cin.get();
}

// PLACE CODE HERE FOR EACH TASK
// TASK B CODE
void reverse(std::string& myString) // takes in a string
{                                   // no return type
    std::string::reverse_iterator it = myString.rbegin(); // create reverse iterator
    std::string newString = myString;   // create a string that is the exact same size as the incoming one
    int i = 0;  // i = 0 for the loop
    while (it != myString.rend())
    {
        newString[i] = *it; // set the new string = to to the reversed string iterator
        ++it;
        ++i;
    }
    myString = newString; // we are essentially "returning" the string here by doing this

}


void
taskB()
{
    std::string string1 = "most of the day I ate captain crunch";
    std::string string2 = "later my teeth hurt, like, a lot!";
    std::string string3 = "i feel better now cause of my new bean bag recliner";
    // code calls here
    reverse(string1);
    reverse(string2);
    reverse(string3);
    std::cout << string1 << '\n';
    std::cout << string2 << '\n';
    std::cout << string3 << '\n';
    cout << "end of task B" << endl;
    cin.get();
}

// PLACE CODE HERE FOR EACH TASK
// TASK C CODE
template <typename T>
void printVector(const vector<T>& myVar) // PRE: any vector
{                                        // No return type
    auto it = myVar.begin(); // create iterator
    while (it != myVar.end())
    {
        std::cout << *it; // outputs the entire phrase
        ++it;
    }
    std::cout << '\n';

}

template <class T>
bool palindrome(const vector<T>& myVar) // pre: vector of anytype
{                                       // post: returns bool

    auto it = myVar.begin();
    auto ti = myVar.rbegin(); // automatically makes a reverse iterator

    while (it != myVar.end())
    {
        if (*it != *ti) // IF the current digit is not equal to the opposite digit reversed,
        {
            return false; // Then it is NOT a palindrome and false can be returned.
        }
        ++it;
        ++ti;
    }
    return true;

}


void
taskC()
{
    vector<int> intVec;
    vector<char> charVec;
    int tempVar = 0;

    for (int i = 75; i >= 65; --i)
    {

        intVec.push_back(i);
        charVec.push_back(static_cast<char>(i + tempVar));

        if (i <= 70)
        {
            tempVar += 2;
        }
    }



    printVector(intVec);
    cout << (palindrome(intVec) ? " is " : " is not ") << "a palindrome\n";

    printVector(charVec);
    cout << (palindrome(charVec) ? " is " : " is not ") << "a palindrome\n";

    cout << "end of task C" << endl;
    cin.get();
}

// PLACE CODE HERE FOR EACH TASK
// TASK D CODE
void
taskD()
{
    std::string AppName[] = { "Puzzled Penny", "Reality", "Adventure Aardvark" }; //List of App Names
    std::string AppType[] = { "Puzzle", "Simulation", "Adventure" }; //List of App Types
    float AppPrice[] = { 0, 50, 75 }; //List of App Prices.
    std::string myString = "placekitten"; // place kitten is an app name
    // refer to the instructions for the following
    Apps AppObj;
    Apps AppObj1(AppPrice[2], AppType[2]);
    Apps AppObj2("MS Excel");
    Apps AppObj3("Twitter", "Social Media");
    Apps AppObj4(myString, "Social Media", 55);
    Apps AppObjTest("gmail", "Social Media", 55);
    //Apps AppObj5(AppName[0], AppPrice[0], AppType[0]);
    //Apps AppObj6("MS Excel", AppPrice[2], AppType[2]);
    //Apps AppObj7(100, "Ubiquity"); // this is a name
    //Apps AppObj8(myString, 55);
    //Apps AppObj9(AppName[1], AppPrice[1]);
    //Apps AppObjA("Intrigue"); // this is a type
    Apps AppObjB(myString, "Social Media");
    //Apps AppObjC(150);
    //Apps AppObjD(AppName[1], AppPrice[1]);
    //Apps AppObjE(200, "Intrigue"); // this is a type
    //Apps AppObjF("Ubiquity"); // this is a name
    //Apps AppObjG("Zoom", "Audio video", 55);

    // Now, create a map with the key value as the app name.
    // write the find and delete methods and print too!

    std::map<string, Apps> appMap;

    appMap.insert(std::pair<string, Apps>(AppObj2.getName(), AppObj2));
    appMap.insert(std::pair<string, Apps>(AppObj4.getName(), AppObj4));
    appMap.insert(std::pair<string, Apps>(AppObj3.getName(), AppObj3));
    appMap.insert(std::pair<string, Apps>(AppObjB.getName(), AppObjB));

    std::map<string, Apps>::iterator it;

    std::cout << "Trying to find socks: \n";
    it = appMap.find("socks");
    if (it == appMap.end())
    {
        cout << "not found \n";
    }
    else
    {
        cout << "found \n";
    }


    cout << "trying to find placekitten : \n";
    it = appMap.find("placekitten");
    if (it == appMap.end())
    {

        cout << "not found \n";
    }
    else
    {

        cout << "found \n";
    }

    cout << '\n' <<  "now deleting placekitten using erase() \n " << '\n';
    appMap.erase("placekitten");

    cout << "trying to find placekitten after deletion : \n";
    it = appMap.find("placekitten");
    if (it == appMap.end())
    {

        cout << "not found \n";
    }
    else
    {

        cout << "found \n";
    }


    cout << "end of task D" << endl;
    cin.get();
}



