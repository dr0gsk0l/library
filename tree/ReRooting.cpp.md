---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc222/submissions/26517686
  bundledCode: "#line 1 \"tree/ReRooting.cpp\"\n//key_t:\u8FBA\u56FA\u6709\u306E\u60C5\
    \u5831\u3000\u9802\u70B9\u56FA\u6709\u306E\u60C5\u5831\u306F\u30E9\u30E0\u30C0\
    \u306E\u65B9\u3067\u30AD\u30E3\u30D7\u30C1\u30E3\u3055\u305B\u308B\n//sum_t:\u8A08\
    \u7B97\u7D50\u679C\ntemplate<typename key_t,typename sum_t=key_t>\nstruct ReRooting{\n\
    \  struct Edge {\n    int from,to;\n    key_t cost;\n    sum_t dp1,dp2;\n    //dp1:\u90E8\
    \u5206\u6728\u306E\u5185\u5BB9\n    //dp2:e=g[idx][i]\u306E\u6642\u3001g[idx][0,i)\u306E\
    dp1\u306E\u7D2F\u7A4D\u304C\u5165\u308B\n  };\n  using F=function<sum_t(sum_t,sum_t)>;\n\
    \  using G=function<sum_t(sum_t,Edge)>;\n \n  vector<vector<Edge>> g;\n  const\
    \ F merge;\n  const G score;\n  const sum_t id;\n  vector<sum_t> dp1,dp2;\n  ReRooting(int\
    \ n,const G &score,const F &merge,const sum_t &id=sum_t{})\n    :g(n),merge(merge),score(score),id(id),dp1(n,id),dp2(n,id){}\n\
    \ \n  void add_edge(int u,int v,const key_t &c){\n    g[u].emplace_back(Edge{u,v,c,id,id});\n\
    \    g[v].emplace_back(Edge{v,u,c,id,id});\n  }\n  void add_directed_edge(int\
    \ u,int v,const key_t &c){\n    g[u].emplace_back(Edge{u,v,c,id,id});\n  }\n \n\
    \  void dfs1(int idx,int pre){\n    for(auto &e:g[idx])if(e.to!=pre){\n      dfs1(e.to,idx);\n\
    \      e.dp1=score(dp1[e.to],e);\n      dp1[idx]=merge(dp1[idx],e.dp1);\n    }\n\
    \  }\n \n  void dfs2(int idx,int pre,sum_t top){\n    sum_t now=id;\n    for(auto\
    \ &e:g[idx]){\n      e.dp2=now;\n      if(e.to==pre)e.dp1=score(top,e);\n    \
    \  now=merge(now,e.dp1);\n    }\n    dp2[idx]=now;\n    now=id;\n    reverse(g[idx].begin(),g[idx].end());\n\
    \    for(auto &e:g[idx]){\n      if(e.to!=pre)\n        dfs2(e.to,idx,merge(e.dp2,now));\n\
    \      now=merge(now,e.dp1);\n    }\n  }\n \n  vector<sum_t> build(){\n    dfs1(0,-1);\n\
    \    dfs2(0,-1,id);\n    return dp2;\n  }\n};\n//\u4F7F\u7528\u4F8B:https://atcoder.jp/contests/abc222/submissions/26517686\n"
  code: "//key_t:\u8FBA\u56FA\u6709\u306E\u60C5\u5831\u3000\u9802\u70B9\u56FA\u6709\
    \u306E\u60C5\u5831\u306F\u30E9\u30E0\u30C0\u306E\u65B9\u3067\u30AD\u30E3\u30D7\
    \u30C1\u30E3\u3055\u305B\u308B\n//sum_t:\u8A08\u7B97\u7D50\u679C\ntemplate<typename\
    \ key_t,typename sum_t=key_t>\nstruct ReRooting{\n  struct Edge {\n    int from,to;\n\
    \    key_t cost;\n    sum_t dp1,dp2;\n    //dp1:\u90E8\u5206\u6728\u306E\u5185\
    \u5BB9\n    //dp2:e=g[idx][i]\u306E\u6642\u3001g[idx][0,i)\u306Edp1\u306E\u7D2F\
    \u7A4D\u304C\u5165\u308B\n  };\n  using F=function<sum_t(sum_t,sum_t)>;\n  using\
    \ G=function<sum_t(sum_t,Edge)>;\n \n  vector<vector<Edge>> g;\n  const F merge;\n\
    \  const G score;\n  const sum_t id;\n  vector<sum_t> dp1,dp2;\n  ReRooting(int\
    \ n,const G &score,const F &merge,const sum_t &id=sum_t{})\n    :g(n),merge(merge),score(score),id(id),dp1(n,id),dp2(n,id){}\n\
    \ \n  void add_edge(int u,int v,const key_t &c){\n    g[u].emplace_back(Edge{u,v,c,id,id});\n\
    \    g[v].emplace_back(Edge{v,u,c,id,id});\n  }\n  void add_directed_edge(int\
    \ u,int v,const key_t &c){\n    g[u].emplace_back(Edge{u,v,c,id,id});\n  }\n \n\
    \  void dfs1(int idx,int pre){\n    for(auto &e:g[idx])if(e.to!=pre){\n      dfs1(e.to,idx);\n\
    \      e.dp1=score(dp1[e.to],e);\n      dp1[idx]=merge(dp1[idx],e.dp1);\n    }\n\
    \  }\n \n  void dfs2(int idx,int pre,sum_t top){\n    sum_t now=id;\n    for(auto\
    \ &e:g[idx]){\n      e.dp2=now;\n      if(e.to==pre)e.dp1=score(top,e);\n    \
    \  now=merge(now,e.dp1);\n    }\n    dp2[idx]=now;\n    now=id;\n    reverse(g[idx].begin(),g[idx].end());\n\
    \    for(auto &e:g[idx]){\n      if(e.to!=pre)\n        dfs2(e.to,idx,merge(e.dp2,now));\n\
    \      now=merge(now,e.dp1);\n    }\n  }\n \n  vector<sum_t> build(){\n    dfs1(0,-1);\n\
    \    dfs2(0,-1,id);\n    return dp2;\n  }\n};\n//\u4F7F\u7528\u4F8B:https://atcoder.jp/contests/abc222/submissions/26517686\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/ReRooting.cpp
  requiredBy: []
  timestamp: '2022-02-06 17:35:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/ReRooting.cpp
layout: document
redirect_from:
- /library/tree/ReRooting.cpp
- /library/tree/ReRooting.cpp.html
title: tree/ReRooting.cpp
---
