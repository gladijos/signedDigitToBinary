#include <iostream>
#include <string>

#include "functionFile.h"

using currentTestType = int64_t;
using currentTestTypeU = uint64_t;

int main(int /*argc*/, char * /*argv*/ []) {
  std::string nStr;
  nStr.resize(256);

  while (true) {
    std::cout << "Please, input signed integer " << std::endl;
    std::getline(std::cin, nStr);
    long long num;
    char *parseEnd;
    num = std::strtol(nStr.c_str(), &parseEnd, 10);
    auto strEnd = &nStr.back();
    if ((strEnd + 1) != parseEnd) {
      std::cout << "fail parse input text" << std::endl;
    } else {
      test1::printBinary1<currentTestType, currentTestTypeU>(
          static_cast<currentTestType>(num));
      test1::printBinary2(static_cast<currentTestType>(num));
      test1::printBinary3(static_cast<currentTestType>(num));
      test1::printBinary4(static_cast<currentTestType>(num));
      test1::printBinary5(static_cast<currentTestType>(num));
    }
  }
  return 1;
}