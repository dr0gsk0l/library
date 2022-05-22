---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/ShortestPath.test.cpp
    title: test/yosupo/ShortestPath.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dijkstra.cpp\"\ntemplate<typename T,typename Comp>\n\
    using pque=priority_queue<T,vector<T>,Comp>;\n\ntemplate<typename T>\nbool chmin(T\
    \ &a,T b){\n  return (a>b&&(a=b,true));\n}\n\ntemplate<typename T>\nvector<T>\
    \ dijkstra(const WeightedGraph<T> &g,int s=0){\n  vector<T> d(g.size(),numeric_limits<T>::max()/2);\n\
    \  pque<pair<T,unsigned int>,greater<>> que;\n  d[s]=0;\n  que.emplace(0,s);\n\
    \  while(que.size()){\n    auto [now,id]=que.top();que.pop();\n    if(d[id]<now)continue;\n\
    \    for(auto&[to,co]:g[id])\n      if(chmin(d[to],now+co))que.emplace(d[to],to);\n\
    \  }\n  return d;\n}\n"
  code: "template<typename T,typename Comp>\nusing pque=priority_queue<T,vector<T>,Comp>;\n\
    \ntemplate<typename T>\nbool chmin(T &a,T b){\n  return (a>b&&(a=b,true));\n}\n\
    \ntemplate<typename T>\nvector<T> dijkstra(const WeightedGraph<T> &g,int s=0){\n\
    \  vector<T> d(g.size(),numeric_limits<T>::max()/2);\n  pque<pair<T,unsigned int>,greater<>>\
    \ que;\n  d[s]=0;\n  que.emplace(0,s);\n  while(que.size()){\n    auto [now,id]=que.top();que.pop();\n\
    \    if(d[id]<now)continue;\n    for(auto&[to,co]:g[id])\n      if(chmin(d[to],now+co))que.emplace(d[to],to);\n\
    \  }\n  return d;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.cpp
  requiredBy: []
  timestamp: '2022-05-23 06:42:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/ShortestPath.test.cpp
documentation_of: graph/dijkstra.cpp
layout: document
redirect_from:
- /library/graph/dijkstra.cpp
- /library/graph/dijkstra.cpp.html
title: graph/dijkstra.cpp
---
