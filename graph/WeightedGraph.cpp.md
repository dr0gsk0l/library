---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/ShortestPath.test.cpp
    title: test/yosupo/ShortestPath.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/WeightedGraph.cpp\"\ntemplate<typename T>\nstruct\
    \ Edge{\n  int to;\n  T cost;\n};\n \ntemplate<typename T>\nstruct WeightedGraph:vector<vector<Edge<T>>>{\n\
    \  WeightedGraph(){}\n  WeightedGraph(int n){\n    (*this).resize(n);\n  }\n \
    \   \n  void add_edge(int from, int to, T cost){\n    (*this)[from].push_back({to,cost});\n\
    \  }\n};\n"
  code: "template<typename T>\nstruct Edge{\n  int to;\n  T cost;\n};\n \ntemplate<typename\
    \ T>\nstruct WeightedGraph:vector<vector<Edge<T>>>{\n  WeightedGraph(){}\n  WeightedGraph(int\
    \ n){\n    (*this).resize(n);\n  }\n    \n  void add_edge(int from, int to, T\
    \ cost){\n    (*this)[from].push_back({to,cost});\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/WeightedGraph.cpp
  requiredBy: []
  timestamp: '2022-05-23 06:42:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/ShortestPath.test.cpp
documentation_of: graph/WeightedGraph.cpp
layout: document
redirect_from:
- /library/graph/WeightedGraph.cpp
- /library/graph/WeightedGraph.cpp.html
title: graph/WeightedGraph.cpp
---
