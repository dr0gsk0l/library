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
  bundledCode: "#line 1 \"graph/WeightedGraph.cpp\"\ntemplate<typename T>\nstruct\
    \ Edge{\n  int to;\n  T cost;\n};\n \ntemplate<typename T>\nstruct WeightedGraph{\n\
    \  int n;\n  vector<vector<Edge<T>>> g;\n    \n  WeightedGraph(){}\n  WeightedGraph(int\
    \ n):n(n),g(n){}\n    \n  void add_edge(int from, int to, T cost){\n    g[from].push_back({to,cost});\n\
    \  }\n};\n"
  code: "template<typename T>\nstruct Edge{\n  int to;\n  T cost;\n};\n \ntemplate<typename\
    \ T>\nstruct WeightedGraph{\n  int n;\n  vector<vector<Edge<T>>> g;\n    \n  WeightedGraph(){}\n\
    \  WeightedGraph(int n):n(n),g(n){}\n    \n  void add_edge(int from, int to, T\
    \ cost){\n    g[from].push_back({to,cost});\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/WeightedGraph.cpp
  requiredBy: []
  timestamp: '2022-02-08 12:19:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/WeightedGraph.cpp
layout: document
redirect_from:
- /library/graph/WeightedGraph.cpp
- /library/graph/WeightedGraph.cpp.html
title: graph/WeightedGraph.cpp
---
