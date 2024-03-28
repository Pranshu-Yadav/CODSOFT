// C++ program that implements a calculator allowing users to perform basic arithmetic operations such as 
//addition, subtraction, multiplication, division and Modulus.
// The program utilizes INT_MAX and INT_MIN constants for handling boundary cases.
//Here we use built-in function 'abs' during subtraction part which will return absolute value after subtraction.
//This program handles potential overflow and division by zero errors using INT_MAX and INT_MIN constants. 
//It checks for overflow conditions before performing arithmetic operations.


#include <iostream>
#include<bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
    int number1, number2;
    char Operator;

    cout << "ENTER FIRST NUMBER :- ";
    cin >> number1;

    cout << "ENTER SECOND NUMBER :- ";
    cin >> number2;

    cout << "CHOOSE OPERATION (+ , - , * ,  / ,  %): ";
    cin >> Operator;

    switch(Operator) {
        case '+':
            if ((number2 > 0 && number1 > INT_MAX - number2) || (number2 < 0 && number1 < INT_MIN - number2)) {
                cout << " ERROR : Addition overflow! " << endl;
            } else {
                cout << "RESULT : " << number1 + number2 << endl;
            }
            break;
        case '-':
            if ((number2 > 0 && number1 < INT_MIN + number2) || (number2 < 0 && number1 > INT_MAX + number2)) {
                cout << "ERROR : Subtraction overflow !" << endl;
            } else {
                cout << "RESULT : " << abs(number1 - number2) << endl;
            }
            break;
        case '*':
            if (number1 > INT_MAX / number2 || number1 < INT_MIN / number2) {
                cout << "ERROR : Multiplication overflow !" << endl;
            } else {
                cout << "RESULT : " << number1 * number2 << endl;
            }
            break;
        case '/':
            if (number2 == 0) {
                cout << "ERROR : Division by zero !" << endl;
            } else if (number1 == INT_MIN && number2 == -1) {
                cout << "ERROR : Division overflow !" << endl;
            } else {
                cout << "RESULT : " << number1 / number2 << endl;
            }
            break;
            case '%':
            if (number2 == 0) {
                cout << "ERROR : Modulus by zero !" << endl;
            } else if (number1 == INT_MIN && number2 == -1) {
                cout << "ERROR : Modulus overflow !" << endl;
            } else {
                cout << "Result: " << number1 % number2 << endl;
            }
            break;
        default:
            cout << "INVALID OPERATION !!!" << endl;
    }

    return 0;
}