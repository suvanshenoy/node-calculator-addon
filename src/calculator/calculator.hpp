#pragma once

#include "utils.hpp"

template <typename T> class Calculator
{
  public:
    Calculator() = default;
    T add(const T &a, const T &b) const;
    T subtract(const T &a, const T &ob) const;
    T multiply(const T &a, const T &b) const;
    Optional<T> divide(const T &a, const T &b) const;
};

#include "calculator.tpp"
