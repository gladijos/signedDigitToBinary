#include "functionFile.h"

#include <cstdio>  // for printf
#include <cstring> // for memset

namespace test1 {

template <typename T> void printBinary(T num, bool realPrint) {
  // 1. конечно такого не может случиться, но если numSignes будет равным 0, то
  // в цикле будет некорректное поведение при условии, что numSignes окажется
  // беззнаковым типом, поэтому явно укажем минимальный тип из "signed integer
  // types".
  // 2. constexpr помогает сэкономить на выделении памяти. вместо кучи
  // используем стек
  constexpr short numSignes = 8 * sizeof(T);
  char result[numSignes + 1];
  char one{'1'};
  char zero{'0'};

  // используем матчасть. вместо этого можно было бы нагло кастануть область
  // памяти к одному из "unsigned integer types", но второе решение менее
  // красивое и более медленное
  if (num < 0) {
    num = -(num + 1);
    one = '0';
    zero = '1';
  }
  // memset позволяет подсэкономить на положительных числах, поскольку внутри
  // цикла стоит сравнение с 0
  memset(result, zero, numSignes);

  for (auto i = numSignes - 1; i >= 0; --i) {
    // хорошая экономия на малых значениях положительных числел большой
    // разрядности
    if (num == 0) {
      break;
    }
    result[i] = (num & 1 ? one : zero);
    num >>= 1;
  }
  result[numSignes] = '\0';
  if (realPrint) {
    printf("%s\n", result);
  }
}

#define REG_TEMPLATE_SPEC(signedT)                                             \
  template void printBinary<signedT>(signedT n, bool realPrint)

// Строго говоря char(signed char) не является "signed integer types ", но пусть
// будет
REG_TEMPLATE_SPEC(char);
REG_TEMPLATE_SPEC(short);
REG_TEMPLATE_SPEC(int);
REG_TEMPLATE_SPEC(long);
REG_TEMPLATE_SPEC(long long);

#undef REG_TEMPLATE_SPEC
} // namespace test1