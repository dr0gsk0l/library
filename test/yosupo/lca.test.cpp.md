---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/lca.cpp
    title: tree/lca.cpp
  - icon: ':heavy_check_mark:'
    path: tree/tree.cpp
    title: tree/tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo/lca.test.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\
    #line 1 \"tree/tree.cpp\"\nstruct Tree : vector<vector<int>>{\n  Tree(int n){\n\
    \    (*this).resize(n);\n  }\n\n  void add_edge(int u,int v){\n    (*this)[u].push_back(v);\n\
    \    (*this)[v].push_back(u);\n  }\n};\n#line 1 \"tree/lca.cpp\"\nclass LCA{\n\
    \  Tree T;\n  int n,root;\n  vector<vector<int>> ancestor;\n  vector<int> depth;\n\
    \n  void dfs(int idx,int pre){\n    for(const int&p:T[idx])if(p!=pre){\n     \
    \ depth[p]=depth[idx]+1;\n      ancestor[p][0]=idx;\n      for(int i=1;i<30;i++)\n\
    \        ancestor[p][i]=ancestor[ancestor[p][i-1]][i-1];\n      dfs(p,idx);\n\
    \    }\n  }\npublic:\n  LCA(const Tree&T,int root=0):T(T),root(root){\n    n=T.size();\n\
    \    ancestor.resize(n,vector<int>(30,root));\n    depth.resize(n,0);\n    dfs(root,-1);\n\
    \  }\n\n  int lca(int u,int v){\n    if(depth[u]>depth[v])swap(u,v);\n    for(int\
    \ diff=depth[v]-depth[u],cnt=0;diff;cnt++,diff>>=1)\n      if(diff&1)v=ancestor[v][cnt];\n\
    \    if(u==v)return u;\n    for(int k=29;k>=0;k--)\n      if(ancestor[u][k]!=ancestor[v][k])\n\
    \        u=ancestor[u][k],v=ancestor[v][k];\n    return ancestor[u][0];\n  }\n\
    };\n#line 7 \"test/yosupo/lca.test.cpp\"\n\nint main(){\n  int n,q;cin>>n>>q;\n\
    \  Tree t(n);\n  for(int i=1;i<n;i++){\n    int p;cin>>p;\n    t.add_edge(i,p);\n\
    \  }\n  LCA lca(t,0);\n  while(q--){\n    int u,v;cin>>u>>v;\n    cout<<lca.lca(u,v)<<\"\
    \\n\";\n  }\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n#include \"../../tree/tree.cpp\"\n#include \"../../tree/lca.cpp\"\n\nint main(){\n\
    \  int n,q;cin>>n>>q;\n  Tree t(n);\n  for(int i=1;i<n;i++){\n    int p;cin>>p;\n\
    \    t.add_edge(i,p);\n  }\n  LCA lca(t,0);\n  while(q--){\n    int u,v;cin>>u>>v;\n\
    \    cout<<lca.lca(u,v)<<\"\\n\";\n  }\n}"
  dependsOn:
  - tree/tree.cpp
  - tree/lca.cpp
  isVerificationFile: true
  path: test/yosupo/lca.test.cpp
  requiredBy: []
  timestamp: '2022-05-07 20:45:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/lca.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/lca.test.cpp
- /verify/test/yosupo/lca.test.cpp.html
title: test/yosupo/lca.test.cpp
---
