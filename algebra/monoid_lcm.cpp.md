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
  bundledCode: "#line 2 \"algebra/monoid_lcm.cpp\"\n\ntemplate<typename X>\nstruct\
    \ Monoid_Lcm{\n  using value_type = X;\n  static constexpr X op(const X &x, const\
    \ X &y) noexcept { return x/gcd(x,y)*y; }\n  static constexpr X unit() { return\
    \ 1; }\n  static constexpr bool commute = true;\n};\n"
  code: "#pragma once\n\ntemplate<typename X>\nstruct Monoid_Lcm{\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x/gcd(x,y)*y;\
    \ }\n  static constexpr X unit() { return 1; }\n  static constexpr bool commute\
    \ = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_lcm.cpp
  requiredBy: []
  timestamp: '2022-09-06 17:29:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_lcm.cpp
layout: document
redirect_from:
- /library/algebra/monoid_lcm.cpp
- /library/algebra/monoid_lcm.cpp.html
title: algebra/monoid_lcm.cpp
---
