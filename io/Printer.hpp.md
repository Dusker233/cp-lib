---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/DSU.test.cpp
    title: test/library_checker/DSU.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix_product.test.cpp
    title: test/library_checker/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/point_add_range_sum.test.cpp
    title: test/library_checker/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1750.test.cpp
    title: test/yukicoder/1750.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"io/Printer.hpp\"\n\nclass Printer\n{\npublic:\n\tPrinter(std::FILE\
    \ *f = stdout, std::size_t buffer_size = 100000)\n\t\t: f_(f), buffer_(new char[buffer_size\
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
    char *buffer_, *buffer_head_, *buffer_end_, *stk_, *top_;\n};\n"
  code: "#pragma once\n\nclass Printer\n{\npublic:\n\tPrinter(std::FILE *f = stdout,\
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
    char *buffer_, *buffer_head_, *buffer_end_, *stk_, *top_;\n};"
  dependsOn: []
  isVerificationFile: false
  path: io/Printer.hpp
  requiredBy: []
  timestamp: '2023-08-13 19:20:30+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1750.test.cpp
  - test/library_checker/point_add_range_sum.test.cpp
  - test/library_checker/DSU.test.cpp
  - test/library_checker/matrix_product.test.cpp
documentation_of: io/Printer.hpp
layout: document
redirect_from:
- /library/io/Printer.hpp
- /library/io/Printer.hpp.html
title: io/Printer.hpp
---
