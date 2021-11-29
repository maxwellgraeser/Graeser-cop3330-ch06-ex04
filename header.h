/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Maxwell Graeser
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Name_value {
    
public:
    string name;
    int val;

    Name_value(string nameIn, int value) {
        name = nameIn;
        val = value;
    }
};

// given the vector array and the new inputs it returns false if there are no
// repeated names, or true if there are.
bool checkRepeated(vector<Name_value> arr, string n, int v) {
    if (arr.size() == 0) return false;
    bool flag = false;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].name == n) flag = true;
    }
    return flag;
}

// returns true if the terminate criteria is met
bool checkTerminate(string n, int v) {
    if (n == "NoName" && v == 0) {
        return true;
    }
    else return false;
}

// outputs the vector list
void printOutput(vector<Name_value> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << "(" << arr[i].name << ", " << arr[i].val << ")\n";
    }
}