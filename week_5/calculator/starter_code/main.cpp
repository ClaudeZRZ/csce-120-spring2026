// for local use only.  do not submit.
#include <iostream>
#include <string>

using std::cout, std::endl, std::getline, std::string;

double calculate(string line);

int main() {
    cout << "Enter the expression to calculate in one line: " << endl;
    string line;
    getline(std::cin, line);

    try {
        cout << "result: " << calculate(line) << endl;
    } catch (const std::invalid_argument& err) {
        cout << err.what() << endl;
    }

    return 0;
}
