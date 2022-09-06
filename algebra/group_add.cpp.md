---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/group_add.cpp\"\n\ntemplate<typename X>\nstruct\
    \ Group_Add {\n  using value_type = X;\n  static constexpr X op(const X &x, const\
    \ X &y) noexcept { return x + y; }\n  static constexpr X inverse(const X &x) noexcept\
    \ { return -x; }\n  static constexpr X power(const X &x, long long n) noexcept\
    \ { return X(n) * x; }\n  static constexpr X unit() { return X(0); }\n  static\
    \ constexpr bool commute = true;\n};\n"
  code: "#pragma once\n\ntemplate<typename X>\nstruct Group_Add {\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, long long n) noexcept { return X(n) * x; }\n \
    \ static constexpr X unit() { return X(0); }\n  static constexpr bool commute\
    \ = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/group_add.cpp
  requiredBy: []
  timestamp: '2022-09-06 17:29:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/group_add.cpp
layout: document
redirect_from:
- /library/algebra/group_add.cpp
- /library/algebra/group_add.cpp.html
title: algebra/group_add.cpp
---
