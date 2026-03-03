#include <iostream>
#include <string>
#include "password_protected_data.h"

using std::string, std::cout, std::endl;

// private methods

bool PasswordProtectedData::invalid_password(const string& password) {
    return password != secret_password;
}

bool PasswordProtectedData::too_short(const string& password, string& messages) {
    if (password.length() >= 8) {
        return false;
    }
    messages += "password should be at least 8 characters\n";
    return true;
}

bool PasswordProtectedData::no_uppercase(const string& password, string& messages) {
    for (char c : password) {
        if (isupper(c)) {
            return false;
        }
    }
    messages += "password should have an uppercase letter\n";
    return true;
}

bool PasswordProtectedData::no_lowercase(const string& password, string& messages) {
    for (char c : password) {
        if (islower(c)) {
            return false;
        }
    }
    messages += "password should have a lowercase letter\n";
    return true;
}

bool PasswordProtectedData::no_digit(const string& password, string& messages) {
    for (char c : password) {
        if (isdigit(c)) {
            return false;
        }
    }
    messages += "password should have a digit\n";
    return true;
}

bool PasswordProtectedData::no_special(const string& password, string& messages) {
    if (password.find_first_of("~`!@#$%^&*()_-+={[}]|\\:;\"'<,>.?/}") < password.length()) {
        return false;
    }
    messages += "password should have a special character\n";
    return true;
}

bool PasswordProtectedData::too_simple(const string& password, string& messages) {
    bool is_too_simple = false;
    is_too_simple = too_short(password, messages)    || is_too_simple;
    is_too_simple = no_uppercase(password, messages) || is_too_simple;
    is_too_simple = no_lowercase(password, messages) || is_too_simple;
    is_too_simple = no_digit(password, messages)     || is_too_simple;
    is_too_simple = no_special(password, messages)   || is_too_simple;
    return is_too_simple;
}

// public methods

PasswordProtectedData::PasswordProtectedData(string data, string password) : secret_data{data}, secret_password{password} {
    string messages;
    if (too_simple(password, messages)) {
        throw std::invalid_argument("password is too simple:\n" + messages);
    }
}

string PasswordProtectedData::get_data(const string& password) {
    if (invalid_password(password)) {
        cout << "get_data: ACCESS DENIED" << endl;
        return "";
    }
    cout << "get_data: ACCESS GRANTED" << endl;
    return secret_data;
}

bool PasswordProtectedData::set_data(string data, const string& password) {
    if (invalid_password(password)) {
        cout << "set_data: ACCESS DENIED" << endl;
        return false;
    }
    cout << "set_data: ACCESS GRANTED" << endl;
    secret_data = data;
    return true;
}

bool PasswordProtectedData::change_password(string new_password, const string& old_password) {
    string messages;
    if (invalid_password(old_password) || too_simple(new_password, messages)) {
        cout << "PASSWORD NOT CHANGED";
        if (!messages.empty()) {
            cout << ":\n" << messages;
        }
        cout << endl;
        return false;
    }
    cout << "PASSWORD CHANGED" << endl;
    secret_password = new_password;
    return true;
}
