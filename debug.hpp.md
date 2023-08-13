---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/static_range_sum.test.cpp
    title: test/library_checker/static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/1787/submission/191105890
    - https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
  bundledCode: "#line 2 \"debug.hpp\"\n\n#include <iostream>\n#include <type_traits>\n\
    #include <string>\n#include <bitset>\n#include <tuple>\n\nnamespace dbg {\n  \
    \  // arithmetic\n    template <class T, std::enable_if_t<std::is_arithmetic_v<T>,\
    \ int> = 0>\n    void print(const T &x) {std::cerr << std::boolalpha << x;}\n\n\
    \    // string\n    void print(const std::string &x) {std::cerr << '\\\"' << x\
    \ << '\\\"';}\n\n    // bitset\n    template <std::size_t N> void print(const\
    \ std::bitset<N> &Bs) {std::cerr << Bs;}\n\n    // pair\n    template <class T,\
    \ class U> void print(const std::pair<T, U> &p) {\n        std::cerr << \"(\"\
    ;\n        print(p.first);\n        std::cerr << \", \";\n        print(p.second);\n\
    \        std::cerr << \")\";\n    }\n\n    // tuple\n    template <class... Args>\
    \ void print(const std::tuple<Args...> &t) {\n        std::cerr << \"(\";\n  \
    \      std::apply([](auto &&... args) {((print(args), std::cerr << \", \"), ...);},\
    \ t);\n        std::cerr << \")\";\n    }\n\n    // Iterable\n    template <typename\
    \ T, typename = std::void_t<>>\n    struct is_iterable : public std::false_type\
    \ {};\n\n    template <typename T>\n    struct is_iterable<T, std::void_t<decltype(std::declval<T>().begin(),\n\
    \            std::declval<T>().end())>>\n            : public std::true_type {};\n\
    \n    template <typename T>\n    using is_iterable_t = typename is_iterable<T>::type;\n\
    \n    template <typename T>\n    inline constexpr bool is_iterable_v = is_iterable<T>::value;\n\
    \n    template <class T, std::enable_if_t<dbg::is_iterable_v<T>, int> = 0>\n \
    \   void print(const T &v) {\n        int f = 0;\n        std::cerr << '{';\n\
    \        for (const auto &i : v) std::cerr << (f++ ? \", \" : \"\"), print(i);\n\
    \        std::cerr << \"}\";\n    }\n\n// Debug Mode\n    void debug_out() { std::cerr\
    \ << endl; }\n    template <typename Head, typename... Tail>\n    void debug_out(Head\
    \ H, Tail... T) {\n        std::cerr << \" \", print(H), debug_out(T...);\n  \
    \  }\n#define debug(...)                                                     \
    \        \\\n  std::cerr << __func__ << \":\" << __LINE__ << \" [\" << #__VA_ARGS__\
    \             \\\n            << \"] =\",                                    \
    \                      \\\n      debug_out(__VA_ARGS__)\n};\n\nusing namespace\
    \ dbg;\n//\n//} // namespace dbg\n\n/**\n * Based on submission('https://codeforces.com/contest/1787/submission/191105890')\n\
    \ * ANSI Escape Sequences: https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797\n\
    \ */\n"
  code: "#pragma once\n\n#include <iostream>\n#include <type_traits>\n#include <string>\n\
    #include <bitset>\n#include <tuple>\n\nnamespace dbg {\n    // arithmetic\n  \
    \  template <class T, std::enable_if_t<std::is_arithmetic_v<T>, int> = 0>\n  \
    \  void print(const T &x) {std::cerr << std::boolalpha << x;}\n\n    // string\n\
    \    void print(const std::string &x) {std::cerr << '\\\"' << x << '\\\"';}\n\n\
    \    // bitset\n    template <std::size_t N> void print(const std::bitset<N> &Bs)\
    \ {std::cerr << Bs;}\n\n    // pair\n    template <class T, class U> void print(const\
    \ std::pair<T, U> &p) {\n        std::cerr << \"(\";\n        print(p.first);\n\
    \        std::cerr << \", \";\n        print(p.second);\n        std::cerr <<\
    \ \")\";\n    }\n\n    // tuple\n    template <class... Args> void print(const\
    \ std::tuple<Args...> &t) {\n        std::cerr << \"(\";\n        std::apply([](auto\
    \ &&... args) {((print(args), std::cerr << \", \"), ...);}, t);\n        std::cerr\
    \ << \")\";\n    }\n\n    // Iterable\n    template <typename T, typename = std::void_t<>>\n\
    \    struct is_iterable : public std::false_type {};\n\n    template <typename\
    \ T>\n    struct is_iterable<T, std::void_t<decltype(std::declval<T>().begin(),\n\
    \            std::declval<T>().end())>>\n            : public std::true_type {};\n\
    \n    template <typename T>\n    using is_iterable_t = typename is_iterable<T>::type;\n\
    \n    template <typename T>\n    inline constexpr bool is_iterable_v = is_iterable<T>::value;\n\
    \n    template <class T, std::enable_if_t<dbg::is_iterable_v<T>, int> = 0>\n \
    \   void print(const T &v) {\n        int f = 0;\n        std::cerr << '{';\n\
    \        for (const auto &i : v) std::cerr << (f++ ? \", \" : \"\"), print(i);\n\
    \        std::cerr << \"}\";\n    }\n\n// Debug Mode\n    void debug_out() { std::cerr\
    \ << endl; }\n    template <typename Head, typename... Tail>\n    void debug_out(Head\
    \ H, Tail... T) {\n        std::cerr << \" \", print(H), debug_out(T...);\n  \
    \  }\n#define debug(...)                                                     \
    \        \\\n  std::cerr << __func__ << \":\" << __LINE__ << \" [\" << #__VA_ARGS__\
    \             \\\n            << \"] =\",                                    \
    \                      \\\n      debug_out(__VA_ARGS__)\n};\n\nusing namespace\
    \ dbg;\n//\n//} // namespace dbg\n\n/**\n * Based on submission('https://codeforces.com/contest/1787/submission/191105890')\n\
    \ * ANSI Escape Sequences: https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: debug.hpp
  requiredBy: []
  timestamp: '2023-08-13 21:39:22+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/static_range_sum.test.cpp
documentation_of: debug.hpp
layout: document
redirect_from:
- /library/debug.hpp
- /library/debug.hpp.html
title: debug.hpp
---
