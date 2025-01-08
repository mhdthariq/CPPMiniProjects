#include <ios>
#include <iostream>
#include <random>
#include <limits>

using namespace std;

int main() {
    int top_of_range;
    int guess;
    int attempts = 0;

    // Welcome message
    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Enter the top of the range: ";
    cin >> top_of_range;

    if (cin.fail() || top_of_range <= 0) {
        cout << "Please type a number greater than 0 next time.\n";
        return 0;
    }

    // Initialize the random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, top_of_range);
    int random_number = dist(gen);

    // Guessing Loop
    while (true) {
        attempts++;
        cout << "Enter your guess: ";
        cin >> guess;

        if (cin.fail()) {
            cout << "Please type a number next time.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (guess == random_number) {
            cout << "You guessed the number!\n";
            break;
        } else if (guess > random_number) {
            cout << "Too high.\n";
        } else {
            cout << "Too low.\n";
        }
    }

    cout << "It took you " << attempts << " attempts to guess the number.\n";
    return 0;
}
