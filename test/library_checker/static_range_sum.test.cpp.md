---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/1D-fenwick.hpp
    title: data_structure/1D-fenwick.hpp
  - icon: ':heavy_check_mark:'
    path: debug.hpp
    title: debug.hpp
  - icon: ':question:'
    path: head.hpp
    title: head.hpp
  - icon: ':heavy_check_mark:'
    path: io/Printer_local.hpp
    title: io/Printer_local.hpp
  - icon: ':heavy_check_mark:'
    path: io/Scanner_local.hpp
    title: io/Scanner_local.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/library_checker/static_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#line 1 \"head.hpp\"\
    \n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n#include<bits/stdc++.h>\n\
    #define ioclear std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);\n\
    #define endl '\\n'\n#define CLOCK 1e3 * clock() / CLOCKS_PER_SEC\n\n\n#line 2\
    \ \"data_structure/1D-fenwick.hpp\"\n\ntemplate<typename T>\nstruct Fenwick\n\
    {\n\tconst int n;\n\tstd::vector<T> a;\n\n\tFenwick(int _n) : n(_n), a(_n) {}\n\
    \n\tvoid add(int x, T v)\n\t{\n\t\tfor(int i = x;i <= n;i += i & -i)\n\t\t\ta[i]\
    \ += v;\n\t\treturn;\n\t}\n\n\tT sum(int x)\n\t{\n\t\tT Ans = 0;\n\t\tfor(int\
    \ i = x;i;i -= i & -i)\n\t\t\tAns += a[i];\n\t\treturn Ans;\n\t}\n\n\tT Rangesum(int\
    \ l, int r) {return sum(r) - sum(l - 1);} // [l, r]\n};\n#line 2 \"io/Scanner_local.hpp\"\
    \n\nstruct Scanner\n{\n\ttemplate<typename T>\n\tvoid scan(T &x)\n\t{\n\t\tstd::cin\
    \ >> x;\n\t}\n\n\ttemplate<typename... T>\n\tvoid scan(T& ...x)\n\t{\n\t\t((std::cin\
    \ >> x), ...);\n\t}\n};\n#line 2 \"io/Printer_local.hpp\"\n\nstruct Printer\n\
    {\n\ttemplate<typename T>\n\tvoid print(T x)\n\t{\n\t\tstd::cout << x;\n\t}\n\n\
    \tvoid putchar(char x)\n\t{\n\t\tputchar(x);\n\t}\n\n\ttemplate<typename T>\n\t\
    void println(T x)\n\t{\n\t\tstd::cout << x << endl;\n\t}\n};\n#line 2 \"debug.hpp\"\
    \n\n#line 4 \"debug.hpp\"\n#include <type_traits>\n#line 8 \"debug.hpp\"\n\nnamespace\
    \ dbg {\n    // arithmetic\n    template <class T, std::enable_if_t<std::is_arithmetic_v<T>,\
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
    \ */\n#line 7 \"test/library_checker/static_range_sum.test.cpp\"\n\nusing i64\
    \ = long long;\nconstexpr int mmax = 5E5 + 10;\n\nScanner scanner;\nPrinter printer;\n\
    Fenwick<i64> fenwick(mmax);\n\nint main()\n{\n    i64 n, q;\n    scanner.scan(n,\
    \ q);\n    \n    for(int i = 1;i <= n;i++)\n    {\n            i64 x;\n      \
    \      scanner.scan(x);\n            fenwick.add(i, x);\n    }\n    for(int i\
    \ = 1;i <= q;i++)\n    {\n            i64 l, r;\n            scanner.scan(l, r);\n\
    \            printer.println(fenwick.Rangesum(++l, r));\n    }\n    debug(fenwick.Rangesum(1,\
    \ n));\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ \"head.hpp\"\n#include \"data_structure/1D-fenwick.hpp\"\n#include \"io/Scanner_local.hpp\"\
    \n#include \"io/Printer_local.hpp\"\n#include \"debug.hpp\"\n\nusing i64 = long\
    \ long;\nconstexpr int mmax = 5E5 + 10;\n\nScanner scanner;\nPrinter printer;\n\
    Fenwick<i64> fenwick(mmax);\n\nint main()\n{\n    i64 n, q;\n    scanner.scan(n,\
    \ q);\n    \n    for(int i = 1;i <= n;i++)\n    {\n            i64 x;\n      \
    \      scanner.scan(x);\n            fenwick.add(i, x);\n    }\n    for(int i\
    \ = 1;i <= q;i++)\n    {\n            i64 l, r;\n            scanner.scan(l, r);\n\
    \            printer.println(fenwick.Rangesum(++l, r));\n    }\n    debug(fenwick.Rangesum(1,\
    \ n));\n}"
  dependsOn:
  - head.hpp
  - data_structure/1D-fenwick.hpp
  - io/Scanner_local.hpp
  - io/Printer_local.hpp
  - debug.hpp
  isVerificationFile: true
  path: test/library_checker/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-08-13 21:39:22+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/static_range_sum.test.cpp
- /verify/test/library_checker/static_range_sum.test.cpp.html
title: test/library_checker/static_range_sum.test.cpp
---
