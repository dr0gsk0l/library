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
  bundledCode: "#line 1 \"algebra/monoid_min.cpp\"\ntemplate<typename X>\nstruct Monoid_Min{\n\
    \  using value_type = X;\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return min(x,y); }\n  static constexpr X unit() { return numeric_limits<X>::max()/2;\
    \ }\n  static constexpr bool commute = true;\n};\n"
  code: "template<typename X>\nstruct Monoid_Min{\n  using value_type = X;\n  static\
    \ constexpr X op(const X &x, const X &y) noexcept { return min(x,y); }\n  static\
    \ constexpr X unit() { return numeric_limits<X>::max()/2; }\n  static constexpr\
    \ bool commute = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_min.cpp
  requiredBy: []
  timestamp: '2022-09-07 12:14:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_min.cpp
layout: document
redirect_from:
- /library/algebra/monoid_min.cpp
- /library/algebra/monoid_min.cpp.html
title: algebra/monoid_min.cpp
---
