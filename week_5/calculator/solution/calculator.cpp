#include <iostream>
#include <sstream>
#include <string>

using std::string;

double calculate(string line) {
    double first_number = 0, second_number = 0;
    char op = ' ';

    std::istringstream iss(line);
    // TODO(student): extract <first_number> <op> <second_number> from iss
    iss >> first_number >> op >> second_number;

    double result = 0;
    // TODO(student): compute result based on op symbol, allowed symbols are +, -, *, /
    switch (op) {
        case '+':
            result = first_number + second_number;
            break;
        case '-':
            result = first_number - second_number;
            break;
        case '*':
            result = first_number * second_number;
            break;
        case '/':
            if (second_number == 0) {
                throw std::invalid_argument("error: divide by zero");
            }
            result = first_number / second_number;
            break;
        default:
            throw std::invalid_argument("error: invalid operator");
    }

    return result;
}
