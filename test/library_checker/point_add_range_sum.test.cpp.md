---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/1D-fenwick.hpp
    title: data_structure/1D-fenwick.hpp
  - icon: ':question:'
    path: head.hpp
    title: head.hpp
  - icon: ':heavy_check_mark:'
    path: io/Printer.hpp
    title: io/Printer.hpp
  - icon: ':heavy_check_mark:'
    path: io/Scanner.hpp
    title: io/Scanner.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/library_checker/point_add_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#line 1 \"\
    head.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n#include<bits/stdc++.h>\n#define ioclear std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);\n\
    #define endl '\\n'\n#define CLOCK 1e3 * clock() / CLOCKS_PER_SEC\n\n\n#line 2\
    \ \"data_structure/1D-fenwick.hpp\"\n\ntemplate<typename T>\nstruct Fenwick\n\
    {\n\tconst int n;\n\tstd::vector<T> a;\n\n\tFenwick(int _n) : n(_n), a(_n) {}\n\
    \n\tvoid add(int x, T v)\n\t{\n\t\tfor(int i = x;i <= n;i += i & -i)\n\t\t\ta[i]\
    \ += v;\n\t\treturn;\n\t}\n\n\tT sum(int x)\n\t{\n\t\tT Ans = 0;\n\t\tfor(int\
    \ i = x;i;i -= i & -i)\n\t\t\tAns += a[i];\n\t\treturn Ans;\n\t}\n\n\tT Rangesum(int\
    \ l, int r) {return sum(r) - sum(l - 1);} // [l, r]\n};\n#line 2 \"io/Scanner.hpp\"\
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
    char *buffer_, *buffer_head_, *buffer_end_, *stk_, *top_;\n};\n#line 6 \"test/library_checker/point_add_range_sum.test.cpp\"\
    \n\nusing i64 = long long;\nconstexpr int mmax = 5E5 + 10;\n\nScanner scanner;\n\
    Printer printer;\nFenwick<i64> fenwick(mmax);\n\nint main()\n{\n    i64 n, q;\n\
    \    scanner.scan(n, q);\n    \n    for(int i = 1;i <= n;i++)\n    {\n       \
    \     i64 x;\n            scanner.scan(x);\n            fenwick.add(i, x);\n \
    \   }\n    for(int i = 1;i <= q;i++)\n    {\n            i64 op, l, r;\n     \
    \       scanner.scan(op, l, r);\n            if(op == 0)\n                   \
    \ fenwick.add(++l, r);\n            else\n                    printer.print(fenwick.Rangesum(++l,\
    \ r)), printer.putchar('\\n');\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"head.hpp\"\n#include \"data_structure/1D-fenwick.hpp\"\n#include \"\
    io/Scanner.hpp\"\n#include \"io/Printer.hpp\"\n\nusing i64 = long long;\nconstexpr\
    \ int mmax = 5E5 + 10;\n\nScanner scanner;\nPrinter printer;\nFenwick<i64> fenwick(mmax);\n\
    \nint main()\n{\n    i64 n, q;\n    scanner.scan(n, q);\n    \n    for(int i =\
    \ 1;i <= n;i++)\n    {\n            i64 x;\n            scanner.scan(x);\n   \
    \         fenwick.add(i, x);\n    }\n    for(int i = 1;i <= q;i++)\n    {\n  \
    \          i64 op, l, r;\n            scanner.scan(op, l, r);\n            if(op\
    \ == 0)\n                    fenwick.add(++l, r);\n            else\n        \
    \            printer.print(fenwick.Rangesum(++l, r)), printer.putchar('\\n');\n\
    \    }\n}"
  dependsOn:
  - head.hpp
  - data_structure/1D-fenwick.hpp
  - io/Scanner.hpp
  - io/Printer.hpp
  isVerificationFile: true
  path: test/library_checker/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-08-13 21:39:22+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/point_add_range_sum.test.cpp
- /verify/test/library_checker/point_add_range_sum.test.cpp.html
title: test/library_checker/point_add_range_sum.test.cpp
---
