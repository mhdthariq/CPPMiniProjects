#include <iostream>
#include <string>

using namespace std;

int main() {
    string play;
    string name;
    string answer;

    cout << "Welcome to the Choose Your Own Adventure Game!\n";

    cout << "Do you want to play? (yes/no): ";
    cin >> play;

    if (play == "yes") {
        cout << "What is your name? ";
        cin >> name;
        cout << "Hello, " << name << "! Let's start your adventure!\n";

        cout << "You're on a dirt road, and it has come to an end. You can go left or right. Which way will you go? (left/right): ";
        cin >> answer;

        if (answer == "left") {
            cout << "You come to a lake. There is a boat and path around the lake. You can take the boat or walk around. Which way will you do? (boat/walk): ";
            cin >> answer;

            if (answer == "boat") {
                cout << "You row accross the lake but encounter a storm. The boat capsizes and you drown. Game Over!\n";
            } else if (answer == "walk") {
                cout << "You walk for a while and find a house. Do you enter the house or keep walking (enter/walk): ";
                cin >> answer;

                if (answer == "enter") {
                    cout << "You enter the house and find a treasure chest. You open it and find a golden coin! You win!\n";
                } else if (answer == "walk") {
                    cout << "You keep walking and find a monster. It eats you. Game Over!\n";
                } else {
                    cout << "Not a valid option. Game Over!\n";
                }
            } else {
                cout << "Not a valid option. Game Over!\n";
            }
        } else if (answer == "right") {
            cout << "You come to a bridge, but it looks weak. Do you cross the bridge or head back? (cross/back): ";
            cin >> answer;

            if (answer == "cross") {
                cout << "You carefully cross the bridge and see a treasure chest. Do you open it or leave it? (open/leave): ";
                cin >> answer;

                if (answer == "open") {
                    cout << "ou open the chest. The chest is full of gold and jewels. You win!\n";
                } else if (answer == "leave") {
                    cout << "You leave the treasure and walk away safely but miss out on riches. You survive, but no treasure for you. Game Over!\n";
                } else {
                    cout << "Not a valid option. Game Over!\n";
                }
            } else if (answer == "back") {
                cout << "You turn back and run into a monster. It eats you. Game Over!\n";
            } else {
                cout << "Not a valid option. Game Over!\n";
            }
        } else {
            cout << "Not a valid option. Game Over!\n";
        }

        cout << "Thanks for playing, " << name << "!\n";
    } else {
        cout << "Okay, goodbye!\n";
    }

    return 0;
}
