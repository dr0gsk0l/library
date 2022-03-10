---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind.cpp
    title: UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/unionfind.cpp\"\
    \nstruct UnionFind{\n  int n,num;\n  vector<int> r,p;\n  UnionFind(){}\n  UnionFind(int\
    \ n):num(n),r(n,1),p(n,0){iota(p.begin(),p.end(),0);}\n  \n  int leader(int x){\n\
    \    return (x==p[x]?x:p[x]=leader(p[x]));\n  }\n  \n  bool same(int x,int y){\n\
    \    return leader(x)==leader(y);\n  }\n  \n  bool merge(int x,int y){\n    x=leader(x);y=leader(y);\n\
    \    if(x==y)return false;\n    if(r[x]<r[y])swap(x,y);\n    r[x]+=r[y];\n   \
    \ p[y]=x;\n    num--;\n    return true;\n  }\n  \n  int size(const int x){\n \
    \   return r[leader(x)];\n  }\n  \n  int count() const{\n    return num;\n  }\n\
    };\n\n/**\n* @docs //docs/data-structure/unionfind.md\n*/\n#line 6 \"test/unionfind.test.cpp\"\
    \n\n\nint main() {\n  int n,q;cin>>n>>q;\n  UnionFind uf(n);\n  while(q--){\n\
    \    int t,u,v;cin>>t>>u>>v;\n    if(t)cout<<uf.same(u,v)<<\"\\n\";\n    else\
    \ uf.merge(u,v);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../data-structure/unionfind.cpp\"\n\n\nint\
    \ main() {\n  int n,q;cin>>n>>q;\n  UnionFind uf(n);\n  while(q--){\n    int t,u,v;cin>>t>>u>>v;\n\
    \    if(t)cout<<uf.same(u,v)<<\"\\n\";\n    else uf.merge(u,v);\n  }\n}\n"
  dependsOn:
  - data-structure/unionfind.cpp
  isVerificationFile: true
  path: test/unionfind.test.cpp
  requiredBy: []
  timestamp: '2022-03-10 13:48:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/unionfind.test.cpp
- /verify/test/unionfind.test.cpp.html
title: test/unionfind.test.cpp
---
