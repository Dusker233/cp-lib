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
  bundledCode: "#line 2 \"io/Scanner_local.hpp\"\n\nstruct Scanner\n{\n\ttemplate<typename\
    \ T>\n\tvoid scan(T &x)\n\t{\n\t\tstd::cin >> x;\n\t}\n\n\ttemplate<typename...\
    \ T>\n\tvoid scan(T& ...x)\n\t{\n\t\t((std::cin >> x), ...);\n\t}\n};\n"
  code: "#pragma once\n\nstruct Scanner\n{\n\ttemplate<typename T>\n\tvoid scan(T\
    \ &x)\n\t{\n\t\tstd::cin >> x;\n\t}\n\n\ttemplate<typename... T>\n\tvoid scan(T&\
    \ ...x)\n\t{\n\t\t((std::cin >> x), ...);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: io/Scanner_local.hpp
  requiredBy: []
  timestamp: '2023-08-13 21:39:22+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/static_range_sum.test.cpp
documentation_of: io/Scanner_local.hpp
layout: document
redirect_from:
- /library/io/Scanner_local.hpp
- /library/io/Scanner_local.hpp.html
title: io/Scanner_local.hpp
---
