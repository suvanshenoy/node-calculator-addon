
#include "calculator.hpp"
#include "utils.hpp"
#include <optional>

template <typename T> T Calculator<T>::add(const T &a, const T &b) const
{
    return a + b;
}

template <typename T> T Calculator<T>::subtract(const T &a, const T &b) const
{
    return a - b;
}

template <typename T> T Calculator<T>::multiply(const T &a, const T &b) const
{
    return a * b;
}

template <typename T>
Optional<T> Calculator<T>::divide(const T &a, const T &b) const
{
    if (b == 0)
    {
        return std::nullopt;
    }
    return a / b;
}
