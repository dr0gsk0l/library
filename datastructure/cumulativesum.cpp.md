---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/StaticRangeSum.test.cpp
    title: test/library-checker/DataStructure/StaticRangeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/cumulativesum.cpp\"\ntemplate<typename T>\n\
    struct CumulativeSum{\n  using U=conditional_t< is_same_v<T,int>,long long,T >;\n\
    \  vector<U> A;\n  CumulativeSum(const vector<T>&v){\n    A.resize(v.size()+1,0);\n\
    \    for(int i=0;i<v.size();i++)A[i+1]=A[i]+v[i];\n  }\n  void add(const T& a){\n\
    \    A.push_back(A.back()+a);\n  }\n  U sum(int l,int r){\n    return A[r]-A[l];\n\
    \  }\n};\n"
  code: "template<typename T>\nstruct CumulativeSum{\n  using U=conditional_t< is_same_v<T,int>,long\
    \ long,T >;\n  vector<U> A;\n  CumulativeSum(const vector<T>&v){\n    A.resize(v.size()+1,0);\n\
    \    for(int i=0;i<v.size();i++)A[i+1]=A[i]+v[i];\n  }\n  void add(const T& a){\n\
    \    A.push_back(A.back()+a);\n  }\n  U sum(int l,int r){\n    return A[r]-A[l];\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/cumulativesum.cpp
  requiredBy: []
  timestamp: '2022-09-07 11:58:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/StaticRangeSum.test.cpp
documentation_of: library/datastructure/cumulativesum.cpp
layout: document
redirect_from:
- /library/datastructure/cumulativesum.cpp
- /library/datastructure/cumulativesum.cpp.html
title: datastructure/cumulativesum.cpp
---
