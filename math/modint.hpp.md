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
  bundledCode: "#line 2 \"math/modint.hpp\"\n\nconstexpr int P = 998244353;\nusing\
    \ i64 = long long;\n\n// assume -P <= x < 2P\nint norm(int x) {\n    if (x < 0)\
    \ {\n        x += P;\n    }\n    if (x >= P) {\n        x -= P;\n    }\n    return\
    \ x;\n}\ntemplate<class T>\nT power(T a, i64 b) {\n    T res = 1;\n    for (;\
    \ b; b /= 2, a *= a) {\n        if (b % 2) {\n            res *= a;\n        }\n\
    \    }\n    return res;\n}\nstruct Z {\n    int x;\n    Z(int x = 0) : x(norm(x))\
    \ {}\n    Z(i64 x) : x(norm(x % P)) {}\n    int val() const {\n        return\
    \ x;\n    }\n    Z operator-() const {\n        return Z(norm(P - x));\n    }\n\
    \    Z inv() const {\n        assert(x != 0);\n        return power(*this, P -\
    \ 2);\n    }\n    Z &operator*=(const Z &rhs) {\n        x = i64(x) * rhs.x %\
    \ P;\n        return *this;\n    }\n    Z &operator+=(const Z &rhs) {\n      \
    \  x = norm(x + rhs.x);\n        return *this;\n    }\n    Z &operator-=(const\
    \ Z &rhs) {\n        x = norm(x - rhs.x);\n        return *this;\n    }\n    Z\
    \ &operator/=(const Z &rhs) {\n        return *this *= rhs.inv();\n    }\n   \
    \ friend Z operator*(const Z &lhs, const Z &rhs) {\n        Z res = lhs;\n   \
    \     res *= rhs;\n        return res;\n    }\n    friend Z operator+(const Z\
    \ &lhs, const Z &rhs) {\n        Z res = lhs;\n        res += rhs;\n        return\
    \ res;\n    }\n    friend Z operator-(const Z &lhs, const Z &rhs) {\n        Z\
    \ res = lhs;\n        res -= rhs;\n        return res;\n    }\n    friend Z operator/(const\
    \ Z &lhs, const Z &rhs) {\n        Z res = lhs;\n        res /= rhs;\n       \
    \ return res;\n    }\n    friend std::istream &operator>>(std::istream &is, Z\
    \ &a) {\n        i64 v;\n        is >> v;\n        a = Z(v);\n        return is;\n\
    \    }\n    friend std::ostream &operator<<(std::ostream &os, const Z &a) {\n\
    \        return os << a.val();\n    }\n};\n"
  code: "#pragma once\n\nconstexpr int P = 998244353;\nusing i64 = long long;\n\n\
    // assume -P <= x < 2P\nint norm(int x) {\n    if (x < 0) {\n        x += P;\n\
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
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy: []
  timestamp: '2023-08-15 19:34:51+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modint.hpp
layout: document
redirect_from:
- /library/math/modint.hpp
- /library/math/modint.hpp.html
title: math/modint.hpp
---
