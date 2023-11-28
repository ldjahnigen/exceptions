// Louis Jahnigen
// CIS 1202 501
// November 28, 2023

#include <iostream>


// define custom exceptions using inheritance
class invalidCharacterException : public std::exception {
  public:
    std::string message = "an invalid character was passed";

};


class invalidRangeException : public std::exception {
  public:
    std::string message = "an invalid range was passed";

};


char character(char start, int offset);

int main() {
  // base case, should not throw an error
  try {
    std::cout << character('a', 1) << '\n';
  } catch (invalidRangeException e) {
    std::cout << e.message << '\n';
  } catch (invalidCharacterException e) {
    std::cout << e.message << '\n';
  }

  // should throw invalidRangeException
  try {
    std::cout << character('a', -1) << '\n';
  } catch (invalidRangeException e) {
    std::cout << e.message << '\n';
  } catch (invalidCharacterException e) {
    std::cout << e.message << '\n';
  }

  // should not throw an error
  try {
    std::cout << character('Z', 1) << '\n';
  } catch (invalidRangeException e) {
    std::cout << e.message << '\n';
  } catch (invalidCharacterException e) {
    std::cout << e.message << '\n';
  }
  
  // should throw invalidCharacterException
  try {
    std::cout << character('?', 1) << '\n';
  } catch (invalidRangeException e) {
    std::cout << e.message << '\n';
  } catch (invalidCharacterException e) {
    std::cout << e.message << '\n';
  }

  return 0;
}


char character(char start, int offset) {
  bool upper; 

  if (!isalpha(start)) {
    invalidCharacterException e;
    throw e;
  }
  if (offset < 0 || offset > 26) {
    invalidRangeException e;
    throw e;
  }

    return start + offset;
}

