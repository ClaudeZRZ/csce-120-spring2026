#include <iostream>
#include <string>
#include <cassert>
#include "password_protected_data.h"

using std::cout, std::endl;
using std::string;

int main() {
    try {
        PasswordProtectedData ppd("data", "too simple");
        assert(false && "expected constructor to throw an exception");
    } catch (const std::invalid_argument& err) {
        // good.
    } catch (...) {
        assert(false && "expected constructor to throw std::invalid_argument");
    }

    string password = "Three m@ny s3crets";
    PasswordProtectedData ppd("the answer is 42", password);

    // read the data with the correct password
    cout << ppd.get_data(password) << endl;
    assert(ppd.get_data(password) == "the answer is 42");

    // attempt to change the data with wrong password
    assert(ppd.set_data("howdy world", "") == false);

    // read the (unchanged) data using the correct password
    cout << ppd.get_data(password) << endl;
    assert(ppd.get_data(password) == "the answer is 42");

    // change the data using the correct password
    assert(ppd.set_data("howdy, world!", password) == true);

    // read the (changed) data using the correct password
    cout << ppd.get_data(password) << endl;
    assert(ppd.get_data(password) == "howdy, world!");

    // attempt to change the password to one that is too simple
    assert(ppd.change_password("$h0rT", password) == false);
    assert(ppd.change_password("n0upperc@se", password) == false);
    assert(ppd.change_password("N0LOWERC@SE", password) == false);
    assert(ppd.change_password("NoD!gits", password) == false);
    assert(ppd.change_password("N0Specials", password) == false);

    // change the password to one that is sufficiently complex
    assert(ppd.change_password("P@ssw0rd", password) == true);

    // attempt to read the data using the old (incorrect) password
    cout << ppd.get_data(password) << endl;
    assert(ppd.get_data(password).empty());

    // read the data using the new (correct) password
    cout << ppd.get_data("P@ssw0rd") << endl;
    assert(ppd.get_data("P@ssw0rd") == "howdy, world!");

    cout << "-----------------\n"
         << "all tests passing\n"
         << endl;

    cout << "=== c++ is dangerous ===" << endl;

    // steal the data (because "security" in c++ is an unfunny joke)
    struct PPD {
        string data;
        string password;
    };
    string& data = reinterpret_cast<PPD*>(&ppd)->data;
    cout << "i stole this: " << data << endl;

    // overwrite the data directly (access control? what's that?)
    data = "all your base are belong to us";
    // and read it in the "correct" way
    cout << ppd.get_data("P@ssw0rd") << endl;
}
