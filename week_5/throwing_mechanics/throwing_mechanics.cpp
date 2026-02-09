#include <iostream>
#include <string>
#include <stdexcept>

class PaperAirplane : public std::exception {
 public:
    const char* what() const noexcept override {
        return "Whoosh!";
    }
};

void throw_an_int() {
    throw 7;
}

void throw_a_c_string() {
    throw "ouch!";
}

void throw_a_std_string() {
    throw std::string("ouch!");
}

void throw_a_std_exception() {
    throw std::invalid_argument("no no no, not in my house.");
}

void throw_a_paper_airplane() {
    throw PaperAirplane();
}

void f3() {
    throw std::runtime_error("boo!");
}

void f2() {
    f3();
}

void f1() {
    f2();
}

int main() {
    std::cout << "(1) int\n";
    std::cout << "(2) c string (char const*)\n";
    std::cout << "(3) std::string\n";
    std::cout << "(4) std::invalid_argument\n";
    std::cout << "(5) PaperAirplane\n";
    std::cout << "(6) from the deep\n";
    std::cout << "> ";
    int number;
    std::cin >> number;
    switch (number) {
    case 1:
        throw_an_int();
    case 2:
        throw_a_c_string();
    case 3:
        throw_a_std_string();
    case 4:
        throw_a_std_exception();
    case 5:
        throw_a_paper_airplane();
    case 6:
        f1();
    default:
        throw std::out_of_range("i'm sorry dave, i can't let you do that...");
    }
    return 0;
}