// Louis Jahnigen
// CIS 1202 501
// November 28, 2023

#include <iostream>

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
  try {
    std::cout << character('a', 1) << '\n';
  } catch (invalidRangeException e) {
    std::cout << e.message << '\n';
  } catch (invalidCharacterException e) {
    std::cout << e.message << '\n';
  }

  return 0;
}


char character(char start, int offset) {
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

