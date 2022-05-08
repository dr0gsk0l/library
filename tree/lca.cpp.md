---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.test.cpp
    title: test/yosupo/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/lca.cpp\"\nclass LCA{\n  Tree T;\n  int n,root;\n \
    \ vector<vector<int>> ancestor;\n  vector<int> depth;\n\n  void dfs(int idx,int\
    \ pre){\n    for(const int&p:T[idx])if(p!=pre){\n      depth[p]=depth[idx]+1;\n\
    \      ancestor[p][0]=idx;\n      for(int i=1;i<30;i++)\n        ancestor[p][i]=ancestor[ancestor[p][i-1]][i-1];\n\
    \      dfs(p,idx);\n    }\n  }\npublic:\n  LCA(const Tree&T,int root=0):T(T),root(root){\n\
    \    n=T.size();\n    ancestor.resize(n,vector<int>(30,root));\n    depth.resize(n,0);\n\
    \    dfs(root,-1);\n  }\n\n  int lca(int u,int v){\n    if(depth[u]>depth[v])swap(u,v);\n\
    \    for(int diff=depth[v]-depth[u],cnt=0;diff;cnt++,diff>>=1)\n      if(diff&1)v=ancestor[v][cnt];\n\
    \    if(u==v)return u;\n    for(int k=29;k>=0;k--)\n      if(ancestor[u][k]!=ancestor[v][k])\n\
    \        u=ancestor[u][k],v=ancestor[v][k];\n    return ancestor[u][0];\n  }\n\
    };\n"
  code: "class LCA{\n  Tree T;\n  int n,root;\n  vector<vector<int>> ancestor;\n \
    \ vector<int> depth;\n\n  void dfs(int idx,int pre){\n    for(const int&p:T[idx])if(p!=pre){\n\
    \      depth[p]=depth[idx]+1;\n      ancestor[p][0]=idx;\n      for(int i=1;i<30;i++)\n\
    \        ancestor[p][i]=ancestor[ancestor[p][i-1]][i-1];\n      dfs(p,idx);\n\
    \    }\n  }\npublic:\n  LCA(const Tree&T,int root=0):T(T),root(root){\n    n=T.size();\n\
    \    ancestor.resize(n,vector<int>(30,root));\n    depth.resize(n,0);\n    dfs(root,-1);\n\
    \  }\n\n  int lca(int u,int v){\n    if(depth[u]>depth[v])swap(u,v);\n    for(int\
    \ diff=depth[v]-depth[u],cnt=0;diff;cnt++,diff>>=1)\n      if(diff&1)v=ancestor[v][cnt];\n\
    \    if(u==v)return u;\n    for(int k=29;k>=0;k--)\n      if(ancestor[u][k]!=ancestor[v][k])\n\
    \        u=ancestor[u][k],v=ancestor[v][k];\n    return ancestor[u][0];\n  }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/lca.cpp
  requiredBy: []
  timestamp: '2022-05-07 20:45:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/lca.test.cpp
documentation_of: tree/lca.cpp
layout: document
redirect_from:
- /library/tree/lca.cpp
- /library/tree/lca.cpp.html
title: tree/lca.cpp
---
