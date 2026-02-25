#include <iostream>

int main() {
    int x = 5;
    int y = 7;

    std::cout << "x = " << x << " @ " << &x << std::endl;
    std::cout << "y = " << y << " @ " << &y << std::endl;
    std::cout << std::endl;

    std::cout << "(*(&y + 1)) += 1;" << std::endl;
    std::cout << std::endl;
    (*(&y + 1)) += 1;

    std::cout << "x = " << x << " @ " << &x << std::endl;
    std::cout << "y = " << y << " @ " << &y << std::endl;
    std::cout << std::endl;

    return 0;
}
