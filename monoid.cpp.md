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
  bundledCode: "#line 1 \"monoid.cpp\"\ntemplate<class T,T (*op)(T, T)>\nstruct AsMonoid\
    \ {\n  std::optional<T> v;\n  AsMonoid():v(){}\n  AsMonoid(T x):v(std::move(x)){}\n\
    \  friend AsMonoid operator+(AsMonoid l, AsMonoid r){\n    if(!l.v)return r;\n\
    \    if(!r.v)return l;\n    return AsMonoid(op(*l.v,*r.v));\n  }\n};\n\n/*\n\u4F7F\
    \u7528\u4F8B1\nstatic constexpr auto f=[](int l, int r){\n  return std::min(l,\
    \ r);\n};\nusing MinInt = AsMonoid<int, f>;\n*/\n"
  code: "template<class T,T (*op)(T, T)>\nstruct AsMonoid {\n  std::optional<T> v;\n\
    \  AsMonoid():v(){}\n  AsMonoid(T x):v(std::move(x)){}\n  friend AsMonoid operator+(AsMonoid\
    \ l, AsMonoid r){\n    if(!l.v)return r;\n    if(!r.v)return l;\n    return AsMonoid(op(*l.v,*r.v));\n\
    \  }\n};\n\n/*\n\u4F7F\u7528\u4F8B1\nstatic constexpr auto f=[](int l, int r){\n\
    \  return std::min(l, r);\n};\nusing MinInt = AsMonoid<int, f>;\n*/"
  dependsOn: []
  isVerificationFile: false
  path: monoid.cpp
  requiredBy: []
  timestamp: '2022-02-07 17:36:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: monoid.cpp
layout: document
redirect_from:
- /library/monoid.cpp
- /library/monoid.cpp.html
title: monoid.cpp
---
