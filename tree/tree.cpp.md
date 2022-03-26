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
  bundledCode: "#line 1 \"tree/tree.cpp\"\nstruct tree{\n  struct node{\n    vector<int>\
    \ G,son,ancestor(30,-1);\n    int depth,parent;\n  };\n  vector<node> T;\n  vector<int>\
    \ fromleaf;\n  queue<int> que;\n  int n,root;\n\n  tree(int n):T(n),fromleaf(n),n(n),root(root){}\n\
    \n  void add_edge(int u,int v){\n    T[u].G.push_back(v);\n    T[v].G.push_back(u);\n\
    \  }\n\n  void have_root(int r){\n    root=r;\n    que.push(r);\n    int now=n;\n\
    \    while(que.size()){\n      int p=que.front();que.pop();\n      fromleaf[--now]=p;\n\
    \      for(int q:G[p]){\n        if(T[p].parent==q)continue;\n        T[p].son.push_back(q);\n\
    \        T[q].parent=T[q].ancestor[0]=p;\n        for(int j=1;j<30;j++)if(~T[q].ancestor[j-1])\n\
    \          T[q].ancestor[j]=T[ancestor[q][j-1]].ancestor[j-1];\n        T[q].depth=T[p].depth+1;\n\
    \        que.push(q);\n      }\n    }\n  }\n\n  int lca(int u,int v){\n    if(depth[u]>depth[v])swap(u,v);\n\
    \    int diff=depth[v]-depth[u],cnt=0;\n    while(diff){\n      if(diff&1)v=ancestor[v][cnt];\n\
    \      cnt++;\n      diff>>=1;\n    }\n    if(u==v)return u;\n    for(int k=28;k>=0;k--)\n\
    \      if(ancestor[u][k]!=ancestor[v][k])\n        u=ancestor[u][k],v=ancestor[v][k];\n\
    \    return ancestor[u][0];\n  }\n};\n"
  code: "struct tree{\n  struct node{\n    vector<int> G,son,ancestor(30,-1);\n  \
    \  int depth,parent;\n  };\n  vector<node> T;\n  vector<int> fromleaf;\n  queue<int>\
    \ que;\n  int n,root;\n\n  tree(int n):T(n),fromleaf(n),n(n),root(root){}\n\n\
    \  void add_edge(int u,int v){\n    T[u].G.push_back(v);\n    T[v].G.push_back(u);\n\
    \  }\n\n  void have_root(int r){\n    root=r;\n    que.push(r);\n    int now=n;\n\
    \    while(que.size()){\n      int p=que.front();que.pop();\n      fromleaf[--now]=p;\n\
    \      for(int q:G[p]){\n        if(T[p].parent==q)continue;\n        T[p].son.push_back(q);\n\
    \        T[q].parent=T[q].ancestor[0]=p;\n        for(int j=1;j<30;j++)if(~T[q].ancestor[j-1])\n\
    \          T[q].ancestor[j]=T[ancestor[q][j-1]].ancestor[j-1];\n        T[q].depth=T[p].depth+1;\n\
    \        que.push(q);\n      }\n    }\n  }\n\n  int lca(int u,int v){\n    if(depth[u]>depth[v])swap(u,v);\n\
    \    int diff=depth[v]-depth[u],cnt=0;\n    while(diff){\n      if(diff&1)v=ancestor[v][cnt];\n\
    \      cnt++;\n      diff>>=1;\n    }\n    if(u==v)return u;\n    for(int k=28;k>=0;k--)\n\
    \      if(ancestor[u][k]!=ancestor[v][k])\n        u=ancestor[u][k],v=ancestor[v][k];\n\
    \    return ancestor[u][0];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/tree.cpp
  requiredBy: []
  timestamp: '2022-03-26 14:25:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/tree.cpp
layout: document
redirect_from:
- /library/tree/tree.cpp
- /library/tree/tree.cpp.html
title: tree/tree.cpp
---
