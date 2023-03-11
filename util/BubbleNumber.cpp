#pragma once
#include "util/InversionNumber.cpp"
template<typename T>
long long bubble_number(const vector<T>&v,const vector<T>&w){
  int n=v.size();
  assert(w.size()==n);
  map<T,queue<int>> mp;
  for(int i=0;i<n;i++)mp[w[i]].push(i);
  vector<int> idx(n);
  REP(i,n){
    if(!mp[v[i]].size())return -1;
    idx[i]=mp[v[i]].front();mp[v[i]].pop();
  }
  return inversion_number(idx);
}