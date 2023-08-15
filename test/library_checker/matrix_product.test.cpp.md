---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: head.hpp
    title: head.hpp
  - icon: ':question:'
    path: io/Printer.hpp
    title: io/Printer.hpp
  - icon: ':question:'
    path: io/Scanner.hpp
    title: io/Scanner.hpp
  - icon: ':x:'
    path: math/matrix.hpp
    title: math/matrix.hpp
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
    \ \"math/matrix.hpp\"\n\nusing i64 = long long;\n\ntemplate<typename T>\nstruct\
    \ matrix\n{\n\tint row, col;\n\ti64 P;\n\tstd::vector<std::vector<T>> m;\n\tmatrix(int\
    \ r, int c, int val, i64 p): row(r), col(c), m(row + 1, std::vector<T>(col + 1,\
    \ val)), P(p) {}\n    matrix(int r, int c, std::vector<std::vector<T>> _m, i64\
    \ p): row(r), col(c), m(_m), P(p) {}\n\t matrix operator *= (const matrix &rhs)\n\
    \t {\n\t \tassert(col == rhs.row);\n\t \tstd::vector<std::vector<T>> tmp(row +\
    \ 1, std::vector<T>(rhs.col + 1, 0));\n\t \tfor(int k = 1;k <= col;k++)\n\t \t\
    \tfor(int i = 1;i <= row;i++)\n\t \t\t\tfor(int j = 1;j <= rhs.col;j++)\n\t \t\
    \t\t\ttmp[i][j] = (tmp[i][j] + ((m[i][k] * rhs.m[k][j]) % P)) % P;\n\t \tm = tmp;\n\
    \t \treturn *this;\n\t }\n\tfriend matrix operator *(const matrix &lhs, const\
    \ matrix &rhs)\n\t{\n\t\tassert(lhs.col == rhs.row);\n        matrix res = lhs;\n\
    \        res *= rhs;\n        return res;\n\t}\n};\n\nmatrix<int> pow(int k, matrix<int>\
    \ m)\n{\n    k--;\n\tmatrix<int> Ans = m;\n\twhile(k)\n\t{\n\t\tif(k & 1)\n\t\t\
    \tAns *= m;\n\t\tm *= m;\n\t\tk >>= 1;\n\t}\n\treturn Ans;\n}\n#line 2 \"io/Scanner.hpp\"\
    \n\nclass Scanner\n{\npublic:\n\tScanner(std::FILE *f = stdin, std::size_t enough_buffer_size\
    \ = 1 << 25)\n\t\t: f_(f), buffer_(new char[enough_buffer_size + 32]), buffer_head_(buffer_),\n\
    \t\t  buffer_tail_(buffer_ + std::fread(buffer_, sizeof(char), enough_buffer_size\
    \ + 32, f_)) {*buffer_tail_ = '\\0';}\n\t~Scanner() {delete[] buffer_;}\n\t\n\t\
    template<typename T>\n\tstd::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T,\
    \ char> && std::is_signed_v<T>, bool>\n\tscan(T &x)\n\t{\n\t\tx = 0;\n\t\twhile(*buffer_head_\
    \ != '-' && std::isspace(*buffer_head_))\n\t\t\t++buffer_head_;\n\t\tbool is_neg\
    \ = *buffer_head_ == '-' && ++buffer_head_;\n\t\tchar *old_buffer_head = buffer_head_;\n\
    \t\tif(is_neg)\n\t\t\twhile(std::isdigit(*buffer_head_)) x = x * 10 - (*buffer_head_++\
    \ - '0');\n\t\telse\n\t\t\twhile(std::isdigit(*buffer_head_)) x = x * 10 + (*buffer_head_++\
    \ - '0');\n\t\treturn buffer_head_ != old_buffer_head;\n\t}  \n\n\ttemplate<typename...\
    \ T>\n\tbool scan(T &...x)\n\t{\n\t\treturn (... && scan(x));\n\t}\n\nprivate:\n\
    \tstd::FILE *f_;\n\tchar *buffer_, *buffer_head_, *buffer_tail_;\n};\n#line 2\
    \ \"io/Printer.hpp\"\n\nclass Printer\n{\npublic:\n\tPrinter(std::FILE *f = stdout,\
    \ std::size_t buffer_size = 100000)\n\t\t: f_(f), buffer_(new char[buffer_size\
    \ + 32]), buffer_head_(buffer_),\n\t\t  buffer_end_(buffer_ + buffer_size + 32),\
    \ stk_(new char[32]), top_(stk_) {}\n\t~Printer()\n\t{\n\t\tflush();\n\t\tdelete[]\
    \ stk_;\n\t\tdelete[] buffer_;\n\t}\n\n\tvoid flush()\n\t{\n\t\tstd::fwrite(buffer_,\
    \ buffer_head_ - buffer_, sizeof(char), f_);\n\t\tbuffer_head_ = buffer_;\n\t\
    }\n\n\tvoid putchar(char x)\n\t{\n\t\tif(buffer_end_ == buffer_head_)\n\t\t\t\
    flush();\n\t\t*buffer_head_++ = x;\n\t}\n\n\ttemplate<typename T>\n\tstd::enable_if_t<std::is_integral_v<T>\
    \ && !std::is_same_v<T, char> && std::is_signed_v<T>, void>\n\tprint(T x)\n\t\
    {\n\t\tif(x == 0)\n\t\t\treturn this->putchar('0');\n\t\tif(x < 0)\n\t\t{\n\t\t\
    \tputchar('-');\n\t\t\tdo\n\t\t\t{\n\t\t\t\tT y = x / 10;\n\t\t\t\t*top_++ = y\
    \ * 10 - x + '0';\n\t\t\t\tx = y;\n\t\t\t} while(x != 0);\n\t\t}\n\t\telse\n\t\
    \t{\n\t\t\tdo\n\t\t\t{\n\t\t\t\tT y = x / 10;\n\t\t\t\t*top_++ = x - y * 10 +\
    \ '0';\n\t\t\t\tx = y;\n\t\t\t} while(x != 0);\n\t\t}\n\t\tif(buffer_end_ - buffer_head_\
    \ < top_ - stk_)\n\t\t\tflush();\n\t\twhile(top_ != stk_) *buffer_head_++ = *--top_;\n\
    \t}\n\n\tvoid print(char x) {return this->putchar(x);}\n\n\ttemplate<typename\
    \ T>\n\tstd::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T, char> &&\
    \ std::is_unsigned_v<T>, void>\n\tprint(T x)\n\t{\n\t\tif(x == 0)\n\t\t\treturn\
    \ this->putchar('0');\n\t\tdo\n\t\t{\n\t\t\tT y = x / 10;\n\t\t\t*top_++ = x -\
    \ y * 10 + '0';\n\t\t\tx = y;\n\t\t} while(x != 0);\n\t\tif(buffer_end_ - buffer_head_\
    \ < top_ - stk_)\n\t\t\tflush();\n\t\twhile(top_ != stk_) *buffer_head_++ = *--top_;\n\
    \t}\n\n\ttemplate<typename... T>\n\tvoid print(T... x)\n\t{\n\t\treturn (...,\
    \ print(x));\n\t}\n\n\ttemplate<typename T>\n\tvoid println(T x)\n\t{\n\t\treturn\
    \ this->print(x), this->putchar('\\n');\n\t}\n\nprivate:\n\tstd::FILE *f_;\n\t\
    char *buffer_, *buffer_head_, *buffer_end_, *stk_, *top_;\n};\n#line 6 \"test/library_checker/matrix_product.test.cpp\"\
    \n\nScanner scanner;\nPrinter printer;\n\nint main()\n{\n\tint n, m, k;\n\tscanner.scan(n,\
    \ m, k);\n\tstd::vector<std::vector<i64>> a(n + 1, std::vector<i64>(m + 1)), b(m\
    \ + 1, std::vector<i64>(k + 1));\n\tfor(int i = 1;i <= n;i++)\n\t\tfor(int j =\
    \ 1;j <= m;j++)\n\t\t\tscanner.scan(a[i][j]);\n\tfor(int i = 1;i <= m;i++)\n\t\
    \tfor(int j = 1;j <= k;j++)\n\t\t\tscanner.scan(b[i][j]);\n\tmatrix<i64> A(n,\
    \ m, a, 998244353ll), B(m, k, b, 998244353ll);\n\tA *= B;\n\tfor(int i = 1;i <=\
    \ n;i++)\n\t{\n\t\tfor(int j = 1;j <= k;j++)\n\t\t\tprinter.print(A.m[i][j]),\
    \ printer.putchar(' ');\n\t\tprinter.putchar('\\n');\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\
    \ \"head.hpp\"\n#include \"math/matrix.hpp\"\n#include \"io/Scanner.hpp\"\n#include\
    \ \"io/Printer.hpp\"\n\nScanner scanner;\nPrinter printer;\n\nint main()\n{\n\t\
    int n, m, k;\n\tscanner.scan(n, m, k);\n\tstd::vector<std::vector<i64>> a(n +\
    \ 1, std::vector<i64>(m + 1)), b(m + 1, std::vector<i64>(k + 1));\n\tfor(int i\
    \ = 1;i <= n;i++)\n\t\tfor(int j = 1;j <= m;j++)\n\t\t\tscanner.scan(a[i][j]);\n\
    \tfor(int i = 1;i <= m;i++)\n\t\tfor(int j = 1;j <= k;j++)\n\t\t\tscanner.scan(b[i][j]);\n\
    \tmatrix<i64> A(n, m, a, 998244353ll), B(m, k, b, 998244353ll);\n\tA *= B;\n\t\
    for(int i = 1;i <= n;i++)\n\t{\n\t\tfor(int j = 1;j <= k;j++)\n\t\t\tprinter.print(A.m[i][j]),\
    \ printer.putchar(' ');\n\t\tprinter.putchar('\\n');\n\t}\n}"
  dependsOn:
  - head.hpp
  - math/matrix.hpp
  - io/Scanner.hpp
  - io/Printer.hpp
  isVerificationFile: true
  path: test/library_checker/matrix_product.test.cpp
  requiredBy: []
  timestamp: '2023-08-15 19:55:42+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/matrix_product.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/matrix_product.test.cpp
- /verify/test/library_checker/matrix_product.test.cpp.html
title: test/library_checker/matrix_product.test.cpp
---
