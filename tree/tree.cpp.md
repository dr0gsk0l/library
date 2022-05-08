---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.test.cpp
    title: test/yosupo/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/tree.cpp\"\nstruct Tree : vector<vector<int>>{\n  Tree(int\
    \ n){\n    (*this).resize(n);\n  }\n\n  void add_edge(int u,int v){\n    (*this)[u].push_back(v);\n\
    \    (*this)[v].push_back(u);\n  }\n};\n"
  code: "struct Tree : vector<vector<int>>{\n  Tree(int n){\n    (*this).resize(n);\n\
    \  }\n\n  void add_edge(int u,int v){\n    (*this)[u].push_back(v);\n    (*this)[v].push_back(u);\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/tree.cpp
  requiredBy: []
  timestamp: '2022-05-07 18:50:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/lca.test.cpp
documentation_of: tree/tree.cpp
layout: document
redirect_from:
- /library/tree/tree.cpp
- /library/tree/tree.cpp.html
title: tree/tree.cpp
---
