#pragma once
#include "flow/MCF.cpp"
// 重みの最大化
template<typename T>
class WeightedBipartiteMatching{
  int A,B; // 左右の頂点数
  int S,T;
  MCF<int,T> fl;
public:
  WeightedBipartiteMatching(int A,int B):A(A),B(B),S(A+B),T(A+B+1),fl(A+B+2,S,T){
    for(int i=0;i<A;i++)fl.add_arc(S,i,1,0);
    for(int j=0;j<B;j++)fl.add_arc(A+j,T,1,0);
  }
  void add_edge(int u,int v,T weight){
    assert(0<=u and u<A);
    assert(0<=v and v<B);
    fl.add_arc(u,A+v,1,-weight);
  }
  T solve(){
    // MCF を改造して辺の情報取れるようにしてくれ
    return fl.flow(S,T,min(A,B)).first;
  }
};