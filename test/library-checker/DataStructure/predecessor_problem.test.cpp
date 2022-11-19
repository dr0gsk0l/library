#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include <bits/stdc++.h>
using namespace std;

#include "superstd/set.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;cin>>n>>q;
  Set<int> se;
  se.banpei();

  for(int i=0;i<n;i++){
    char c;cin>>c;
    if(c=='1')se.insert(i);
  }

  while(q--){
    int c,k;cin>>c>>k;
    if(c==0)se.insert(k);
    if(c==1)se.erase(k);
    if(c==2)cout<<se.count(k)<<"\n";
    if(c==3){
      int x=se.geq(k);
      cout<<(x<n?x:-1)<<"\n";
    }
    if(c==4){
      int x=se.leq(k);
      cout<<(x>=0?x:-1)<<"\n";
    }
  }
}