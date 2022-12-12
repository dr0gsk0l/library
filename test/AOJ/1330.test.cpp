#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330"
#include <bits/stdc++.h>
using namespace std;

#include "datastructure/unionfind/PotentialUnionFind.cpp"
#include "algebra/group/Add.cpp"

using ll=long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;
  while(cin>>n>>m,n){
    PotentialUnionFind<GroupAdd<ll>> uf(n);
    while(m--){
      char c;
      int a,b;
      cin>>c>>a>>b;a--;b--;
      if(c=='!'){
        ll w;cin>>w;
        assert(uf.merge(a,b,w));
      }
      else{
        auto ans=uf.diff(a,b);
        if(ans)cout<<ans.value()<<"\n";
        else cout<<"UNKNOWN\n";
      }
    }
  }
}
