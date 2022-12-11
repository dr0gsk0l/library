#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2971"
#include <bits/stdc++.h>
using namespace std;

#include "datastructure/unionfind/PotentialUnionFind.cpp"
#include "mod/Modint.cpp"
#include "algebra/group/Multiply.cpp"
using ll=long long;
using mint1=Mint<ll,998244341>;
using mint2=Mint<ll,998244389>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;cin>>n>>m;
  PotentialUnionFind< GroupMultiply< mint1 > > uf1(n);
  PotentialUnionFind< GroupMultiply< mint2 > > uf2(n);
  
  while(m--){
    int a,b,c;cin>>a>>b>>c;a--;b--;
    if(!uf1.merge(a,b,c)||!uf2.merge(a,b,c)){
      cout<<"No\n";
      return 0;
    }
  }
  cout<<"Yes\n";
}