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
  bundledCode: "#line 1 \"graph/Graph.cpp\"\nstruct Graph:vector<vector<int>>{\n \
    \ int n;\n  Graph()=default;\n  Graph(int n):n(n){resize(n);}\n  Graph(int n,int\
    \ m,bool directed=false,int index=1):n(n){\n    resize(n);\n    while(m--){\n\
    \      int from,to;cin>>from>>to;\n      if(directed)add_arc(from-index,to-index);\n\
    \      else add_edge(from-index,to-index);\n    }\n  }\n\n  vector<int>& operator[](int\
    \ v){return at(v);}\n\n  void add_arc(int from,int to){\n    at(from).push_back(to);\n\
    \  }\n\n  void add_edge(int u,int v){\n    add_arc(u,v);\n    add_arc(v,u);\n\
    \  }\n};\n"
  code: "struct Graph:vector<vector<int>>{\n  int n;\n  Graph()=default;\n  Graph(int\
    \ n):n(n){resize(n);}\n  Graph(int n,int m,bool directed=false,int index=1):n(n){\n\
    \    resize(n);\n    while(m--){\n      int from,to;cin>>from>>to;\n      if(directed)add_arc(from-index,to-index);\n\
    \      else add_edge(from-index,to-index);\n    }\n  }\n\n  vector<int>& operator[](int\
    \ v){return at(v);}\n\n  void add_arc(int from,int to){\n    at(from).push_back(to);\n\
    \  }\n\n  void add_edge(int u,int v){\n    add_arc(u,v);\n    add_arc(v,u);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/Graph.cpp
  requiredBy: []
  timestamp: '2022-09-06 21:44:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/Graph.cpp
layout: document
redirect_from:
- /library/graph/Graph.cpp
- /library/graph/Graph.cpp.html
title: graph/Graph.cpp
---
