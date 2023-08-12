---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/DSU.hpp
    title: data_structure/DSU.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
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
    https://judge.yosupo.jp/problem/unionfind\"\n#line 1 \"my_template.hpp\"\n#pragma\
    \ GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n#include<bits/stdc++.h>\n\
    #define ioclear std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);\n\
    #define endl '\\n'\n#define CLOCK 1e3 * clock() / CLOCKS_PER_SEC\n#line 2 \"data_structure/DSU.hpp\"\
    \n\ntemplate<typename T>\nstruct DSU\n{\n\tstd::vector<T> f, siz;\n\n\tDSU() {}\n\
    \tDSU(int n) {init(n);}\n\n\tvoid init(int n)\n\t{\n\t\tf.resize(n);\n\t\tstd::iota(f.begin(),\
    \ f.end(), 0);\n\t\tsiz.assign(n, 1);\n\t}\n\n\tT find(T x)\n\t{\n\t\twhile(x\
    \ != f[x])\n\t\t\tx = f[x] = f[f[x]];\n\t\treturn x;\n\t}\n\n\tbool same(T x,\
    \ T y) {return find(x) == find(y);}\n\n\tbool merge(T x, T y)\n\t{\n\t\tx = find(x);\n\
    \t\ty = find(y);\n\t\tif(x == y)\n\t\t\treturn false;\n\t\tsiz[x] += siz[y];\n\
    \t\tf[y] = x;\n\t\treturn true;\n\t}\n\n\tT size(T x) {return siz[find(x)];}\n\
    };\n#line 4 \"test/library_checker/DSU.test.cpp\"\n\nint main()\n{\n\t#ifdef ONLINE_JUDGE\n\
    \tioclear;\n\t#endif\n\n\tint n, q;\n\tstd::cin >> n >> q;\n\tDSU<int> dsu(n +\
    \ 10);\n\tfor(int i = 1;i <= q;i++)\n\t{\n\t\tint t, u, v;\n\t\tstd::cin >> t\
    \ >> u >> v;\n\t\tif(t == 0)\n\t\t\tdsu.merge(u, v);\n\t\telse\n\t\t\tstd::cout\
    \ << (dsu.same(u, v) ? 1 : 0) << endl;\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    my_template.hpp\"\n#include \"data_structure/DSU.hpp\"\n\nint main()\n{\n\t#ifdef\
    \ ONLINE_JUDGE\n\tioclear;\n\t#endif\n\n\tint n, q;\n\tstd::cin >> n >> q;\n\t\
    DSU<int> dsu(n + 10);\n\tfor(int i = 1;i <= q;i++)\n\t{\n\t\tint t, u, v;\n\t\t\
    std::cin >> t >> u >> v;\n\t\tif(t == 0)\n\t\t\tdsu.merge(u, v);\n\t\telse\n\t\
    \t\tstd::cout << (dsu.same(u, v) ? 1 : 0) << endl;\n\t}\n}"
  dependsOn:
  - my_template.hpp
  - data_structure/DSU.hpp
  isVerificationFile: true
  path: test/library_checker/DSU.test.cpp
  requiredBy: []
  timestamp: '2023-08-12 16:43:03+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/DSU.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/DSU.test.cpp
- /verify/test/library_checker/DSU.test.cpp.html
title: test/library_checker/DSU.test.cpp
---
