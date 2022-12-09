#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include <bits/stdc++.h>
using namespace std;

#include "datastructure/BinaryTrie.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  BinaryTrie<30,int> BT;
  int q;cin>>q;
  while(q--){
    int t,x;cin>>t>>x;
    if(t<=1){
      int c=BT.count(x);
      if(t==0 and c==0)BT.add(x,+1);
      if(t==1 and c==1)BT.add(x,-1);
    }
    else cout<<BT.min(x)<<"\n";
  }
}
