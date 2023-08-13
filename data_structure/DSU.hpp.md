---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/DSU.test.cpp
    title: test/library_checker/DSU.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/DSU.hpp\"\n\ntemplate<typename T>\nstruct\
    \ DSU\n{\n\tstd::vector<T> f, siz;\n\n\tDSU() {}\n\tDSU(int n) {init(n);}\n\n\t\
    void init(int n)\n\t{\n\t\tf.resize(n);\n\t\tstd::iota(f.begin(), f.end(), 0);\n\
    \t\tsiz.assign(n, 1);\n\t}\n\n\tT find(T x)\n\t{\n\t\twhile(x != f[x])\n\t\t\t\
    x = f[x] = f[f[x]];\n\t\treturn x;\n\t}\n\n\tbool same(T x, T y) {return find(x)\
    \ == find(y);}\n\n\tbool merge(T x, T y)\n\t{\n\t\tx = find(x);\n\t\ty = find(y);\n\
    \t\tif(x == y)\n\t\t\treturn false;\n\t\tsiz[x] += siz[y];\n\t\tf[y] = x;\n\t\t\
    return true;\n\t}\n\n\tT size(T x) {return siz[find(x)];}\n};\n"
  code: "#pragma once\n\ntemplate<typename T>\nstruct DSU\n{\n\tstd::vector<T> f,\
    \ siz;\n\n\tDSU() {}\n\tDSU(int n) {init(n);}\n\n\tvoid init(int n)\n\t{\n\t\t\
    f.resize(n);\n\t\tstd::iota(f.begin(), f.end(), 0);\n\t\tsiz.assign(n, 1);\n\t\
    }\n\n\tT find(T x)\n\t{\n\t\twhile(x != f[x])\n\t\t\tx = f[x] = f[f[x]];\n\t\t\
    return x;\n\t}\n\n\tbool same(T x, T y) {return find(x) == find(y);}\n\n\tbool\
    \ merge(T x, T y)\n\t{\n\t\tx = find(x);\n\t\ty = find(y);\n\t\tif(x == y)\n\t\
    \t\treturn false;\n\t\tsiz[x] += siz[y];\n\t\tf[y] = x;\n\t\treturn true;\n\t\
    }\n\n\tT size(T x) {return siz[find(x)];}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/DSU.hpp
  requiredBy: []
  timestamp: '2023-08-12 16:43:03+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/DSU.test.cpp
documentation_of: data_structure/DSU.hpp
layout: document
redirect_from:
- /library/data_structure/DSU.hpp
- /library/data_structure/DSU.hpp.html
title: data_structure/DSU.hpp
---
