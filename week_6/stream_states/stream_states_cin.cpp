#include <iostream>
#include <string>
#include <sstream>

#define print(X) std::cout << #X << "=" << std::boolalpha << X << std::endl;

using std::cin;

int main() {
    // read in a line of input, place in a istringstream
    std::cout << "Provide a line of input.\n";
    std::cout << "The code will attempt to extract an integer from it." << std::endl;

    int z = -99;
    cin >> z;

    print(z);
    print(cin.eof());  // printf "7" | ./a.out
    print(cin.fail());
    print(cin.bad());
    print(cin.good());

    return 0;
}
