
#include "calculator.hpp"
#include "utils.hpp"
#include <optional>

template <typename T>
constexpr inline T Calculator<T>::add(const T &a, const T &b) const {
  return a + b;
}

template <typename T>
constexpr inline T Calculator<T>::subtract(const T &a, const T &b) const {
  return a - b;
}

template <typename T>
constexpr inline T Calculator<T>::multiply(const T &a, const T &b) const {
  return a * b;
}

template <typename T>
[[nodiscard]] constexpr inline Optional<T>
Calculator<T>::divide(const T &a, const T &b) const {
  if (b == 0) {
    return std::nullopt;
  }
  return a / b;
}
