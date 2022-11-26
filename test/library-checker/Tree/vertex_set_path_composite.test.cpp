#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include <bits/stdc++.h>
using namespace std;

#include "algebra/group/Affine.cpp"
#include "algebra/Reverse.cpp"
#include "segtree/SegmentTree.cpp"
#include "tree/Tree.cpp"
#include "tree/HLD.cpp"
#include "tree/TreeMonoid.cpp"

#include <atcoder/modint>
#include <atcoder/convolution>
using namespace atcoder;
using mint=modint998244353;
ostream& operator<<(ostream &os,mint a){os<<a.val();return os;}
istream& operator>>(istream &is,mint &a){
  long long b;is>>b;a=b;
  return is;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  using G=AlgebraReverse<GroupAffine<mint>>;
  using F=G::value_type;

  int n,q;cin>>n>>q; 

  vector<F> f(n);
  for(int i=0;i<n;i++){
    mint a,b;cin>>a>>b;
    f[i]={a,b};
  }

  Tree t(n);
  t.scan(0);

  TreeMonoid<Tree,G> TM(t,f);

  while(q--){
    int c;cin>>c;
    if(c){
      int u,v,x;cin>>u>>v>>x;
      F g=TM.path_prod(u,v);
      cout<<G::eval(g,x)<<endl;
    }
    else{
      int p,c,d;cin>>p>>c>>d;
      TM.set(p,{c,d});
    }
  }
}