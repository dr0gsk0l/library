#pragma once
#include "util/Compress.cpp"
template<typename X,typename Y>
class Projection{
  Compress<pair<X,Y>> C; // pair で番兵は壊れるので使わない
public:
  Projection(const vector<pair<X,Y>>&v):C(v){}
  int size(){ return C.size(); }
  int id(pair<X,Y> xy){ return C[xy]; }
  int id(int x,int y){ return C[make_pair(x,y)]; }
  pair<X,Y> r(int id){ return C.r(id); }
  //[l,r) を返す
  pair<int,int> interval(const X&l,const X&r){
    if(C.max().first<l or r<=C.min().first)return make_pair(0,0);
    Y mn=numeric_limits<Y>::min();
    int L=C.geq(make_pair(l,mn));
    int R=C.geq(make_pair(r,mn));
    return make_pair(L,R);
  }
};