//Name:     Chloe Taylor
//Date:     2/21/2021
//Language: C++
//Purpose:  To make a program that can state if a phone number is a US phone number

#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool phone(queue <char> & temp);
bool lparen(char const & temp);//
bool rparen(char const & temp);//
bool dash(char const & temp);//
bool sigDigit(char const & temp);//
bool digit(char const & temp);//
bool areaExch(queue <char> & temp);
bool lineNum(queue <char> &  temp);

int main() {
    // variable declaration
    queue <char> numQueue;
    char choice = 'y';
    string num;
    int n;


    // Instructions
    cout << "Please enter a valid US phone number\n";
    cout << "Proper format is (XOO)XOO-OOOO\n";
    cout << "Where X cannot be the number zero and ";
    cout << "O can be any number 0-9\n";
    cout << "There can be no spaces\n";

    while (choice == 'y' || choice == 'Y') {
        cin >> num;
        cout << num << "\t";

        // If the number is too short or too long, it is automatically rejected
        n = num.length();
        if (n < 13) {
            cout << "NO! This is not a valid us phone number!\n";
            cout << "It is too short! ";
            cout << "Would you like to try again?\n";
            cout << "Press Y for yes and any other letter for no\n";
            cin >> choice;
        } else if (n >= 14) {
            cout << "NO! This is not a valid us phone number!\n";
            cout << "It is too long! ";
            cout << "Would you like to try again?\n";
            cout << "Press Y for yes and any other letter for no\n";
            cin >> choice;
        } else {
            // copies what's in num into mumQueue
            for (int i = 0; i < n; i++) {
                numQueue.push(num[i]);
            }
            if (phone(numQueue)) {
                cout << "Yes, this is a valid US  phone number\n";
                cout << "Would you like to try another number?\n";
                cout << "Press Y for yes and any other letter for no\n";
                cin >> choice;
            } else {
                cout << "Would you like to try again?\n";
                cout << "Press Y for yes and any other letter for no\n";
                cin >> choice;
            }
        }
        if (choice == 'y' || choice == 'Y')
            cout << "Please enter a valid US phone number\n";
    }
    return 0;
}

bool phone(queue <char> & temp){

    // If the first char is not a (, the program returns false
    if (!lparen(temp.front())){
        return false;
    }
    temp.pop();

    // If the area code is not correct, return false
    if (!areaExch(temp)){
        return false;
    }

    // If the next char is not a ), the program returns false
    if (!rparen(temp.front())){
        return false;
    }
    temp.pop();

    // If the exchange code is not correct, return false
    if (!areaExch(temp)){
        return false;
    }

    // If there is no dash after exchange code, return false
    if(!dash(temp.front())){
        return false;
    }
    temp.pop();

    // If the last four numbers are not digits, returns false
    if(!lineNum(temp)){
        return false;
    }

    // Returns true if the number is valid
    return true;
}

// checks to see if the string contains a (
bool lparen(char const & temp){
    if (temp == '(') {
        return true;
    }
    else {
        cout << "No, not a valid us phone number\n";
        cout << "Your first character is not a (\n";
        return false;
    }
}

// checks to see if the string contains a )
bool rparen(char const &  temp){
    if (temp == ')') {
        return true;
    }
    else{
        cout << "rparen is " << temp << endl;
        cout << "No, not a valid us phone number\n";
        cout << "This character is not a )\n";
        return false;
    }
}

// checks to see if the string contains a -
bool dash(char const & temp){
    if (temp == '-') {
        return true;
    }
    else {
        cout << "No, not a valid us phone number\n";
        cout << "This character is not a -\n";
        return false;
    }
}

// checks to see if the string is zero
bool sigDigit(char const & temp){
    if (temp == '0') {
        cout << "No, this is not a valid US phone number\n";
        cout << "There can not be a Zero in the first part of the area code or exchange code\n";
        return false;
        }
    else {
        return true;
    }

}

// returns true if the char is a digit
bool digit(char const & temp){
    switch(temp) {
        case '0':
            return true;
        case '1':
            return true;
        case '2':
            return true;
        case '3':
            return true;
        case '4':
            return true;
        case '5':
            return true;
        case '6':
            return true;
        case '7':
            return true;
        case '8':
            return true;
        case '9':
            return true;
        default:
            cout << "No, this is not a valid US phone number\n";
            cout << "This digit is not a number\n";
            return false;
    }
}

// checks to see if the area code or exchange code is correct
bool areaExch(queue <char> & temp){
    // If the next digit of area code is zero, return false
    if (!sigDigit(temp.front()))
        return false;
    temp.pop();

    // If the next digit is not a number, returns false
    if (!digit(temp.front()))
        return false;
    temp.pop();

    // If the next digit is not a number, returns false
    if (!digit(temp.front()))
        return false;
    temp.pop();

    return true;
}

// checks to make sure the last four digits are numbers
bool lineNum(queue <char> & temp){
    // If the next digit is not a number, returns false
    if (!digit(temp.front()))
        return false;
    temp.pop();

    // If the next digit is not a number, returns false
    if (!digit(temp.front()))
        return false;
    temp.pop();

    // If the next digit is not a number, returns false
    if (!digit(temp.front()))
        return false;
    temp.pop();

    // If the next digit is not a number, returns false
    if (!digit(temp.front()))
        return false;
    temp.pop();

    return true;
}