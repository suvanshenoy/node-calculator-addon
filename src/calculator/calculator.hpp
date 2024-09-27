#pragma once

#include "utils.hpp"
#include <optional>
#include <type_traits>

namespace Calculator {
template <typename T>
[[nodiscard]] constexpr inline
    typename std::enable_if<std::is_integral_v<T>, T>::type
    add(const T &first, const T &second) {
  return first + second;
}

template <typename T>
[[nodiscard]] constexpr inline
    typename std::enable_if<std::is_integral_v<T>, T>::type
    subtract(const T &first, const T &second) {
  return first - second;
}

template <typename T>
[[nodiscard]] constexpr inline
    typename std::enable_if<std::is_integral_v<T>, T>::type
    multiply(const T &first, const T &second) {
  return first * second;
}

template <typename T>
[[nodiscard]] constexpr inline
    typename std::enable_if<std::is_integral_v<T>, Optional<T>>::type
    divide(const T &first, const T &second) {
  if (second == 0) {
    return std::nullopt;
  }
  return first / second;
}
} // namespace Calculator
