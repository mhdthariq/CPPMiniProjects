#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string playing;
    string answer;
    int score = 0;

    // Welcome message
    cout << "Welcome to the Capital City Quiz Game!\n";
    cout << "Are you ready to play? (yes/no): ";
    getline(cin, playing);

    // Check if the player is ready to play
    if (playing != "yes") {
        cout << "Goodbye!\n";
        return 0;
    }

    cout << "\nLet's start the quiz!\n\n";

    // Questions and answers
    vector<pair<string, string>> quiz = {
        {"What is the capital of Japan?", "Tokyo"},
        {"What is the capital of France?", "Paris"},
        {"What is the capital of Italy?", "Rome"},
        {"What is the capital of Germany?", "Berlin"},
        {"What is the capital of Spain?", "Madrid"},
        {"What is the capital of the United States?", "Washington D.C."},
        {"What is the capital of Canada?", "Ottawa"},
        {"What is the capital of Australia?", "Canberra"},
        {"What is the capital of Brazil?", "Brasilia"},
        {"What is the capital of South Korea?", "Seoul"}
    };

    // Loop through the questions
    for (const auto& [question, correct_answer] : quiz) {
        cout << question << " ";
        getline(cin, answer);

        // Convert the answer to lowercase for case-insensitive comparison
        string temp_answer = correct_answer;
        transform(temp_answer.begin(), temp_answer.end(), temp_answer.begin(), ::tolower);
        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

        if (answer == temp_answer) {
            cout << "Correct!\n\n";
            ++score;
        } else {
            cout << "Incorrect! The correct answer is " << correct_answer << ".\n\n";
        }
    }

    // Display the final score
    cout << "You got " << score << " out of " << quiz.size() << " questions correct.\n";
    cout << "Your final score is " << fixed << setprecision(2) << (static_cast<double>(score) / quiz.size()) * 100 << "%.\n";

    return 0;
}
