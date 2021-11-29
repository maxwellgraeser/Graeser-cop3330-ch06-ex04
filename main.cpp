/*
Define a class Name_value that holds a string and a value.
Rework exercise 19 in Chapter 4 to use a vector<Name_value> instead of two vectors

exercise 19:
Write a program where you first enter a set of name-and-value pairs, such
as Joe 17 and Barbara 22. For each pair, add the name to a vector called
names and the number to a vector called scores (in corresponding positions, so that if names[7]=="Joe" then scores[7]==17). Terminate input
with NoName 0. Check that each name is unique and terminate with an
error message if a name is entered twice. Write out all the (name,score)
pairs, one per line.
*/

#include "header.h"

// Note: inputs must be either entered in one line then hit the enter key, or: pair, enter key, repeat
// if the latter, an extra enter will result in an error
int main() {
    vector<Name_value> list;
    string nameIn;
    int value;
    cout << "\nEnter name-and-value pairs (with unique names), for example 'Joe 17'\nTo exit the program type 'NoName 0'\n\n";
    getline(cin, nameIn, ' ');
    cin >> value;

    while (1) {
        // check for repeated name
        if (checkRepeated(list, nameIn, value)) {
            cout << "Error, you entered the same name twice.\n";
            break;
        }

        // check for terminate
        if (checkTerminate(nameIn, value)) {
            break;
        }

        // Input name
        Name_value *temp = new Name_value(nameIn, value);
        list.push_back(*temp);

        // read inputs
        cin.ignore();
        getline(cin, nameIn, ' ');
        cin >> value;
    }

    printOutput(list);

    return 0;
}