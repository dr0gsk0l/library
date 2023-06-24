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
  bundledCode: "#line 1 \"algebra/group_linear.cpp\"\n// op(f,g) = f(g(x))\ntemplate<typename\
    \ K>\nstruct Group_Affine{\n  using F = pair<K, K>;\n  using value_type = F;\n\
    \  static constexpr F op(const F &f, const F &g) noexcept {\n    return F({f.first\
    \ * g.first, f.first * g.second + f.second});\n  }\n  static constexpr F inverse(const\
    \ F &x) {\n    auto [a, b] = x; assert(a!=0);\n    a = K(1) / a;\n    return {a,\
    \ a * (-b)};\n  }\n  /*\n  static constexpr F power(const F& f,long long n) noexcept\
    \ {\n    if(a==1)return {1,n*b};\n    K an=power(a,n);\n    return {an,b*((1-an)/(1-a))};\n\
    \  }\n  */\n  static constexpr F unit() { return {K(1), K(0)}; }\n  static constexpr\
    \ bool commute = false;\n\n  static constexpr K eval(const F &f, K x) noexcept\
    \ {\n    return f.first * x + f.second;\n  }\n};\n"
  code: "// op(f,g) = f(g(x))\ntemplate<typename K>\nstruct Group_Affine{\n  using\
    \ F = pair<K, K>;\n  using value_type = F;\n  static constexpr F op(const F &f,\
    \ const F &g) noexcept {\n    return F({f.first * g.first, f.first * g.second\
    \ + f.second});\n  }\n  static constexpr F inverse(const F &x) {\n    auto [a,\
    \ b] = x; assert(a!=0);\n    a = K(1) / a;\n    return {a, a * (-b)};\n  }\n \
    \ /*\n  static constexpr F power(const F& f,long long n) noexcept {\n    if(a==1)return\
    \ {1,n*b};\n    K an=power(a,n);\n    return {an,b*((1-an)/(1-a))};\n  }\n  */\n\
    \  static constexpr F unit() { return {K(1), K(0)}; }\n  static constexpr bool\
    \ commute = false;\n\n  static constexpr K eval(const F &f, K x) noexcept {\n\
    \    return f.first * x + f.second;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/group_linear.cpp
  requiredBy: []
  timestamp: '2022-09-06 17:29:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/group_linear.cpp
layout: document
redirect_from:
- /library/algebra/group_linear.cpp
- /library/algebra/group_linear.cpp.html
title: algebra/group_linear.cpp
---
