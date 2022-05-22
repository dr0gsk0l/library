---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/WeightedGraph.cpp
    title: graph/WeightedGraph.cpp
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.cpp
    title: graph/dijkstra.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/yosupo/ShortestPath.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/shortest_path\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"graph/WeightedGraph.cpp\"\ntemplate<typename\
    \ T>\nstruct Edge{\n  int to;\n  T cost;\n};\n \ntemplate<typename T>\nstruct\
    \ WeightedGraph:vector<vector<Edge<T>>>{\n  WeightedGraph(){}\n  WeightedGraph(int\
    \ n){\n    (*this).resize(n);\n  }\n    \n  void add_edge(int from, int to, T\
    \ cost){\n    (*this)[from].push_back({to,cost});\n  }\n};\n#line 1 \"graph/dijkstra.cpp\"\
    \ntemplate<typename T,typename Comp>\nusing pque=priority_queue<T,vector<T>,Comp>;\n\
    \ntemplate<typename T>\nbool chmin(T &a,T b){\n  return (a>b&&(a=b,true));\n}\n\
    \ntemplate<typename T>\nvector<T> dijkstra(const WeightedGraph<T> &g,int s=0){\n\
    \  vector<T> d(g.size(),numeric_limits<T>::max()/2);\n  pque<pair<T,unsigned int>,greater<>>\
    \ que;\n  d[s]=0;\n  que.emplace(0,s);\n  while(que.size()){\n    auto [now,id]=que.top();que.pop();\n\
    \    if(d[id]<now)continue;\n    for(auto&[to,co]:g[id])\n      if(chmin(d[to],now+co))que.emplace(d[to],to);\n\
    \  }\n  return d;\n}\n#line 8 \"test/yosupo/ShortestPath.test.cpp\"\n\nusing ll=long\
    \ long;\n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\
    \  \n  int n,m;cin>>n>>m;\n  int s,t;cin>>s>>t;\n  WeightedGraph<ll> g(n);\n \
    \ while(m--){\n    int a,b,c;cin>>a>>b>>c;\n    g.add_edge(a,b,c);\n  }\n  auto\
    \ d=dijkstra(g,s);\n  if(d[t]>1e15){\n    cout<<-1<<endl;\n    return 0;\n  }\n\
    \  vector<int> pre(n,-1);\n  queue<int> que;\n  que.push(s);\n  pre[s]=s;\n  while(que.size()){\n\
    \    int p=que.front();que.pop();\n    for(auto [to,co]:g[p])\n      if(pre[to]==-1\
    \ and d[p]+co==d[to]){\n        pre[to]=p;\n        que.push(to);\n      }\n \
    \ }\n  vector<int> ans;\n  while(true){\n    ans.push_back(t);\n    if(t==s)break;\n\
    \    t=pre[t];\n  }\n  cout<<d[ans[0]]<<\" \"<<ans.size()-1<<\"\\n\";\n  for(int\
    \ i=ans.size()-1;i;i--)cout<<ans[i]<<\" \"<<ans[i-1]<<\"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../graph/WeightedGraph.cpp\"\
    \n#include \"../../graph/dijkstra.cpp\"\n\nusing ll=long long;\n\nint main(){\n\
    \  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  \n  int n,m;cin>>n>>m;\n\
    \  int s,t;cin>>s>>t;\n  WeightedGraph<ll> g(n);\n  while(m--){\n    int a,b,c;cin>>a>>b>>c;\n\
    \    g.add_edge(a,b,c);\n  }\n  auto d=dijkstra(g,s);\n  if(d[t]>1e15){\n    cout<<-1<<endl;\n\
    \    return 0;\n  }\n  vector<int> pre(n,-1);\n  queue<int> que;\n  que.push(s);\n\
    \  pre[s]=s;\n  while(que.size()){\n    int p=que.front();que.pop();\n    for(auto\
    \ [to,co]:g[p])\n      if(pre[to]==-1 and d[p]+co==d[to]){\n        pre[to]=p;\n\
    \        que.push(to);\n      }\n  }\n  vector<int> ans;\n  while(true){\n   \
    \ ans.push_back(t);\n    if(t==s)break;\n    t=pre[t];\n  }\n  cout<<d[ans[0]]<<\"\
    \ \"<<ans.size()-1<<\"\\n\";\n  for(int i=ans.size()-1;i;i--)cout<<ans[i]<<\"\
    \ \"<<ans[i-1]<<\"\\n\";\n}"
  dependsOn:
  - graph/WeightedGraph.cpp
  - graph/dijkstra.cpp
  isVerificationFile: true
  path: test/yosupo/ShortestPath.test.cpp
  requiredBy: []
  timestamp: '2022-05-23 06:42:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/ShortestPath.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/ShortestPath.test.cpp
- /verify/test/yosupo/ShortestPath.test.cpp.html
title: test/yosupo/ShortestPath.test.cpp
---
