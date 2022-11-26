#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"
#include <bits/stdc++.h>
using namespace std;

#include "superstd/Multiset.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;cin>>n>>q;
  Multiset<int> s;
  s.scan(n);
  while(q--){
    int t;cin>>t;
    if(t==0){
      int x;cin>>x;
      s.insert(x);
    }
    if(t==1){
      int a=s.pick_mn();
      cout<<a<<"\n";
    }
    if(t==2){
      int a=s.pick_mx();
      cout<<a<<"\n";
    }
  }
}