#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Utility function to get user input
int getUserChoice(int min, int max) {
    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice >= min && choice <= max) break;
        cout << "Invalid choice. Try again.\n";
    }
    return choice;
}

// ------------------ Rock Paper Scissors ------------------

void playRockPaperScissors() {
    string choices[] = {"Rock", "Paper", "Scissors"};
    int userChoice, computerChoice;

    cout << "\n--- Rock Paper Scissors ---\n";
    cout << "1. Rock\n2. Paper\n3. Scissors\n";

    userChoice = getUserChoice(1, 3);
    computerChoice = rand() % 3 + 1;

    cout << "You chose: " << choices[userChoice - 1] << endl;
    cout << "Computer chose: " << choices[computerChoice - 1] << endl;

    if (userChoice == computerChoice)
        cout << "It's a draw!\n";
    else if ((userChoice == 1 && computerChoice == 3) ||
             (userChoice == 2 && computerChoice == 1) ||
             (userChoice == 3 && computerChoice == 2))
        cout << "You win!\n";
    else
        cout << "You lose!\n";
}

// ------------------ Number Guessing Game ------------------

void playNumberGuessing() {
    int number = rand() % 100 + 1;
    int guess, attempts = 0;

    cout << "\n--- Number Guessing Game (1-100) ---\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < number)
            cout << "Too low!\n";
        else if (guess > number)
            cout << "Too high!\n";
        else
            cout << "Correct! You guessed it in " << attempts << " tries.\n";

    } while (guess != number);
}

// ------------------ Coin Flip ------------------

void playCoinFlip() {
    cout << "\n--- Coin Flip ---\n";
    cout << "1. Heads\n2. Tails\n";

    int userChoice = getUserChoice(1, 2);
    int flip = rand() % 2 + 1;

    cout << "Coin shows: " << (flip == 1 ? "Heads" : "Tails") << endl;
    if (userChoice == flip)
        cout << "You guessed it!\n";
    else
        cout << "Better luck next time!\n";
}

// ------------------ Game Menu ------------------

void showMenu() {
    cout << "\n==== Mini Game Arcade ====\n";
    cout << "1. Rock Paper Scissors\n";
    cout << "2. Number Guessing\n";
    cout << "3. Coin Flip\n";
    cout << "4. Exit\n";
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int choice;

    do {
        showMenu();
        choice = getUserChoice(1, 4);

        switch (choice) {
            case 1:
                playRockPaperScissors();
                break;
            case 2:
                playNumberGuessing();
                break;
            case 3:
                playCoinFlip();
                break;
            case 4:
                cout << "Thanks for playing!\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
