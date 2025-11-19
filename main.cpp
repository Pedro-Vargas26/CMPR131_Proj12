#include <iostream>
#include <fstream>
#include "input.h"
using namespace std;


void option3();
void mvStr(char*,const int, string&);
bool searchContainer(const vector<int>&, int);

int main() {
    option3();
}


bool searchContainer(const vector<int>& haystack,int needle) {
    for (auto a : haystack)if (a == needle)return true;
    return false;
}

vector<int> translateFile(const string& fileName) {
    if (fileName.empty())throw std::runtime_error("ERROR: INVALID FILENAME");

    fstream fileReader;
    vector <int> info;

    fileReader.open(fileName, ios::in);

    if (fileReader.is_open()) {
        NULL;
    }
    else throw std::runtime_error("ERROR: FILE FAILED TO OPEN. ");
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

    vector <int> haystack;

    string tempStr = " ";
    string fileName = "student.dat";
    bool running = true;
    bool errorMarked = false;

    constexpr int BUFFER_SIZE = 150;
    int needle = 0;
    int n = 0;
    int tempInt = 0;


    double tempDouble = 0.0;

    char studentName[BUFFER_SIZE] = {};
    char studentMajor[BUFFER_SIZE] = {};



    do{
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
    choice = inputChar("\t\tOption :");
    switch (choice) {
    case 'A':
        n = inputInteger("\t\tEnter a number of read-in records: ", true);
        try {
            haystack = translateFile(fileName);
            cout << "\t\t" << n << "records have been inserted. \n\n";
        }
        catch (...) {
            cerr << "\t\t" << "ERROR: FILE OPERATION FAILED. \n\n";
        }

        break;
    case 'B':
        needle = inputInteger("\t\tEnter a student ID to search:", true);
        if (searchContainer(haystack, needle)) {
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

        //erase logic here
        //success: student record index#n with ID: idnum has been removed. 
        //failed:  ERROR: ID cannot be found.

        break;
    case 'E':
        if (haystack.empty())cout << "\n\n\t\t" << "ERROR: no record found.\n\n\t";
        else
            for (int i = 0; i < haystack.size();i++) 
                cout << "[" << i << "]: -" << haystack[i] << "\n";
        break;
    default:
        running = false;
    }
    system("pause");
}while (running);
}
