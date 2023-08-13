---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/DSU.test.cpp
    title: test/library_checker/DSU.test.cpp
  - icon: ':x:'
    path: test/library_checker/point_add_range_sum.test.cpp
    title: test/library_checker/point_add_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"io/Scanner.hpp\"\n\nclass Scanner\n{\npublic:\n\tScanner(std::FILE\
    \ *f = stdin, std::size_t enough_buffer_size = 1 << 25)\n\t\t: f_(f), buffer_(new\
    \ char[enough_buffer_size + 32]), buffer_head_(buffer_),\n\t\t  buffer_tail_(buffer_\
    \ + std::fread(buffer_, sizeof(char), enough_buffer_size + 32, f_)) {*buffer_tail_\
    \ = '\\0';}\n\t~Scanner() {delete[] buffer_;}\n\t\n\ttemplate<typename T>\n\t\
    std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T, char> && std::is_signed_v<T>,\
    \ bool>\n\tscan(T &x)\n\t{\n\t\tx = 0;\n\t\twhile(*buffer_head_ != '-' && std::isspace(*buffer_head_))\n\
    \t\t\t++buffer_head_;\n\t\tbool is_neg = *buffer_head_ == '-' && ++buffer_head_;\n\
    \t\tchar *old_buffer_head = buffer_head_;\n\t\tif(is_neg)\n\t\t\twhile(std::isdigit(*buffer_head_))\
    \ x = x * 10 - (*buffer_head_++ - '0');\n\t\telse\n\t\t\twhile(std::isdigit(*buffer_head_))\
    \ x = x * 10 + (*buffer_head_++ - '0');\n\t\treturn buffer_head_ != old_buffer_head;\n\
    \t}  \n\n\ttemplate<typename... T>\n\tbool scan(T &...x)\n\t{\n\t\treturn (...\
    \ && scan(x));\n\t}\n\nprivate:\n\tstd::FILE *f_;\n\tchar *buffer_, *buffer_head_,\
    \ *buffer_tail_;\n};\n"
  code: "#pragma once\n\nclass Scanner\n{\npublic:\n\tScanner(std::FILE *f = stdin,\
    \ std::size_t enough_buffer_size = 1 << 25)\n\t\t: f_(f), buffer_(new char[enough_buffer_size\
    \ + 32]), buffer_head_(buffer_),\n\t\t  buffer_tail_(buffer_ + std::fread(buffer_,\
    \ sizeof(char), enough_buffer_size + 32, f_)) {*buffer_tail_ = '\\0';}\n\t~Scanner()\
    \ {delete[] buffer_;}\n\t\n\ttemplate<typename T>\n\tstd::enable_if_t<std::is_integral_v<T>\
    \ && !std::is_same_v<T, char> && std::is_signed_v<T>, bool>\n\tscan(T &x)\n\t\
    {\n\t\tx = 0;\n\t\twhile(*buffer_head_ != '-' && std::isspace(*buffer_head_))\n\
    \t\t\t++buffer_head_;\n\t\tbool is_neg = *buffer_head_ == '-' && ++buffer_head_;\n\
    \t\tchar *old_buffer_head = buffer_head_;\n\t\tif(is_neg)\n\t\t\twhile(std::isdigit(*buffer_head_))\
    \ x = x * 10 - (*buffer_head_++ - '0');\n\t\telse\n\t\t\twhile(std::isdigit(*buffer_head_))\
    \ x = x * 10 + (*buffer_head_++ - '0');\n\t\treturn buffer_head_ != old_buffer_head;\n\
    \t}  \n\n\ttemplate<typename... T>\n\tbool scan(T &...x)\n\t{\n\t\treturn (...\
    \ && scan(x));\n\t}\n\nprivate:\n\tstd::FILE *f_;\n\tchar *buffer_, *buffer_head_,\
    \ *buffer_tail_;\n};"
  dependsOn: []
  isVerificationFile: false
  path: io/Scanner.hpp
  requiredBy: []
  timestamp: '2023-08-13 18:04:56+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/point_add_range_sum.test.cpp
  - test/library_checker/DSU.test.cpp
documentation_of: io/Scanner.hpp
layout: document
redirect_from:
- /library/io/Scanner.hpp
- /library/io/Scanner.hpp.html
title: io/Scanner.hpp
---
