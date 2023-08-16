---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/matrix_product.test.cpp
    title: test/library_checker/matrix_product.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix.hpp\"\n\nusing i64 = long long;\n\ntemplate<typename\
    \ T>\nstruct matrix\n{\n\tint row, col;\n\ti64 P;\n\tstd::vector<std::vector<T>>\
    \ m;\n\tmatrix(int r, int c, int val, i64 p): row(r), col(c), m(row + 1, std::vector<T>(col\
    \ + 1, val)), P(p) {}\n    matrix(int r, int c, std::vector<std::vector<T>> _m,\
    \ i64 p): row(r), col(c), m(_m), P(p) {}\n\t matrix operator *= (const matrix\
    \ &rhs)\n\t {\n\t \tassert(col == rhs.row);\n\t \tstd::vector<std::vector<T>>\
    \ tmp(row + 1, std::vector<T>(rhs.col + 1, 0));\n\t \tfor(int k = 1;k <= col;k++)\n\
    \t \t\tfor(int i = 1;i <= row;i++)\n\t \t\t\tfor(int j = 1;j <= rhs.col;j++)\n\
    \t \t\t\t\ttmp[i][j] = (tmp[i][j] + ((m[i][k] * rhs.m[k][j]))) % P;\n\t \tm =\
    \ tmp;\n\t \treturn *this;\n\t }\n\tfriend matrix operator *(const matrix &lhs,\
    \ const matrix &rhs)\n\t{\n\t\tassert(lhs.col == rhs.row);\n        matrix res\
    \ = lhs;\n        res *= rhs;\n        return res;\n\t}\n};\n\nmatrix<int> pow(int\
    \ k, matrix<int> m)\n{\n    k--;\n\tmatrix<int> Ans = m;\n\twhile(k)\n\t{\n\t\t\
    if(k & 1)\n\t\t\tAns *= m;\n\t\tm *= m;\n\t\tk >>= 1;\n\t}\n\treturn Ans;\n}\n"
  code: "#pragma once\n\nusing i64 = long long;\n\ntemplate<typename T>\nstruct matrix\n\
    {\n\tint row, col;\n\ti64 P;\n\tstd::vector<std::vector<T>> m;\n\tmatrix(int r,\
    \ int c, int val, i64 p): row(r), col(c), m(row + 1, std::vector<T>(col + 1, val)),\
    \ P(p) {}\n    matrix(int r, int c, std::vector<std::vector<T>> _m, i64 p): row(r),\
    \ col(c), m(_m), P(p) {}\n\t matrix operator *= (const matrix &rhs)\n\t {\n\t\
    \ \tassert(col == rhs.row);\n\t \tstd::vector<std::vector<T>> tmp(row + 1, std::vector<T>(rhs.col\
    \ + 1, 0));\n\t \tfor(int k = 1;k <= col;k++)\n\t \t\tfor(int i = 1;i <= row;i++)\n\
    \t \t\t\tfor(int j = 1;j <= rhs.col;j++)\n\t \t\t\t\ttmp[i][j] = (tmp[i][j] +\
    \ ((m[i][k] * rhs.m[k][j]))) % P;\n\t \tm = tmp;\n\t \treturn *this;\n\t }\n\t\
    friend matrix operator *(const matrix &lhs, const matrix &rhs)\n\t{\n\t\tassert(lhs.col\
    \ == rhs.row);\n        matrix res = lhs;\n        res *= rhs;\n        return\
    \ res;\n\t}\n};\n\nmatrix<int> pow(int k, matrix<int> m)\n{\n    k--;\n\tmatrix<int>\
    \ Ans = m;\n\twhile(k)\n\t{\n\t\tif(k & 1)\n\t\t\tAns *= m;\n\t\tm *= m;\n\t\t\
    k >>= 1;\n\t}\n\treturn Ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2023-08-16 10:22:37+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/matrix_product.test.cpp
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: math/matrix.hpp
---
