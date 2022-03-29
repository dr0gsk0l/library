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
  bundledCode: "#line 1 \"flow/dinic.cpp\"\ntemplate<typename T,bool directed>\nstruct\
    \ Dinic{\n  struct edge{\n    int to,cap,rev;\n    edge(){}\n    edge(int to,int\
    \ cap,int rev):to(to),cap(cap),rev(rev){} \n  };\n  vector<vector<edge>> G;\n\
    \  vector<int> level,iter;\n\n  Dinic(){}\n  Dinic(int n):G(n),level(n),iter(n){}\n\
    \n  int add_edge(int from,int to,T cap){\n    G[from].emplace_back(to,cap,G[to].size());\n\
    \    G[to].emplace_back(from,directed?0:cap,G[from].size()-1);\n    return G[to].back().rev;\n\
    \  }\n\n  void bfs(int s){\n    //level[v]\u3092\uFF08\u5BB9\u91CF\u6B63\u306E\
    \u8FBA\u306B\u3088\u308B\uFF09s\u304B\u3089\u306E\u6700\u77ED\u8DDD\u96E2\u306B\
    \u3059\u308B \u5230\u9054\u51FA\u6765\u306A\u3051\u308C\u3070-1\n    fill(level.begin(),level.end(),-1);\n\
    \    queue<int> que;\n    level[s]=0;\n    que.emplace(s);\n    while(que.size()){\n\
    \      int v=que.front();que.pop();\n      for(int i=0;i<(int)G[v].size();i++){\n\
    \        edge &e=G[v][i];\n        if(e.cap==0||~level[e.to])continue;\n     \
    \   level[e.to]=level[v]+1;\n        que.emplace(e.to);\n      }\n    }\n  }\n\
    \  \n  T dfs(int v,int t,T f){\n    //v\u304B\u3089t\u306B\u6700\u77ED\u8DEF\u3067\
    \u6C34\u3092\u6D41\u3059 f\u304Cv\u307E\u3067\u6301\u3063\u3066\u3053\u308C\u305F\
    \u6C34\u91CF \u6D41\u305B\u305F\u91CF\u304C\u8FD4\u308A\u5024\n    if(v==t)return\
    \ f;\n    for(int &i=iter[v];i<(int)G[v].size();i++){//\u3053\u306Edfs\u3067\u4F7F\
    \u308F\u306A\u304B\u3063\u305F\u8FBA\u306F\u6B21\u306EBFS\u307E\u3067\u4F7F\u308F\
    \u308C\u308B\u3053\u3068\u306F\u306A\u3044\n      edge &e=G[v][i];\n      if(e.cap>0&&level[v]<level[e.to]){//bfs\u3092\
    \u3057\u3066\u3044\u308B\u306E\u3067level[v]<level[e.to]\u306A\u3089level[v]+1==level[e.to]\n\
    \        T d=dfs(e.to,t,min(f,e.cap));\n        if(d==0)continue;\n        e.cap-=d;\n\
    \        G[e.to][e.rev].cap+=d;\n        return d;//\u4E00\u672C\u6D41\u305B\u305F\
    \u3089return\n      }\n    }\n    return 0;\n  }\n  \n  T flow(int s,int t,T lim){\n\
    \    T fl=0;\n    while(lim>0){\n      bfs(s);\n      if(level[t]<0)break;\n \
    \     fill(iter.begin(),iter.end(),0);\n      while(true){\n        T f=dfs(s,t,lim);\n\
    \        if(f==0)break;\n        fl+=f;\n        lim-=f;\n      }\n    }\n   \
    \ return fl;\n  }\n  \n  T flow(int s,int t){\n    return flow(s,t,numeric_limits<T>::max()/2);\n\
    \  }\n};\n"
  code: "template<typename T,bool directed>\nstruct Dinic{\n  struct edge{\n    int\
    \ to,cap,rev;\n    edge(){}\n    edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}\
    \ \n  };\n  vector<vector<edge>> G;\n  vector<int> level,iter;\n\n  Dinic(){}\n\
    \  Dinic(int n):G(n),level(n),iter(n){}\n\n  int add_edge(int from,int to,T cap){\n\
    \    G[from].emplace_back(to,cap,G[to].size());\n    G[to].emplace_back(from,directed?0:cap,G[from].size()-1);\n\
    \    return G[to].back().rev;\n  }\n\n  void bfs(int s){\n    //level[v]\u3092\
    \uFF08\u5BB9\u91CF\u6B63\u306E\u8FBA\u306B\u3088\u308B\uFF09s\u304B\u3089\u306E\
    \u6700\u77ED\u8DDD\u96E2\u306B\u3059\u308B \u5230\u9054\u51FA\u6765\u306A\u3051\
    \u308C\u3070-1\n    fill(level.begin(),level.end(),-1);\n    queue<int> que;\n\
    \    level[s]=0;\n    que.emplace(s);\n    while(que.size()){\n      int v=que.front();que.pop();\n\
    \      for(int i=0;i<(int)G[v].size();i++){\n        edge &e=G[v][i];\n      \
    \  if(e.cap==0||~level[e.to])continue;\n        level[e.to]=level[v]+1;\n    \
    \    que.emplace(e.to);\n      }\n    }\n  }\n  \n  T dfs(int v,int t,T f){\n\
    \    //v\u304B\u3089t\u306B\u6700\u77ED\u8DEF\u3067\u6C34\u3092\u6D41\u3059 f\u304C\
    v\u307E\u3067\u6301\u3063\u3066\u3053\u308C\u305F\u6C34\u91CF \u6D41\u305B\u305F\
    \u91CF\u304C\u8FD4\u308A\u5024\n    if(v==t)return f;\n    for(int &i=iter[v];i<(int)G[v].size();i++){//\u3053\
    \u306Edfs\u3067\u4F7F\u308F\u306A\u304B\u3063\u305F\u8FBA\u306F\u6B21\u306EBFS\u307E\
    \u3067\u4F7F\u308F\u308C\u308B\u3053\u3068\u306F\u306A\u3044\n      edge &e=G[v][i];\n\
    \      if(e.cap>0&&level[v]<level[e.to]){//bfs\u3092\u3057\u3066\u3044\u308B\u306E\
    \u3067level[v]<level[e.to]\u306A\u3089level[v]+1==level[e.to]\n        T d=dfs(e.to,t,min(f,e.cap));\n\
    \        if(d==0)continue;\n        e.cap-=d;\n        G[e.to][e.rev].cap+=d;\n\
    \        return d;//\u4E00\u672C\u6D41\u305B\u305F\u3089return\n      }\n    }\n\
    \    return 0;\n  }\n  \n  T flow(int s,int t,T lim){\n    T fl=0;\n    while(lim>0){\n\
    \      bfs(s);\n      if(level[t]<0)break;\n      fill(iter.begin(),iter.end(),0);\n\
    \      while(true){\n        T f=dfs(s,t,lim);\n        if(f==0)break;\n     \
    \   fl+=f;\n        lim-=f;\n      }\n    }\n    return fl;\n  }\n  \n  T flow(int\
    \ s,int t){\n    return flow(s,t,numeric_limits<T>::max()/2);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: flow/dinic.cpp
  requiredBy: []
  timestamp: '2022-03-29 14:51:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/dinic.cpp
layout: document
redirect_from:
- /library/flow/dinic.cpp
- /library/flow/dinic.cpp.html
title: flow/dinic.cpp
---
