---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unionfind.test.cpp
    title: test/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"unionfind.cpp\"\nstruct UnionFind{\n  int n,num;\n  vector<int>\
    \ r,p;\n  UnionFind(){}\n  UnionFind(int n):num(n),r(n,1),p(n,0){iota(p.begin(),p.end(),0);}\n\
    \  \n  int find(int x){\n    return (x==p[x]?x:p[x]=find(p[x]));\n  }\n  \n  bool\
    \ same(int x,int y){\n    return find(x)==find(y);\n  }\n  \n  bool merge(int\
    \ x,int y){\n    x=find(x);y=find(y);\n    if(x==y)return false;\n    if(r[x]<r[y])swap(x,y);\n\
    \    r[x]+=r[y];\n    p[y]=x;\n    num--;\n    return true;\n  }\n  \n  int size(const\
    \ int x){\n    return r[find(x)];\n  }\n  \n  int count() const{\n    return num;\n\
    \  }\n};\n"
  code: "struct UnionFind{\n  int n,num;\n  vector<int> r,p;\n  UnionFind(){}\n  UnionFind(int\
    \ n):num(n),r(n,1),p(n,0){iota(p.begin(),p.end(),0);}\n  \n  int find(int x){\n\
    \    return (x==p[x]?x:p[x]=find(p[x]));\n  }\n  \n  bool same(int x,int y){\n\
    \    return find(x)==find(y);\n  }\n  \n  bool merge(int x,int y){\n    x=find(x);y=find(y);\n\
    \    if(x==y)return false;\n    if(r[x]<r[y])swap(x,y);\n    r[x]+=r[y];\n   \
    \ p[y]=x;\n    num--;\n    return true;\n  }\n  \n  int size(const int x){\n \
    \   return r[find(x)];\n  }\n  \n  int count() const{\n    return num;\n  }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: unionfind.cpp
  requiredBy: []
  timestamp: '2022-03-09 14:07:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unionfind.test.cpp
documentation_of: unionfind.cpp
layout: document
redirect_from:
- /library/unionfind.cpp
- /library/unionfind.cpp.html
title: unionfind.cpp
---
