---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 289, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n                        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/subprocess.py\"\
    , line 466, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/subprocess.py\"\
    , line 571, in run\n    raise CalledProcessError(retcode, process.args,\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/cp-lib/cp-lib', '-fpreprocessed',\
    \ '-dD', '-E', '/home/runner/work/cp-lib/cp-lib/test/library_checker/matrix_product.test.cpp']'\
    \ returned non-zero exit status 1.\n"
  code: "#PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include \"\
    head.hpp\"\n#include \"math/modint.hpp\"\n#include \"math/matrix.hpp\"\n\nint\
    \ main()\n{\n\tioclear;\n\tint n, m, k;\n\tstd::cin >> n >> m >> k;\n\tstd::vector<std::vector<Z>>\
    \ a(n + 1, std::vector<Z>(m + 1)), b(m + 1, std::vector<Z>(k + 1));\n\tfor(int\
    \ i = 1;i <= n;i++)\n\t\tfor(int j = 1;j <= m;j++)\n\t\t\tstd::cin >> a[i][j];\n\
    \tfor(int i = 1;i <= m;i++)\n\t\tfor(int j = 1;j <= k;j++)\n\t\t\tstd::cin >>\
    \ b[i][j];\n\tmatrix<Z> A(n, m, a), B(m, k, b);\n\tA *= B;\n\tfor(int i = 1;i\
    \ <= n;i++)\n\t\tfor(int j = 1;j <= k;j++)\n\t\t\tstd::cout << A.m[i][j] << \"\
    \ \\n\"[j == k];\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/matrix_product.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/matrix_product.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/matrix_product.test.cpp
- /verify/test/library_checker/matrix_product.test.cpp.html
title: test/library_checker/matrix_product.test.cpp
---
