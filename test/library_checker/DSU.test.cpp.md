---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/DSU.hpp
    title: data_structure/DSU.hpp
  - icon: ':question:'
    path: head.hpp
    title: head.hpp
  - icon: ':question:'
    path: io/Printer.hpp
    title: io/Printer.hpp
  - icon: ':question:'
    path: io/Scanner.hpp
    title: io/Scanner.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/library_checker/DSU.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/unionfind\"\n#line 1 \"head.hpp\"\n#pragma GCC\
    \ optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n#include<bits/stdc++.h>\n\
    #define ioclear std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);\n\
    #define endl '\\n'\n#define CLOCK 1e3 * clock() / CLOCKS_PER_SEC\n\n\n#line 2\
    \ \"data_structure/DSU.hpp\"\n\ntemplate<typename T>\nstruct DSU\n{\n\tstd::vector<T>\
    \ f, siz;\n\n\tDSU() {}\n\tDSU(int n) {init(n);}\n\n\tvoid init(int n)\n\t{\n\t\
    \tf.resize(n);\n\t\tstd::iota(f.begin(), f.end(), 0);\n\t\tsiz.assign(n, 1);\n\
    \t}\n\n\tT find(T x)\n\t{\n\t\twhile(x != f[x])\n\t\t\tx = f[x] = f[f[x]];\n\t\
    \treturn x;\n\t}\n\n\tbool same(T x, T y) {return find(x) == find(y);}\n\n\tbool\
    \ merge(T x, T y)\n\t{\n\t\tx = find(x);\n\t\ty = find(y);\n\t\tif(x == y)\n\t\
    \t\treturn false;\n\t\tsiz[x] += siz[y];\n\t\tf[y] = x;\n\t\treturn true;\n\t\
    }\n\n\tT size(T x) {return siz[find(x)];}\n};\n#line 2 \"io/Scanner.hpp\"\n\n\
    class Scanner\n{\npublic:\n\tScanner(std::FILE *f = stdin, std::size_t enough_buffer_size\
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
    char *buffer_, *buffer_head_, *buffer_end_, *stk_, *top_;\n};\n#line 6 \"test/library_checker/DSU.test.cpp\"\
    \n\nScanner scanner;\nPrinter printer;\n\nint main()\n{\n\t#ifdef ONLINE_JUDGE\n\
    \tioclear;\n\t#endif\n\n\tint n, q;\n\tscanner.scan(n, q);\n\tDSU<int> dsu(n +\
    \ 10);\n\tfor(int i = 1;i <= q;i++)\n\t{\n\t\tint t, u, v;\n\t\tscanner.scan(t,\
    \ u, v);\n\t\tif(t == 0)\n\t\t\tdsu.merge(u, v);\n\t\telse\n\t\t\tprinter.print(dsu.same(u,\
    \ v)), printer.putchar('\\n');\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    head.hpp\"\n#include \"data_structure/DSU.hpp\"\n#include \"io/Scanner.hpp\"\n\
    #include \"io/Printer.hpp\"\n\nScanner scanner;\nPrinter printer;\n\nint main()\n\
    {\n\t#ifdef ONLINE_JUDGE\n\tioclear;\n\t#endif\n\n\tint n, q;\n\tscanner.scan(n,\
    \ q);\n\tDSU<int> dsu(n + 10);\n\tfor(int i = 1;i <= q;i++)\n\t{\n\t\tint t, u,\
    \ v;\n\t\tscanner.scan(t, u, v);\n\t\tif(t == 0)\n\t\t\tdsu.merge(u, v);\n\t\t\
    else\n\t\t\tprinter.print(dsu.same(u, v)), printer.putchar('\\n');\n\t}\n}"
  dependsOn:
  - head.hpp
  - data_structure/DSU.hpp
  - io/Scanner.hpp
  - io/Printer.hpp
  isVerificationFile: true
  path: test/library_checker/DSU.test.cpp
  requiredBy: []
  timestamp: '2023-08-13 21:39:22+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/DSU.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/DSU.test.cpp
- /verify/test/library_checker/DSU.test.cpp.html
title: test/library_checker/DSU.test.cpp
---
