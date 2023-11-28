// Louis Jahnigen
// CIS 1202 501
// November 28, 2023

#include <iostream>

char character(char start, int offset);

int main() {
  std::cout << character('a', 1) << '\n';

  return 0;
}


char character(char start, int offset) {
  return start + offset;
}
