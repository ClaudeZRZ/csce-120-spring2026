#ifndef PASSWORD_PROTECTED_DATA_H_
#define PASSWORD_PROTECTED_DATA_H_

#include <string>

using std::string;

/**
 * A password-protected string.
 * The password is required to read and write the data.
 * The password can be changed.
 */
class PasswordProtectedData {
    string secret_data;
    string secret_password;

    bool invalid_password(const string& password);
    bool too_short(const string& password, string& messages);
    bool no_uppercase(const string& password, string& messages);
    bool no_lowercase(const string& password, string& messages);
    bool no_digit(const string& password, string& messages);
    bool no_special(const string& password, string& messages);
    bool too_simple(const string& password, string& messages);

 public:
    /**
     * Construct a new password protected string.
     *
     * @param data string to protect
     * @param password password to use, must meet complexity requirements:
     *                 >= 8 characters,
     *                 >= 1 uppercase letter,
     *                 >= 1 lowercase letter,
     *                 >= 1 digit,
     *                 >= 1 special character,
     * @throws `std::invalid_argument` if password is too simple
     */
    PasswordProtectedData(string data, string password);

    /**
     * Read the data.
     *
     * @param password
     * @returns the data if the password is correct, or empty string otherwise
     */
    string get_data(const string& password);

    /**
     * Change the data.
     *
     * If the password is correct, the value of the private `secret_data`
     * is overwritten with the new value of the provided data.
     *
     * @param data
     * @param password
     * @returns `true` if the password was correct, or `false` otherwise
     */
    bool set_data(string data, const string& password);

    /**
     * Change the password.
     *
     * If the password is correct, the value of the private `secret_password`
     * is overwritten with the new value of the provided password.
     *
     * @param new_password
     * @param old_password
     * @returns `true` if the password was correct, or `false` otherwise
     */
    bool change_password(string new_password, const string& old_password);
};

#endif  // PASSWORD_PROTECTED_DATA_H_
