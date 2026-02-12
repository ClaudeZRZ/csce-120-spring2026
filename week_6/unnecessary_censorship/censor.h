// this file is provided. do not modify. do not submit.
#ifndef PROVIDED_CENSOR_H_
#define PROVIDED_CENSOR_H_

#include <string>

// get list of words to censor from stream
std::string get_censor_words(std::istream& stream);
// censor the line using the words provided
std::string censor(std::string line, const std::string& censor_words);

#endif // PROVIDED_CENSOR_H_
