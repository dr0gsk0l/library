#pragma once

// 重み無し
#include "flow/Dinic.cpp"
class BipartiteMatching{
  int A,B; // 左右の頂点数
  int S,T;
  Dinic<int> fl;
public:
  BipartiteMatching(int A,int B):A(A),B(B),S(A+B),T(A+B+1),fl(A+B+2,S,T){
    for(int i=0;i<A;i++)fl.add_arc(S,i,1);
    for(int j=0;j<B;j++)fl.add_arc(A+j,T,1);
  }
  void add_arc(int u,int v){
    assert(0<=u and u<A);
    assert(0<=v and v<B);
    fl.add_arc(u,A+v,1);
  }
  vector<pair<int,int>> solve(){
    int K=fl.flow(min(A,B));
    vector<pair<int,int>> res;
    res.reserve(K);
    auto all_edge=fl.all_edge();
    for(int i=A+B;i<all_edge.size();i++){
      const auto&[from,to,flow]=all_edge[i];
      if(flow)res.emplace_back(from,to-A);
    }
    return res;
  }
};