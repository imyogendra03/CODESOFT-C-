#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Seed the random number generator
    int number_to_guess = std::rand() % 100 + 1; // Random number between 1 and 100
    int user_guess = 0;

    std::cout << "I have selected a number between 1 and 100. Can you guess what it is?" << std::endl;

    while (user_guess != number_to_guess) {
        std::cout << "Enter your guess: ";
        std::cin >> user_guess;

        if (user_guess < number_to_guess) {
            std::cout << "Too low. Try again." << std::endl;
        } else if (user_guess > number_to_guess) {
            std::cout << "Too high. Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number." << std::endl;
        }
    }

    return 0;
}
