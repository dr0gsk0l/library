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
  bundledCode: "#line 1 \"tree/tree.cpp\"\nstruct Tree : vector<vector<int>>{\n  Tree(int\
    \ n){\n    (*tree).resize(n);\n  }\n\n  void add_edge(int u,int v){\n    (*this)[u].push_back(v);\n\
    \    (*this)[v].push_back(u);\n  }\n};\n"
  code: "struct Tree : vector<vector<int>>{\n  Tree(int n){\n    (*tree).resize(n);\n\
    \  }\n\n  void add_edge(int u,int v){\n    (*this)[u].push_back(v);\n    (*this)[v].push_back(u);\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/tree.cpp
  requiredBy: []
  timestamp: '2022-03-29 14:51:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/tree.cpp
layout: document
redirect_from:
- /library/tree/tree.cpp
- /library/tree/tree.cpp.html
title: tree/tree.cpp
---
