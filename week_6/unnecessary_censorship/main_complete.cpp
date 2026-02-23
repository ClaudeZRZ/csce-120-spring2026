#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "censor.h"

#define debug(X) std::cout << "[DEBUG] (" << __func__ << ":" << __LINE__ << ") " << #X << "=" << std::boolalpha << X << std::endl;

int main(int argc, char* argv[]) {
  // get filenames from command line
  if (argc < 4) {
    std::cout << "usage: " << argv[0] << " <censor words filename> <original text filename> <censored text filename>" << std::endl;
    return 1;
  }
  std::string censor_words_filename = argv[1];
  std::string original_text_filename = argv[2];
  std::string censored_text_filename = argv[3];

  // create filestreams
  std::ifstream censor_in(censor_words_filename);
  std::ifstream original_in(original_text_filename);
  std::ofstream censor_out(censored_text_filename);

  // TODO(student): add code to check whether the streams are open
  //                if not, print an error and exit
  if (!censor_in.is_open()) {
    std::cerr << "error: could not open censor words file: " << censor_words_filename << std::endl;
    return 1;
  }
  if (!original_in.is_open()) {
    std::cerr << "error: could not open original text file: " << original_text_filename << std::endl;
    return 1;
  }
  if (!censor_out.is_open()) {
    std::cerr << "error: could not open censored text file: " << censored_text_filename << std::endl;
    return 1;
  }

  // get list of words to censor from file
  std::string censor_words = get_censor_words(censor_in);

  // read original text, censor text, write out updated text to output file
  // process text line by line, until the end of the file
  while (!original_in.eof()) {
    // 1) get next line
    std::string line;
    std::getline(original_in, line);

    // TODO(student): add code to check if getline executed properly
    //                if not, print a warning, recover, and continue
    if (original_in.fail()) {
      if (original_in.eof()) {
        // not actually a problem, just at end of file
        std::cout << "info: ignoring empty line at end of file" << std::endl;
        break;
      }
      // failed, but not at end of file... is this even possible?
      original_in.clear();
      original_in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    // 2) censor the line
    std::string line_out = censor(line, censor_words);

    // 3) write the censored line to output file
    censor_out << line_out << std::endl;
  }

  // no need to close fstreams because this is done by their destructors
  return 0;
}
