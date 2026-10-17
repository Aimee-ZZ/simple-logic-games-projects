#include <iostream>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()

using namespace std;

int main() {
    // 1. Seed the random number generator so the number changes every game
    srand(time(0));
    
    // 2. Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    
    int userGuess = 0;
    int attempts = 0;

     // --- COLOR CODES DEFINITION ---
    // \033[ is the escape sequence, followed by the color code number, and 'm'
    string RESET = "\033[0m";   // Resets terminal to default color
    string RED   = "\033[31m";  // Red text
    string BLUE  = "\033[34m";  // Blue text
    string GREEN = "\033[32m";  // Green text for winning!

    cout << "=== WELCOME TO THE GUESS THE NUMBER ===\n";
    cout << "I have picked a number between 1 and 100. What do you think it is?\n\n";

    // 3. The Game Loop
    // This loop will keep running as long as the user hasn't guessed the secret number
    while (userGuess != secretNumber) {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++; // Increment the number of tries

        // 4. Check the logic
        if (userGuess > secretNumber) {
            cout << RED << "TOO HIGH!! Try again." << RESET << "\n\n";
        } 
        else if (userGuess < secretNumber) {
            cout << BLUE << "TOO LOW!! Try again." << RESET << "\n\n";
        } 
        else {
            cout << GREEN << "\n CONGRATULATIONS! You guessed the secret number " << secretNumber << "!" << RESET << "\n";
            cout << "It took you " << attempts << " attempts.\n";
        }
    }
    // Force the program to wait for the user to press Enter before closing
        cout << "\nPress Enter to exit the game...";
        cin.ignore(); // Clears any leftover input characters
        cin.get();    // Pauses the program and waits for an Enter key press

    return 0;
}