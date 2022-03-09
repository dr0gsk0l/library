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
    _deprecated_at_docs: UnionFind.md
    links: []
  bundledCode: "#line 1 \"unionfind.cpp\"\nstruct UnionFind{\n  int n,num;\n  vector<int>\
    \ r,p;\n  UnionFind(){}\n  UnionFind(int n):num(n),r(n,1),p(n,0){iota(p.begin(),p.end(),0);}\n\
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
  path: unionfind.cpp
  requiredBy: []
  timestamp: '2022-03-09 14:48:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unionfind.test.cpp
documentation_of: unionfind.cpp
layout: document
title: UnionFind
---

## UnionFind

- `UnionFind uf(int n)`
  - $n$頂点$0$辺の無向グラフを作成
  - $O(n)$
- `void merge(int u,int v)`
  - 辺$(u,v)$を足す
  - $0\leq u,v \lt n$
  - ならし $O(\alpha(n))$
- `int leader(int v)`
  - 頂点$v$の属する連結成分の代表元を返す
  - ならし $O(\alpha(n))$
- `bool same(int u,int v)`
  - 頂点$u,v$が連結かどうかを返す
  - ならし $O(\alpha(n))$
- `int size(int v)`
  - 頂点$v$の属する連結成分のサイズを返す
- `int count()`
  - 連結成分の個数を返す