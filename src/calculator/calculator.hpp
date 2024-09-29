#pragma once

#include "utils.hpp"
#include <concepts>

namespace Calculator {

template <Addable T>
[[nodiscard]] constexpr inline T add(const T &first, const T &second) {
  return first + second;
}

template <Subtractable T>
[[nodiscard]] constexpr inline T subtract(const T &first, const T &second) {
  return first - second;
}

template <MultiPlyable T>
[[nodiscard]] constexpr inline T multiply(const T &first, const T &second) {
  return first * second;
}

template <Dividable T>
[[nodiscard]] constexpr inline Optional<T> divide(const T &first,
                                                  const T &second) {
  if (second == 0) {
    return std::nullopt;
  }
  return first / second;
}
} // namespace Calculator
