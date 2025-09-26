#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomNumber;
int currentPlayer = 1;

void guessNumber() {
    int guess;
    cout << "Player " << currentPlayer << ", enter your guess (1-100): ";
    cin >> guess;

    if (guess == randomNumber) {
        cout << "Player " << currentPlayer << " wins! The number was " << randomNumber << ".\n";
        return;
    } 
    else if (guess < randomNumber) {
        cout << "Too low!\n";
    } 
    else {
        cout << "Too high!\n";
    }

    currentPlayer = (currentPlayer == 1 ? 2 : 1);
    guessNumber();
}

int main() {
    srand(time(0));
    randomNumber = rand() % 100 + 1;
    guessNumber();
    return 0;
}
