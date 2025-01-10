#include <iostream>
#include <random>
#include <string>
#include <unordered_map>

using namespace std;

int get_choice_number(const string& choice) {
    static const unordered_map<string, int> choices = {
        {"rock", 0},
        {"paper", 1},
        {"scissors", 2}
    };
    auto it = choices.find(choice);
    return it != choices.end() ? it->second : -1;
}

int main() {
    int user_wins = 0;
    int computer_wins = 0;
    string user_input;
    const string options[3] = {"rock", "paper", "scissors"};

    // Welcome message
    cout << "Welcome to the Rock, Paper, Scissors Game!\n";

    // Initialize the random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 2);

    while (true) {
        cout << "Enter, 'rock', 'paper', 'scissors', or 'q' to quit: ";
        cin >> user_input;

        if (user_input == "q") {
            break;
        }

        int user_choice = get_choice_number(user_input);
        if (user_choice == -1) {
            cout << "Invalid input. Please enter 'rock', 'paper', or 'scissors'.\n";
            continue;
        }

        // rock = 0, paper = 1, scissors = 2
        int random_number = dist(gen);
        cout << "Computer chose " << options[random_number] <<".\n";

        if ((user_choice == 0 && random_number == 2) ||     // rock beats scissors
            (user_choice == 1 && random_number == 0) ||     // paper beats rock
            (user_choice == 2 && random_number == 1)) {     // scissors beats paper
            cout << "You win!\n";
            user_wins++;
        } else if (user_choice == random_number) {
            cout << "It's a tie!\n";
        } else {
            cout << "You lose!\n";
            computer_wins++;
        }
    }

    // Final score

    return 0;
}
