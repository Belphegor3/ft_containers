#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP
#include <iostream>
#include <type_traits>

/*
constexpr comme son nom l indique est une expression constante qui a la particularite
d etre evalue a la compilation et pas a l execution et ne peut donc pas etre change a l execution.
*/

template <typename T>
struct is_integral {
  static constexpr bool value = false;
};

template <>
struct is_integral<bool> {
  static constexpr bool value = true;
};

template <>
struct is_integral<char> {
  static constexpr bool value = true;
};

template <>
struct is_integral<char16_t> {
  static constexpr bool value = true;
};

template <>
struct is_integral<char32_t> {
  static constexpr bool value = true;
};

template <>
struct is_integral<wchar_t> {
  static constexpr bool value = true;
};

template <>
struct is_integral<signed char> {
  static constexpr bool value = true;
};

template <>
struct is_integral<short> {
  static constexpr bool value = true;
};

template <>
struct is_integral<int> {
  static constexpr bool value = true;
};

template <>
struct is_integral<long> {
  static constexpr bool value = true;
};

template <>
struct is_integral<long long> {
  static constexpr bool value = true;
};

template <>
struct is_integral<unsigned char> {
  static constexpr bool value = true;
};

template <>
struct is_integral<unsigned short> {
  static constexpr bool value = true;
};

template <>
struct is_integral<unsigned int> {
  static constexpr bool value = true;
};

template <>
struct is_integral<unsigned long> {
  static constexpr bool value = true;
};

template <>
struct is_integral<unsigned long long> {
  static constexpr bool value = true;
};

#endif