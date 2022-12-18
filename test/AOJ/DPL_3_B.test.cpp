#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B"
#include <bits/stdc++.h>
using namespace std;

#include "tree/CartesianTree.cpp"

void chmax(int&a,int b){ a=max(a,b); }

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int h,w;cin>>h>>w;

  int ans=0;
  vector<int> v(w,0);
  while(h--){
    for(int&p:v){
      int a;cin>>a;
      if(a)p=0;
      else p++;
    }
    auto T=cartesian_tree(v);
    chmax(ans,v[T.root]*w);
    for(int i=0;i<w;i++)
      for(const auto&e:T.son(i)){
        const auto&[L,R]=e.weight;
        chmax(ans,v[e.to]*(R-L));
      }
  }
  cout<<ans<<endl;
}