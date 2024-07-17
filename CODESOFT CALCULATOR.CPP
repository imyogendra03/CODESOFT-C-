#include <iostream>

int main() {
    double num1, num2;
    char operation;
    bool continue_calculating = true;

    while (continue_calculating) {
        // Get user input
        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter second number: ";
        std::cin >> num2;
        std::cout << "Enter operation (+, -, *, /): ";
        std::cin >> operation;

        // Perform the chosen operation
        switch (operation) {
            case '+':
                std::cout << "Result: " << num1 + num2 << std::endl;
                break;
            case '-':
                std::cout << "Result: " << num1 - num2 << std::endl;
                break;
            case '*':
                std::cout << "Result: " << num1 * num2 << std::endl;
                break;
            case '/':
                if (num2 != 0)
                    std::cout << "Result: " << num1 / num2 << std::endl;
                else
                    std::cout << "Error: Division by zero is not allowed." << std::endl;
                break;
            default:
                std::cout << "Error: Invalid operation. Please enter one of +, -, *, /." << std::endl;
                break;
        }

        // Ask the user if they want to perform another calculation
        char choice;
        std::cout << "Do you want to perform another calculation? (y/n): ";
        std::cin >> choice;
        continue_calculating = (choice == 'y' || choice == 'Y');
    }

    std::cout << "Calculator program has ended." << std::endl;

    return 0;
}
