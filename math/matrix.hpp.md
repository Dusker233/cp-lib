---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix.hpp\"\n\ntemplate<typename T>\nstruct matrix\n\
    {\n\tint row, col;\n\tstd::vector<std::vector<T>> m;\n\tmatrix(int r, int c, int\
    \ val): row(r), col(c), m(row + 1, std::vector<T>(col + 1, val)) {}\n    matrix(int\
    \ r, int c, std::vector<std::vector<T>> _m): row(r), col(c), m(_m) {}\n\t matrix\
    \ operator *= (const matrix &rhs)\n\t {\n\t \tassert(col == rhs.row);\n\t \tstd::vector<std::vector<T>>\
    \ tmp(row + 1, std::vector<T>(rhs.col + 1, 0));\n\t \tfor(int k = 1;k <= col;k++)\n\
    \t \t\tfor(int i = 1;i <= row;i++)\n\t \t\t\tfor(int j = 1;j <= rhs.col;j++)\n\
    \t \t\t\t\ttmp[i][j] += m[i][k] * rhs.m[k][j];\n\t \tm = tmp;\n\t \treturn *this;\n\
    \t }\n\tfriend matrix operator *(const matrix &lhs, const matrix &rhs)\n\t{\n\t\
    \tassert(lhs.col == rhs.row);\n        matrix res = lhs;\n        res *= rhs;\n\
    \        return res;\n\t}\n};\n\nmatrix<int> pow(int k, matrix<int> m)\n{\n  \
    \  k--;\n\tmatrix<int> Ans = m;\n\twhile(k)\n\t{\n\t\tif(k & 1)\n\t\t\tAns *=\
    \ m;\n\t\tm *= m;\n\t\tk >>= 1;\n\t}\n\treturn Ans;\n}\n"
  code: "#pragma once\n\ntemplate<typename T>\nstruct matrix\n{\n\tint row, col;\n\
    \tstd::vector<std::vector<T>> m;\n\tmatrix(int r, int c, int val): row(r), col(c),\
    \ m(row + 1, std::vector<T>(col + 1, val)) {}\n    matrix(int r, int c, std::vector<std::vector<T>>\
    \ _m): row(r), col(c), m(_m) {}\n\t matrix operator *= (const matrix &rhs)\n\t\
    \ {\n\t \tassert(col == rhs.row);\n\t \tstd::vector<std::vector<T>> tmp(row +\
    \ 1, std::vector<T>(rhs.col + 1, 0));\n\t \tfor(int k = 1;k <= col;k++)\n\t \t\
    \tfor(int i = 1;i <= row;i++)\n\t \t\t\tfor(int j = 1;j <= rhs.col;j++)\n\t \t\
    \t\t\ttmp[i][j] += m[i][k] * rhs.m[k][j];\n\t \tm = tmp;\n\t \treturn *this;\n\
    \t }\n\tfriend matrix operator *(const matrix &lhs, const matrix &rhs)\n\t{\n\t\
    \tassert(lhs.col == rhs.row);\n        matrix res = lhs;\n        res *= rhs;\n\
    \        return res;\n\t}\n};\n\nmatrix<int> pow(int k, matrix<int> m)\n{\n  \
    \  k--;\n\tmatrix<int> Ans = m;\n\twhile(k)\n\t{\n\t\tif(k & 1)\n\t\t\tAns *=\
    \ m;\n\t\tm *= m;\n\t\tk >>= 1;\n\t}\n\treturn Ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2023-08-15 19:34:51+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: math/matrix.hpp
---
