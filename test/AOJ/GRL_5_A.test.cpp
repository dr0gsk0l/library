#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"
#include <bits/stdc++.h>
using namespace std;

#include "tree/WeightedTree.cpp"
#include "tree/ReRooting.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
  WeightedTree<int> t(n);
  t.scan(0);

  ReRooting< WeightedTree<int>, int> RR;
  auto score=[&](int now,auto&e){
    return now+e.weight;
  };
  auto merge=[&](int&now,int add){
    return max(now,add);
  };
  auto ans=RR.build(score,merge,0);

  int fans=0;
  for(int p:ans)fans=max(fans,p);
  cout<<fans<<endl;
}