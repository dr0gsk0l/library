#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#include "../../segtree/segtree.cpp"
#include "../../mod/modint.cpp"

using mint=Mint<long long>;
struct Linear{
  mint a,b;
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;cin>>n>>q;

  vector<Linear> v(n);
  for(int i=0;i<n;i++)cin>>v[i].a>>v[i].b;
  SegmentTree<Linear> seg([](Linear f,Linear g){
    return Linear{f.a*g.a,g.a*f.b+g.b};
  },{1,0},v);

  while(q--){
    int t,l,r,x;cin>>t>>l>>r>>x;
    if(t){
      auto [a,b]=seg.query(l,r);
      cout<<a*x+b<<"\n";
    }
    else seg.set_val(l,Linear{r,x});
  }
}