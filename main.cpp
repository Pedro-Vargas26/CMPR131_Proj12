#include <iostream>
#include <fstream>
#include <sstream>
#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include "Student.h"
#include "HashTable.h"
#include "input.h"
using namespace std;


void option1();
void option2();
void option3();
void mvStr(char*, const int, string&);
HashTable<Student> translateFile(const string&, int&);


char mainMenu();

int main() {
    bool running = true;

    while (running) {
        system("cls");
        switch (mainMenu()) {
        case '1':
            option1();
            break;
        case '2':
            option2();
            break;
        case '3':
            option3();
            break;
        case '0':
            running = false;   // Exit cleanly
            break;
        }
    }
}


void option1() {
    //char choice = 'A';
    //bool running = true;
    do {
        system("cls");

        cout << "\t1 > Searching unsorted dynamic arrays\n";
        cout << "\t" << string(85, (char)196) << "\n";
        cout << "\t\t" << "1 > Read data file and store into the array\n";
        cout << "\t\t" << "2 > Add an element to the dynamic array\n";
        cout << "\t\t" << "3 > Display elements from the array\n";
        cout << "\t\t" << "4 > Search for an element from the array\n";
        cout << "\t\t" << "5 > Clear the array\n";
        cout << "\t" << string(85, (char)196) << "\n";
        cout << "\t\t" << "0 > return\n";
        cout << "\t" << string(85, (char)205) << "\n";

            //choice = inputChar("\tERROR INVALID CHOICE. TRY AGAIN:");
        
        switch (inputInteger("\tOption: ", 0, 5))
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 0: return;
        default:
        {
            cout << "\n\tERROR: invalid input...";
        }break;
        }
        system("pause");
    } while (true);
}
void option2() {
    char choice = 'A';
    bool running = true;
    do {
        system("cls");


        cout << "\t1 > Searching sorted dynamic arrays\n";
        cout << "\t" << string(85, (char)205) << "\n";
        cout << "\t\t" << "1 > Read data file and store into the array\n";
        cout << "\t\t" << "2 > Add an element to the dynamic array\n";
        cout << "\t\t" << "3 > Display elements from the array\n";
        cout << "\t\t" << "4 > Search for an element from the array\n";
        cout << "\t\t" << "5 > Clear the array\n";
        cout << "\t" << string(85, (char)196) << "\n";
        cout << "\t\t" << "0 > return\n";
        cout << "\t" << string(85, (char)205) << "\n";
        choice = inputChar("\t\tChoice:");
        if (choice < '0' || choice > '5') {
            while ((choice < '0') || (choice > '5')) {
                choice = inputChar("\tERROR INVALID CHOICE. TRY AGAIN:");
            }
        }
        switch (choice) {
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '0':
            running = false;
            break;
        }
        system("pause");
    } while (running);
}
char mainMenu() {
    char choice = 'A';
    cout << "\t" << "CMPR131 Chapter 12: Searches and hashing by Pedro Vargas (11/23/2025)\n";
    cout << "\t" << string(85, (char)205) << "\n";
    cout << "\t\t" << "1 > Searching from an unsorted dynamic array\n";
    cout << "\t\t" << "2 > Searching from a sorted dynamic array\n";
    cout << "\t\t" << "3 > Application using hashing\n";
    cout << "\t" << string(85, (char)196) << "\n";
    cout << "\t\t" << "0 > Exit\n";
    cout << "\t" << string(85, (char)205) << "\n";
    choice = inputChar("\tOption :");
    if (choice < '0' || choice > '3') {
        while ((choice < '0') || (choice > '3')) {
            choice = inputChar("\tERROR INVALID CHOICE. TRY AGAIN:");
        }
    }
    return choice;
}


HashTable<Student> translateFile(const string& fileName, int& n) {
    if (fileName.empty())
        throw std::runtime_error("ERROR: INVALID FILENAME");

    fstream fileReader(fileName, ios::in);
    if (!fileReader.is_open())
        throw std::runtime_error("ERROR: FILE FAILED TO OPEN.");

    HashTable<Student> info;
    string fromFile = "";
    int i = 0;


    while (i < n && std::getline(fileReader, fromFile))
    {
        stringstream ss(fromFile);

        string fileID, fileName, fileMajor, fileGPA;

        if (!getline(ss, fileID, ',')) continue;
        if (!getline(ss, fileName, ',')) continue;
        if (!getline(ss, fileMajor, ',')) continue;
        if (!getline(ss, fileGPA, ',')) continue;

        Student s(fileName, fileMajor, stoi(fileID), stof(fileGPA));
        info.insert(s);
        i++;
    }

    n = i;
    return info;
}


void mvStr(char* dest, const int buffSize, string& src) {
    if (src.length() >= buffSize)src = src.substr(0, buffSize - 1);
    if (src.empty())throw std::runtime_error("ERROR: STRING WAS EMPTY. ");

    size_t copyLen = src.length();

    memcpy_s(dest, buffSize, src.c_str(), src.length());
    src.clear();
    dest[copyLen] = '\0';
}

void option3() {
    char choice = 'A';

    HashTable <Student> haystack;

    string tempStr = " ";
    string fileName = "student.dat";
    bool running = true;
    bool errorMarked = false;

    constexpr int BUFFER_SIZE = 150;
    int needle = 0;
    int n = 0;
    int tempInt = 0;
    int idx = 0;

    double tempDouble = 0.0;

    char studentName[BUFFER_SIZE] = {};
    char studentMajor[BUFFER_SIZE] = {};



    do {
        system("cls");
        cout << "\t" << "3 > Application using hashing\n";
        cout << "\t" << string(80, (char)205) << "\n";
        cout << "\t\t" << "A > Read data file, hash and insert into the dynamic array\n";
        cout << "\t\t" << "B > Search an element from the dynamic array\n";
        cout << "\t\t" << "C > Insert an element into the dynamic array\n";
        cout << "\t\t" << "D > Remove an element from the dynamic array\n";
        cout << "\t\t" << "E > Display all records from the array\n";
        cout << "\t" << string(80, (char)196) << "\n";
        cout << "\t\t" << "0  > return\n";
        cout << "\t" << string(80, (char)205) << "\n";
        choice = toupper(inputChar("\t\tOption :"));
        switch (choice) {
        case 'A':
            n = inputInteger("\t\tEnter a number of read-in records: ", true);
            try {
                haystack = translateFile(fileName, n);
                cout << "\t\t" << n << " records have been inserted. \n\n";
            }
            catch (...) {
                cerr << "\t\t" << "ERROR: FILE OPERATION FAILED. \n\n";
            }

            break;
        case 'B':
            needle = inputInteger("\t\tEnter a student ID to search:", true);
            if (haystack.search(needle)) {
                cout << "found. ";
            }
            else {
                cout << "\t\t" << "ERROR: ID not found. \n\n";
            }
            break;
        case 'C':
            tempInt = inputInteger("\t\tEnter a new student ID:   ", true);
            do {
                try {
                    tempStr = inputString("\t\tEnter the student's name:  ", true);
                    mvStr(studentName, BUFFER_SIZE, tempStr);
                    errorMarked = false;
                }
                catch (const std::runtime_error& e) {
                    cerr << "\t\t" << e.what() << "\n";
                }
            } while (errorMarked);
            errorMarked = true;
            do {
                try {
                    tempStr = inputString("\t\tEnter the student's major: ", true);
                    mvStr(studentMajor, BUFFER_SIZE, tempStr);
                    errorMarked = false;
                }
                catch (const std::runtime_error& e) {
                    cerr << "\t\t" << e.what() << "\n";
                }
            } while (errorMarked);

            tempDouble = inputDouble("\t\tEnter a student's GPA(1.0...4.0):", 1.0, 4.0);

            cout << "\t\t" << "Inserted the new record. \n\n";
            break;
        case 'D':
            needle = inputInteger("\t\tEnter a student ID to remove: ", true);

            idx = haystack.remove(needle);
            cout << "\t\t";
            if (idx != -1) {
                cout << "Student record index #" << idx << " with ID: " << needle << " has been removed.";
            }
            else {
                cout << "ERROR: ID CANNOT BE FOUND.";
            }
            cout << "\n\n";
            //erase logic here
            //success: student record index#n with ID: idnum has been removed. 
            //failed:  ERROR: ID cannot be found.

            break;
        case 'E':
            if (haystack.empty())cout << "\n\n\t\t" << "ERROR: no record found.\n\n\t";
            else
                for (int i = 0; i < haystack.size(); i++)
                    cout << "[" << i << "]: -> " << haystack[i] << "\n";
            break;
        default:
            running = false;
        }
        system("pause");
    } while (running);
}
