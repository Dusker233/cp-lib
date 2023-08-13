#pragma once

#include <iostream>
#include <type_traits>
#include <string>
#include <bitset>
#include <tuple>

namespace dbg {
    // arithmetic
    template <class T, std::enable_if_t<std::is_arithmetic_v<T>, int> = 0>
    void print(const T &x) {std::cerr << std::boolalpha << x;}

    // string
    void print(const std::string &x) {std::cerr << '\"' << x << '\"';}

    // bitset
    template <std::size_t N> void print(const std::bitset<N> &Bs) {std::cerr << Bs;}

    // pair
    template <class T, class U> void print(const std::pair<T, U> &p) {
        std::cerr << "(";
        print(p.first);
        std::cerr << ", ";
        print(p.second);
        std::cerr << ")";
    }

    // tuple
    template <class... Args> void print(const std::tuple<Args...> &t) {
        std::cerr << "(";
        std::apply([](auto &&... args) {((print(args), std::cerr << ", "), ...);}, t);
        std::cerr << ")";
    }

    // Iterable
    template <typename T, typename = std::void_t<>>
    struct is_iterable : public std::false_type {};

    template <typename T>
    struct is_iterable<T, std::void_t<decltype(std::declval<T>().begin(),
            std::declval<T>().end())>>
            : public std::true_type {};

    template <typename T>
    using is_iterable_t = typename is_iterable<T>::type;

    template <typename T>
    inline constexpr bool is_iterable_v = is_iterable<T>::value;

    template <class T, std::enable_if_t<dbg::is_iterable_v<T>, int> = 0>
    void print(const T &v) {
        int f = 0;
        std::cerr << '{';
        for (const auto &i : v) std::cerr << (f++ ? ", " : ""), print(i);
        std::cerr << "}";
    }

// Debug Mode
    void debug_out() { std::cerr << endl; }
    template <typename Head, typename... Tail>
    void debug_out(Head H, Tail... T) {
        std::cerr << " ", print(H), debug_out(T...);
    }
#define debug(...)                                                             \
  std::cerr << __func__ << ":" << __LINE__ << " [" << #__VA_ARGS__             \
            << "] =",                                                          \
      debug_out(__VA_ARGS__)
};

using namespace dbg;
//
//} // namespace dbg

/**
 * Based on submission('https://codeforces.com/contest/1787/submission/191105890')
 * ANSI Escape Sequences: https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
 */
