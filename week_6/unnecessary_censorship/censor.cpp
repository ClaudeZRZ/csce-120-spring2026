// this file is provided. do not modify. do not submit.
#include <iostream>
#include <string>
#include <sstream>
#include "censor.h"

// lowercase all letters in the string
std::string tolower(std::string str) {
  for (size_t i=0; i < str.size(); ++i) {
    str.at(i) = tolower(str.at(i));
  }
  return str;
}

// get the string that will replace the word
std::string get_replace(std::string str) {
  return std::string(str.length(), '*');
}

std::string censor(std::string line, const std::string& censor_words) {
  // treat the list of censor words as an input stream
  std::istringstream censor_word_stream(censor_words);
  // while there are censor words to process
  std::string censor_word;
  while (censor_word_stream >> censor_word) {
    // make a temporary, lowercased copy of the string
    // to use for matching against censor words
    std::string lowerLine = tolower(line);
    size_t position = lowerLine.find(censor_word);
    while (position != std::string::npos) {
      lowerLine.replace(position, censor_word.size(), get_replace(censor_word));
      line.replace(position, censor_word.size(), get_replace(censor_word));
      position = lowerLine.find(censor_word);
    }
  }
  return line;
}

std::string get_censor_words(std::istream& stream) {
  std::string censor_words;
  std::string censor_word;
  while (stream >> censor_word) {
    // the >> operator will use whitespace to determine the end of the string
    // failure checking is built in:
    //   the >> operator returns a reference to the stream,
    //   evaluating the stream as a boolean returns the same value as the stream's fail() function

    // lowercase and append the new word to a string with all the censor words
    censor_words += (" " + tolower(censor_word));
  }
  return censor_words;
}
