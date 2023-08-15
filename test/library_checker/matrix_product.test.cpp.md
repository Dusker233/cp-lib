---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: head.hpp
    title: head.hpp
  - icon: ':x:'
    path: math/matrix.hpp
    title: math/matrix.hpp
  - icon: ':x:'
    path: math/modint.hpp
    title: math/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/library_checker/matrix_product.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#line 1 \"head.hpp\"\
    \n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n#include<bits/stdc++.h>\n\
    #define ioclear std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);\n\
    #define endl '\\n'\n#define CLOCK 1e3 * clock() / CLOCKS_PER_SEC\n\n\n#line 2\
    \ \"math/modint.hpp\"\n\nconstexpr int P = 998244353;\nusing i64 = long long;\n\
    \n// assume -P <= x < 2P\nint norm(int x) {\n    if (x < 0) {\n        x += P;\n\
    \    }\n    if (x >= P) {\n        x -= P;\n    }\n    return x;\n}\ntemplate<class\
    \ T>\nT power(T a, i64 b) {\n    T res = 1;\n    for (; b; b /= 2, a *= a) {\n\
    \        if (b % 2) {\n            res *= a;\n        }\n    }\n    return res;\n\
    }\nstruct Z {\n    int x;\n    Z(int x = 0) : x(norm(x)) {}\n    Z(i64 x) : x(norm(x\
    \ % P)) {}\n    int val() const {\n        return x;\n    }\n    Z operator-()\
    \ const {\n        return Z(norm(P - x));\n    }\n    Z inv() const {\n      \
    \  assert(x != 0);\n        return power(*this, P - 2);\n    }\n    Z &operator*=(const\
    \ Z &rhs) {\n        x = i64(x) * rhs.x % P;\n        return *this;\n    }\n \
    \   Z &operator+=(const Z &rhs) {\n        x = norm(x + rhs.x);\n        return\
    \ *this;\n    }\n    Z &operator-=(const Z &rhs) {\n        x = norm(x - rhs.x);\n\
    \        return *this;\n    }\n    Z &operator/=(const Z &rhs) {\n        return\
    \ *this *= rhs.inv();\n    }\n    friend Z operator*(const Z &lhs, const Z &rhs)\
    \ {\n        Z res = lhs;\n        res *= rhs;\n        return res;\n    }\n \
    \   friend Z operator+(const Z &lhs, const Z &rhs) {\n        Z res = lhs;\n \
    \       res += rhs;\n        return res;\n    }\n    friend Z operator-(const\
    \ Z &lhs, const Z &rhs) {\n        Z res = lhs;\n        res -= rhs;\n       \
    \ return res;\n    }\n    friend Z operator/(const Z &lhs, const Z &rhs) {\n \
    \       Z res = lhs;\n        res /= rhs;\n        return res;\n    }\n    friend\
    \ std::istream &operator>>(std::istream &is, Z &a) {\n        i64 v;\n       \
    \ is >> v;\n        a = Z(v);\n        return is;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Z &a) {\n        return os << a.val();\n\
    \    }\n};\n#line 2 \"math/matrix.hpp\"\n\ntemplate<typename T>\nstruct matrix\n\
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
    \ m;\n\t\tm *= m;\n\t\tk >>= 1;\n\t}\n\treturn Ans;\n}\n#line 5 \"test/library_checker/matrix_product.test.cpp\"\
    \n\nint main()\n{\n\tioclear;\n\tint n, m, k;\n\tstd::cin >> n >> m >> k;\n\t\
    std::vector<std::vector<Z>> a(n + 1, std::vector<Z>(m + 1)), b(m + 1, std::vector<Z>(k\
    \ + 1));\n\tfor(int i = 1;i <= n;i++)\n\t\tfor(int j = 1;j <= m;j++)\n\t\t\tstd::cin\
    \ >> a[i][j];\n\tfor(int i = 1;i <= m;i++)\n\t\tfor(int j = 1;j <= k;j++)\n\t\t\
    \tstd::cin >> b[i][j];\n\tmatrix<Z> A(n, m, a), B(m, k, b);\n\tA *= B;\n\tfor(int\
    \ i = 1;i <= n;i++)\n\t\tfor(int j = 1;j <= k;j++)\n\t\t\tstd::cout << A.m[i][j]\
    \ << \" \\n\"[j == k];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\
    \ \"head.hpp\"\n#include \"math/modint.hpp\"\n#include \"math/matrix.hpp\"\n\n\
    int main()\n{\n\tioclear;\n\tint n, m, k;\n\tstd::cin >> n >> m >> k;\n\tstd::vector<std::vector<Z>>\
    \ a(n + 1, std::vector<Z>(m + 1)), b(m + 1, std::vector<Z>(k + 1));\n\tfor(int\
    \ i = 1;i <= n;i++)\n\t\tfor(int j = 1;j <= m;j++)\n\t\t\tstd::cin >> a[i][j];\n\
    \tfor(int i = 1;i <= m;i++)\n\t\tfor(int j = 1;j <= k;j++)\n\t\t\tstd::cin >>\
    \ b[i][j];\n\tmatrix<Z> A(n, m, a), B(m, k, b);\n\tA *= B;\n\tfor(int i = 1;i\
    \ <= n;i++)\n\t\tfor(int j = 1;j <= k;j++)\n\t\t\tstd::cout << A.m[i][j] << \"\
    \ \\n\"[j == k];\n}"
  dependsOn:
  - head.hpp
  - math/modint.hpp
  - math/matrix.hpp
  isVerificationFile: true
  path: test/library_checker/matrix_product.test.cpp
  requiredBy: []
  timestamp: '2023-08-15 19:36:42+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/matrix_product.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/matrix_product.test.cpp
- /verify/test/library_checker/matrix_product.test.cpp.html
title: test/library_checker/matrix_product.test.cpp
---
