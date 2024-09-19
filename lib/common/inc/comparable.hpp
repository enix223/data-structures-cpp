#pragma once

#include <concepts>

// define Comparable with type constraints
template <typename T>
concept Comparable = requires(T a, T b) {
  { a < b } -> std::convertible_to<bool>;
  { a > b } -> std::convertible_to<bool>;
  { a == b } -> std::convertible_to<bool>;
  { a >= b } -> std::convertible_to<bool>;
  { a <= b } -> std::convertible_to<bool>;
};
