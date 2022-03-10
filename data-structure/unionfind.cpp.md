---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: UnionFind.md
    links: []
  bundledCode: "#line 1 \"data-structure/unionfind.cpp\"\nstruct UnionFind{\n  int\
    \ n,num;\n  vector<int> r,p;\n  UnionFind(){}\n  UnionFind(int n):num(n),r(n,1),p(n,0){iota(p.begin(),p.end(),0);}\n\
    \  \n  int leader(int x){\n    return (x==p[x]?x:p[x]=leader(p[x]));\n  }\n  \n\
    \  bool same(int x,int y){\n    return leader(x)==leader(y);\n  }\n  \n  bool\
    \ merge(int x,int y){\n    x=leader(x);y=leader(y);\n    if(x==y)return false;\n\
    \    if(r[x]<r[y])swap(x,y);\n    r[x]+=r[y];\n    p[y]=x;\n    num--;\n    return\
    \ true;\n  }\n  \n  int size(const int x){\n    return r[leader(x)];\n  }\n  \n\
    \  int count() const{\n    return num;\n  }\n};\n\n/**\n* @docs UnionFind.md\n\
    */\n"
  code: "struct UnionFind{\n  int n,num;\n  vector<int> r,p;\n  UnionFind(){}\n  UnionFind(int\
    \ n):num(n),r(n,1),p(n,0){iota(p.begin(),p.end(),0);}\n  \n  int leader(int x){\n\
    \    return (x==p[x]?x:p[x]=leader(p[x]));\n  }\n  \n  bool same(int x,int y){\n\
    \    return leader(x)==leader(y);\n  }\n  \n  bool merge(int x,int y){\n    x=leader(x);y=leader(y);\n\
    \    if(x==y)return false;\n    if(r[x]<r[y])swap(x,y);\n    r[x]+=r[y];\n   \
    \ p[y]=x;\n    num--;\n    return true;\n  }\n  \n  int size(const int x){\n \
    \   return r[leader(x)];\n  }\n  \n  int count() const{\n    return num;\n  }\n\
    };\n\n/**\n* @docs UnionFind.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/unionfind.cpp
  requiredBy: []
  timestamp: '2022-03-10 13:03:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/unionfind.cpp
layout: document
redirect_from:
- /library/data-structure/unionfind.cpp
- /library/data-structure/unionfind.cpp.html
title: data-structure/unionfind.cpp
---
