#include <iostream>
using namespace std;
#include "string2wstring.h"
#include "lang.h"

int
main(int argc, char ** argv){
// the main function takes the name of a language as the first
// argument: ll
  if (argc < 2) {
    cerr << "usage: progname langname" << endl;
    cerr << "  example: 'progname en' for English" << endl;
    return 0;
  }
  string ll = argv[1];

// then it constructs a language object after looking for the
// necessary files that support the language
// for example for 'en' the files are as follows.
// en.p : list of prefixes
// en.s : list of stems
// en.x : list of suffixes
// en.pp: list of prefix-prefix concatenation rules (optional)
// en.ps: list of prefix-stem concatenation rules
// en.sx: list of stem-suffix concatenation rules
// en.xx: list of suffix-suffix concatenation rules (optional)
//
// each prefix, suffix and stem line contain the prefix, suffix
// or stem followed by a number specifying its concatenation
// category
//
// each concatenation rule line is a pair of number that
// specifies that category 1 can be concatenated with
// category 2
  Lang_t lang(ll);

  // Then the program loops waiting for user input
  while (true) {
    // first get the action choice
    wcout << "(A) to analyze, (G) to generate and (Q) to quit: " << endl;
    wchar_t c;
    wcin >> c;
    if (c == 'Q' || c == 'q') {
    // quit for q
      wcout << "exiting program gracefully." << endl;
      break;
    }
    if (c == 'a' || c == 'A') {
    // perform analysis of the word for a
      wcout << "Please enter the word to analyze: ";
      wstring word;
      wcin >> word;
      lang.analyze(word);
    }else if (c == 'g' || c == 'G') {
    // generate words from word for g
      wcout << "Please enter the word to synthesize: ";
      wstring word;
      wcin >> word;
      lang.synthesize(word);
    }else {
      cerr << "Wrong input, please select action again."<< endl;
    }
  }
  return 0;
}
