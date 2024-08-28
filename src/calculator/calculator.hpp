#pragma once

#include "utils.hpp"

template <typename T> class Calculator {
public:
  Calculator() = default;
  constexpr inline T add(const T &a, const T &b) const;
  constexpr inline T subtract(const T &a, const T &ob) const;
  constexpr inline T multiply(const T &a, const T &b) const;
  constexpr inline Optional<T> divide(const T &a, const T &b) const;
};
