---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/dsu.cpp
    title: datastructure/dsu.cpp
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
  bundledCode: "#line 1 \"test/library-checker/DataStructure/unionfind.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"datastructure/dsu.cpp\"\nstruct dsu{\n  int\
    \ n,num;\n  vector<int> sz,parent;\n  dsu()=default;\n  dsu(int n):n(n),num(n),sz(n,1),parent(n,0){iota(parent.begin(),parent.end(),0);}\n\
    \  \n  int leader(int x){ \n    assert(0<=x and x<n);\n    return (x==parent[x]?\
    \ x : parent[x]=leader(parent[x])); \n  }\n  \n  bool same(int x,int y){\n   \
    \ assert(0<=x and x<n and 0<=y and y<n);\n    return leader(x)==leader(y); \n\
    \  }\n  \n  bool merge(int x,int y){\n    assert(0<=x and x<n and 0<=y and y<n);\n\
    \    x=leader(x);y=leader(y);\n    if(x==y)return false;\n    if(sz[x]<sz[y])swap(x,y);\n\
    \    sz[x]+=sz[y];\n    parent[y]=x;\n    num--;\n    return true;\n  }\n  \n\
    \  int size(const int x){\n    assert(0<=x and x<n);\n    return sz[leader(x)];\n\
    \  }\n  \n  int count()const{\n    return num;\n  }\n};\n#line 6 \"test/library-checker/DataStructure/unionfind.test.cpp\"\
    \n\nint main() {\n  int n,q;cin>>n>>q;\n  dsu uf(n);\n  while(q--){\n    int t,u,v;cin>>t>>u>>v;\n\
    \    if(t)cout<<uf.same(u,v)<<\"\\n\";\n    else uf.merge(u,v);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"datastructure/dsu.cpp\"\n\nint main() {\n \
    \ int n,q;cin>>n>>q;\n  dsu uf(n);\n  while(q--){\n    int t,u,v;cin>>t>>u>>v;\n\
    \    if(t)cout<<uf.same(u,v)<<\"\\n\";\n    else uf.merge(u,v);\n  }\n}"
  dependsOn:
  - datastructure/dsu.cpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/unionfind.test.cpp
  requiredBy: []
  timestamp: '2022-09-06 17:50:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/unionfind.test.cpp
- /verify/test/library-checker/DataStructure/unionfind.test.cpp.html
title: test/library-checker/DataStructure/unionfind.test.cpp
---
