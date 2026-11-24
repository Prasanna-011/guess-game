
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int main() {
    // Seed random number generator
    srand(time(0));

    int secretNumber;
    int guess;
    int attempts;
    char playAgain;

    cout << "====================================\n";
    cout << "       NUMBER GUESSING GAME\n";
    cout << "====================================\n";

    do {
        // Generate random number between 1 and 100
        secretNumber = rand() % 100 + 1;

        attempts = 0;

        cout << "\nI have selected a number between 1 and 100.\n";
        cout << "Can you guess the correct number?\n";

        // Guessing loop
        while (true) {
            cout << "\nEnter your guess: ";

            if (!(cin >> guess)) {
                cout << "Invalid input! Please enter a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (guess < 1 || guess > 100) {
                cout << "Please enter a number between 1 and 100.\n";
                continue;
            }

            attempts++;

            // Check the guess
            if (guess == secretNumber) {
                cout << "\nCongratulations! You guessed correctly!\n";
                cout << "The secret number was: " << secretNumber << endl;
                cout << "Total attempts: " << attempts << endl;

                // Display score
                int score = 100 - (attempts - 1) * 10;

                if (score < 0) {
                    score = 0;
                }

                cout << "Your score: " << score << "/100\n";
                break;
            }
            else if (guess < secretNumber) {
                cout << "Too Low! Try a higher number.\n";
            }
            else {
                cout << "Too High! Try a lower number.\n";
            }
        }

        // Ask user to play again
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

        while (playAgain != 'Y' && playAgain != 'y' &&
               playAgain != 'N' && playAgain != 'n') {
            cout << "Invalid choice! Enter Y or N: ";
            cin >> playAgain;
        }

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\n====================================\n";
    cout << "       THANK YOU FOR PLAYING!\n";
    cout << "====================================\n";

    return 0;
}
