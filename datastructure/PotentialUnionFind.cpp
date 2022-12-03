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
  
  int leader(int x){ 
    if(x==parent[x])return x;
    int p=leader(parent[x]);
    potential[x]=AbelGroup::op(potential[x],potential[parent[x]]);
    return parent[x]=p;
  }
  
  bool same(int x,int y){
    assert(0<=x and x<n and 0<=y and y<n);
    return leader(x)==leader(y); 
  }

  bool merge(int x,int y,T d){
    // potential[y]-potential[x]=d にする
    // 矛盾する場合は変更はせず false を返す
    assert(0<=x and x<n and 0<=y and y<n);
    bool same_=same(x,y);
    d=AbelGroup::op(d,potential[x]);
    x=parent[x];
    d=AbelGroup::op(d,AbelGroup::inverse(potential[y]));
    y=parent[y];
    if(same_)return d==AbelGroup::unit();
    if(sz[x]<sz[y]){
      swap(x,y);
      d=AbelGroup::inverse(d);
    }
    sz[x]+=sz[y];
    parent[y]=x;
    potential[y]=d;
    num--;
    return true;
  }

  optional<T> diff(int x,int y){
    // x を基準とする
    if(!same(x,y))return nullopt;
    return AbelGroup::op(potential[y],AbelGroup::inverse(potential[x]));
  }

  int size(const int x){
    assert(0<=x and x<n);
    return sz[leader(x)];
  }
  
  int count()const{
    return num;
  }
};