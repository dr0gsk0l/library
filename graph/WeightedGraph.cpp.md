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
    \ Edge{\n  int to;\n  T cost;\n};\n \ntemplate<typename T>\nstruct WeightedGraph:vector<vector<Edge<T>>>{\n\
    \  WeightedGraph(){}\n  WeightedGraph(int n):{\n    (*this).resize(n);\n  }\n\
    \    \n  void add_edge(int from, int to, T cost){\n    (*this).push_back({to,cost});\n\
    \  }\n};\n"
  code: "template<typename T>\nstruct Edge{\n  int to;\n  T cost;\n};\n \ntemplate<typename\
    \ T>\nstruct WeightedGraph:vector<vector<Edge<T>>>{\n  WeightedGraph(){}\n  WeightedGraph(int\
    \ n):{\n    (*this).resize(n);\n  }\n    \n  void add_edge(int from, int to, T\
    \ cost){\n    (*this).push_back({to,cost});\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/WeightedGraph.cpp
  requiredBy: []
  timestamp: '2022-04-12 17:14:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/WeightedGraph.cpp
layout: document
redirect_from:
- /library/graph/WeightedGraph.cpp
- /library/graph/WeightedGraph.cpp.html
title: graph/WeightedGraph.cpp
---
