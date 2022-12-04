#pragma once
template<typename AbelGroup>
class PotentialUnionFind{
  using T=typename AbelGroup::value_type;
  int n,num;
  vector<int> sz,parent;
  vector<T> potential; // parent[x] を基準とした時の x の値
public:
  PotentialUnionFind()=default;
  PotentialUnionFind(int n):n(n),num(n),sz(n,1),parent(n,0),potential(n,AbelGroup::unit()){
    assert(AbelGroup::commute);
    iota(parent.begin(),parent.end(),0);
  }

  pair<int,T> from_root(int x){
    if(x==parent[x])return {x,AbelGroup::unit()};
    auto [r,add]=from_root(parent[x]);
    parent[x]=r;
    potential[x]=AbelGroup::op(add,potential[x]);
    return {r,potential[x]};
  }
  
  int leader(int x){ return from_root(x).first; }
  
  bool same(int x,int y){
    assert(0<=x and x<n and 0<=y and y<n);
    return leader(x)==leader(y); 
  }

  bool merge(int x,int y,T d){
    // potential[y]-potential[x]=d にする
    // 矛盾する場合は変更はせず false を返す
    assert(0<=x and x<n and 0<=y and y<n);
    auto [rx,dx]=from_root(x);
    auto [ry,dy]=from_root(y);
    if(rx==ry)return dx==dy;
    d=AbelGroup::op(d,dx);
    d=AbelGroup::op(d,AbelGroup::inverse(dy));
    if(sz[rx]<sz[ry]){
      swap(rx,ry);
      d=AbelGroup::inverse(d);
    }
    sz[rx]+=sz[ry];
    parent[ry]=rx;
    potential[ry]=d;
    num--;
    return true;
  }

  optional<T> diff(int x,int y){
    // x を基準とする
    auto [rx,dx]=from_root(x);
    auto [ry,dy]=from_root(y);
    if(rx!=ry)return nullopt;
    return AbelGroup::op(dy,AbelGroup::inverse(dx));
  }

  int size(const int x){
    assert(0<=x and x<n);
    return sz[leader(x)];
  }
  
  int count()const{
    return num;
  }
};