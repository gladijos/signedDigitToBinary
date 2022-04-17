#pragma once

namespace test1 {
/**
 * @brief функция печатат целое знаковое число в бинарном виде
 *
 * @tparam T - целочисленный беззнаковый тип
 * @param num - число
 * @param realPrint - флаг реального консольного вывода. можно отключать для
 * замеров производительности самой конвертации
 * @note реализация вынесена в cpp-файл для того, чтобы строго специализировать
 * темплейтные типы для передаваемого числа
 */
template <typename T> void printBinary(T num, bool realPrint = false);

} // namespace test1