---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/static_range_sum.test.cpp
    title: test/library_checker/static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"io/Printer_local.hpp\"\n\nstruct Printer\n{\n\ttemplate<typename\
    \ T>\n\tvoid print(T x)\n\t{\n\t\tstd::cout << x;\n\t}\n\n\tvoid putchar(char\
    \ x)\n\t{\n\t\tputchar(x);\n\t}\n\n\ttemplate<typename T>\n\tvoid println(T x)\n\
    \t{\n\t\tstd::cout << x << endl;\n\t}\n};\n"
  code: "#pragma once\n\nstruct Printer\n{\n\ttemplate<typename T>\n\tvoid print(T\
    \ x)\n\t{\n\t\tstd::cout << x;\n\t}\n\n\tvoid putchar(char x)\n\t{\n\t\tputchar(x);\n\
    \t}\n\n\ttemplate<typename T>\n\tvoid println(T x)\n\t{\n\t\tstd::cout << x <<\
    \ endl;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: io/Printer_local.hpp
  requiredBy: []
  timestamp: '2023-08-13 21:39:22+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/static_range_sum.test.cpp
documentation_of: io/Printer_local.hpp
layout: document
redirect_from:
- /library/io/Printer_local.hpp
- /library/io/Printer_local.hpp.html
title: io/Printer_local.hpp
---
