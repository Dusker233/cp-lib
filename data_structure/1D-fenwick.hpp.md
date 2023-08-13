---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/point_add_range_sum.test.cpp
    title: test/library_checker/point_add_range_sum.test.cpp
  - icon: ':x:'
    path: test/library_checker/static_range_sum.test.cpp
    title: test/library_checker/static_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/1D-fenwick.hpp\"\n\ntemplate<typename T>\n\
    struct Fenwick\n{\n\tconst int n;\n\tstd::vector<T> a;\n\n\tFenwick(int _n) :\
    \ n(_n), a(_n) {}\n\n\tvoid add(int x, T v)\n\t{\n\t\tfor(int i = x;i <= n;i +=\
    \ i & -i)\n\t\t\ta[i] += v;\n\t\treturn;\n\t}\n\n\tT sum(int x)\n\t{\n\t\tT Ans\
    \ = 0;\n\t\tfor(int i = x;i;i -= i & -i)\n\t\t\tAns += a[i];\n\t\treturn Ans;\n\
    \t}\n\n\tT Rangesum(int l, int r) {return sum(r) - sum(l - 1);} // [l, r]\n};\n"
  code: "#pragma once\n\ntemplate<typename T>\nstruct Fenwick\n{\n\tconst int n;\n\
    \tstd::vector<T> a;\n\n\tFenwick(int _n) : n(_n), a(_n) {}\n\n\tvoid add(int x,\
    \ T v)\n\t{\n\t\tfor(int i = x;i <= n;i += i & -i)\n\t\t\ta[i] += v;\n\t\treturn;\n\
    \t}\n\n\tT sum(int x)\n\t{\n\t\tT Ans = 0;\n\t\tfor(int i = x;i;i -= i & -i)\n\
    \t\t\tAns += a[i];\n\t\treturn Ans;\n\t}\n\n\tT Rangesum(int l, int r) {return\
    \ sum(r) - sum(l - 1);} // [l, r]\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/1D-fenwick.hpp
  requiredBy: []
  timestamp: '2023-08-13 19:08:09+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/point_add_range_sum.test.cpp
  - test/library_checker/static_range_sum.test.cpp
documentation_of: data_structure/1D-fenwick.hpp
layout: document
redirect_from:
- /library/data_structure/1D-fenwick.hpp
- /library/data_structure/1D-fenwick.hpp.html
title: data_structure/1D-fenwick.hpp
---
