/*This code does the following:

Generates a random number between 1 and 100.
Asks the user to guess the number.
Provides feedback if the guess is too high or too low.
Continues until the user guesses the correct number.
I used numeric_limits<streamsize>::max() to clear the input buffer in case of invalid input to prevent the program from going into an infinite loop. 
if the user enters invalid input.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int main() {
    srand(time(NULL)); // the random number generator with current time
    int secretNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess;


    string name;
    cout<<"ENTER YOUR NAME :-  ";
    cin>>name;
    cout << "WELCOME  TO THE NUMBER GUESSING GAME !! (MADE BY PRANSHU )" << endl;
    cout << "I have picked a number between 1 and 100. Can you guess it?" << endl;
    
    do {
        cout << "ENTER YOUR GUESS : ";
        cin >> guess;
        
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
            cout << "INVALID INPUT. PLEASE ENTER A VALID NUMBER. " << endl;
            continue; // Skip the rest of the loop iteration
        }
        
        if (guess < secretNumber) {
            cout << "TOO LOW !! TRY AGAIN. " << endl;
        } else if (guess > secretNumber) {
            cout << "TOO HIGH !! TRY AGAIN. " << endl;
        } else {
            cout << "CONGRATULATIONS !! "  + name +  "  YOU GUESSED IT RIGHT." << endl;
        }
    } while (guess != secretNumber);
    
    return 0;
}








