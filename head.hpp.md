---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/DSU.test.cpp
    title: test/library_checker/DSU.test.cpp
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
  bundledCode: '#line 1 "head.hpp"

    #pragma GCC optimize("Ofast")

    #pragma GCC optimize("unroll-loops")

    #include<bits/stdc++.h>

    #define ioclear std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

    #define endl ''\n''

    #define CLOCK 1e3 * clock() / CLOCKS_PER_SEC

    '
  code: '#pragma GCC optimize("Ofast")

    #pragma GCC optimize("unroll-loops")

    #include<bits/stdc++.h>

    #define ioclear std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

    #define endl ''\n''

    #define CLOCK 1e3 * clock() / CLOCKS_PER_SEC

    '
  dependsOn: []
  isVerificationFile: false
  path: head.hpp
  requiredBy: []
  timestamp: '2023-08-13 18:01:43+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/point_add_range_sum.test.cpp
  - test/library_checker/DSU.test.cpp
  - test/library_checker/static_range_sum.test.cpp
documentation_of: head.hpp
layout: document
redirect_from:
- /library/head.hpp
- /library/head.hpp.html
title: head.hpp
---
