#include "functionFile.h"
namespace test1 {

template <typename signedT, typename unsignedT>
std::string toBinary1(signedT num) {
  std::string result;
  unsignedT uNum = *((signedT *)(&num));
  for (auto i = 0; i < 8 * sizeof(signedT); ++i) {
    result.insert(0, (uNum & 1 ? one : zero));
    uNum >>= 1;
  }
  return result;
}

template <typename signedT, typename unsignedT> void printBinary1(signedT n) {
  std::cout << toBinary1<signedT, unsignedT>(n) << std::endl;
}

#define REG_TEMPLATE_SPEC(signedT)                                             \
  template std::string toBinary1<signedT, u##signedT>(signedT num);            \
  template void printBinary1<signedT, u##signedT>(signedT n)

REG_TEMPLATE_SPEC(int8_t);
REG_TEMPLATE_SPEC(int16_t);
REG_TEMPLATE_SPEC(int32_t);
REG_TEMPLATE_SPEC(int64_t);

#undef REG_TEMPLATE_SPEC

#define REG_TEMPLATE_IMPL(signedT)                                             \
                                                                               \
  template <> std::string toBinary2<signedT>(signedT num) {                    \
    std::string result;                                                        \
    u##signedT uNum = *((signedT *)(&num));                                    \
    for (auto i = 0; i < 8 * sizeof(signedT); ++i) {                           \
      result.insert(0, (uNum & 1 ? one : zero));                               \
      uNum >>= 1;                                                              \
    }                                                                          \
    return result;                                                             \
  }

REG_TEMPLATE_IMPL(int8_t);
REG_TEMPLATE_IMPL(int16_t);
REG_TEMPLATE_IMPL(int32_t);
REG_TEMPLATE_IMPL(int64_t);
#undef REG_TEMPLATE_DECL

} // namespace test1