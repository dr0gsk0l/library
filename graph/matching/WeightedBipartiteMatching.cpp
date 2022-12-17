#pragma once
#include "flow/MCF.cpp"
// 重みの最大化
template<typename TC>
class WeightedBipartiteMatching{
  int A,B; // 左右の頂点数
  int S,T;
  MCF<int,TC> fl;
public:
  WeightedBipartiteMatching(int A,int B):A(A),B(B),S(A+B),T(A+B+1),fl(A+B+2,S,T){
    for(int i=0;i<A;i++)fl.add_arc(S,i,1,0);
    for(int j=0;j<B;j++)fl.add_arc(A+j,T,1,0);
  }
  void add_edge(int u,int v,TC weight){
    assert(0<=u and u<A);
    assert(0<=v and v<B);
    fl.add_arc(u,A+v,1,-weight);
  }

  // first は重みの総和
  // second はマッチした各 [u,v,weight]
  pair<TC,vector<tuple<int,int,TC>>> solve(){
    auto [sum,ok]=fl.flow(min(A,B));
    vector<tuple<int,int,TC>> res;
    auto all_edge=fl.all_edge();
    for(int i=A+B;i<all_edge.size();i++){
      const auto&[from,to,flow,cost]=all_edge[i];
      if(flow)res.emplace_back(from,to-A,-cost);
    }
    return make_pair(-sum,res);
  }
};