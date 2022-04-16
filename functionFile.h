#pragma once

#include <iostream>
#include <string>
namespace test1 {

static const std::string one{"1"};
static const std::string zero{"0"};

template <typename signedT, typename unsignedT>
std::string toBinary1(signedT num);
template <typename signedT, typename unsignedT> void printBinary1(signedT n);

template <typename signedT> std::string toBinary2(signedT num);
template <typename signedT> void printBinary2(signedT n) {
  std::cout << toBinary2(n) << std::endl;
}

template <typename signedT> std::string toBinary3(signedT num) {
  std::string result;
  unsigned long long uNum = *((signedT *)(&num));
  for (auto i = 0; i < 8 * sizeof(signedT); ++i) {
    result.insert(0, (uNum & 1 ? one : zero));
    uNum >>= 1;
  }
  return result;
}
template <typename signedT> void printBinary3(signedT n) {
  std::cout << toBinary3(n) << std::endl;
}

template <typename T> std::string positiveToBinary4(T num) {
  std::string result;
  for (auto i = 0; i < 8 * sizeof(T); ++i) {
    result.insert(0, (num & 1 ? one : zero));
    num >>= 1;
  }
  return result;
}
template <typename T> std::string negativeToBinary4(T num) {
  std::string result;
  num = -(num + 1);
  for (auto i = 0; i < 8 * sizeof(T); ++i) {
    result.insert(0, (num & 1 ? zero : one));
    num >>= 1;
  }
  return result;
}

template <typename signedT> std::string toBinary4(signedT num) {
  if (num < 0)
    return negativeToBinary4(num);
  else
    return positiveToBinary4(num);
}
template <typename signedT> void printBinary4(signedT n) {
  std::cout << toBinary4(n) << std::endl;
}

template <typename T> std::string toBinary5(T num) {
  std::string result;

  std::string one{"1"};
  std::string zero{"0"};

  if (num < 0) {
    num = -(num + 1);
    one = "0";
    zero = "1";
  }

  for (auto i = 0; i < 8 * sizeof(T); ++i) {
    result.insert(0, (num & 1 ? one : zero));
    num >>= 1;
  }
  return result;
}
template <typename signedT> void printBinary5(signedT n) {
  std::cout << toBinary5(n) << std::endl;
}
} // namespace test1