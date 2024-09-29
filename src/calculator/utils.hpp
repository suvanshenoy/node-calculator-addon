#pragma once

#include <concepts>
#include <optional>

template <typename T>
concept Addable = requires(const T &first, const T &second) {
  { first + second } -> std::same_as<T>;
};

template <typename T>
concept Subtractable = requires(const T &first, const T &second) {
  { first - second } -> std::same_as<T>;
};

template <typename T>
concept MultiPlyable = requires(const T &first, const T &second) {
  { first *second } -> std::same_as<T>;
};

template <typename T>
concept Dividable = requires(const T &first, const T &second) {
  { first / second } -> std::same_as<T>;
};

template <typename T> using Optional = std::optional<T>;
