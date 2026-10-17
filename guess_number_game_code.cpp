#include <iostream>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()
#include <windows.h> // Needed for system("chcp 65001 > nul") to set UTF-8 encoding

using namespace std;

int main() {
    system("chcp 65001 > nul");  
    // 1. Seed the random number generator so the number changes every game
    srand(time(0));
    
    // 2. Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    
    int userGuess = 0;
    int attempts = 0;

    //Player starts with 5 lives
    int maxLives = 5;
    int currentLives = maxLives;

     // --- COLOR CODES DEFINITION ---
    // \033[ is the escape sequence, followed by the color code number, and 'm'
    string RESET = "\033[0m";   // Resets terminal to default color
    string RED   = "\033[31m";  // Red text
    string BLUE  = "\033[34m";  // Blue text
    string GREEN = "\033[32m";  // Green text for winning!
    string GRAY = "\033[90m";  // Lost lives

    cout << "=== WELCOME TO THE GUESS THE NUMBER ===\n";
    cout << "I have picked a number between 1 and 100. What do you think it is?\n\n";
    cout << "You have " << maxLives << " lives. Each wrong guess will cost you a life.\n";

    // 3. The Game Loop
    // This loop will keep running as long as the user hasn't guessed the secret number
    while (userGuess != secretNumber && currentLives > 0) {
        // --- DYNAMIC HEARTS DISPLAY ---
        cout << "Lives: ";
        for (int i = 0; i < maxLives; i++) {
            if (i < currentLives) {
                // Print a vibrant red heart
                cout << RED << "♥ " << RESET;
            } else {
                // Print an extinguished gray/dark heart
                cout << GRAY << "♡ " << RESET; // Using an open heart symbol
            }
        }
        cout << "\n";
        
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++; // Increment the number of tries

        // 4. Check the logic
        if (userGuess > secretNumber) {
            cout << RED << "TOO HIGH!! Try again." << RESET << "\n\n";
            currentLives--;
            if (currentLives>0) cout << "You have " << currentLives << " lives left.\n";
        } 
        else if (userGuess < secretNumber) {
            cout << BLUE << "TOO LOW!! Try again." << RESET << "\n\n";
            currentLives--;
            if (currentLives>0) cout << "You have " << currentLives << " lives left.\n";
        } 
        else {
            cout << GREEN << "\n CONGRATULATIONS! You guessed the secret number " << secretNumber << "!" << RESET << "\n";
            cout << "It took you " << attempts << " attempts.\n";
        }
    }
    // 5. Game Over Logic
    if (currentLives == 0) {
        // Show the fully extinguished hearts one last time
        cout << "Lives: ";
        for (int i = 0; i < maxLives; i++) {
            cout << GRAY << "♡ " << RESET;
        }
        cout << "\n\n" << RED << "💀 Game Over! You ran out of lives." << RESET << "\n";
        cout << "The secret number was: " << secretNumber << "\n";
    } 

    // Force the program to wait for the user to press Enter before closing
    cin.ignore(); // Clears any leftover input characters
    cout << "\nPress Enter to exit the game...";
    cin.get();    // Pauses the program and waits for an Enter key press

  return 0;
}