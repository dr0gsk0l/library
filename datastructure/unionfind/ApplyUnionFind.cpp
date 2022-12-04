#pragma once
// ある連結成分の各頂点に加算出来る
template<typename AbelGroup>
class ApplyUnionFind{
  using T=typename AbelGroup::value_type;
  int n,num;
  vector<int> sz,parent;
  vector<T> value;
public:
  ApplyUnionFind()=default;
  ApplyUnionFind(int n):n(n),num(n),sz(n,1),parent(n),value(n,AbelGroup::unit()){
    iota(parent.begin(),parent.end(),0);
  }
  ApplyUnionFind(const vector<T>&v):n(v.size()),num(n),sz(n,1),parent(n),value(v){
    iota(parent.begin(),parent.end(),0);
  }
  
  int leader(int x){ 
    assert(0<=x and x<n);
    if(parent[x]==x)return x;
    if(parent[parent[x]]==parent[x])return parent[x];
    stack<int> sta;
    while(parent[x]!=x){
      sta.push(x);
      x=parent[x];
    }
    T sum=AbelGroup::unit();
    while(sta.size()){
      int v=sta.top();sta.pop();
      sum=AbelGroup::op(sum,value[v]);
      value[v]=sum;
      parent[v]=x;
    }
    return x;
  }

  T get(int x){
    if(x==leader(x))return value[x];
    return AbelGroup::op(value[x],value[parent[x]]);
  }

  // x と連結な頂点全体に *=a
  void multiply(int x,T a){
    x=leader(x);
    value[x]=AbelGroup::op(value[x],a);
  }
  
  bool same(int x,int y){
    assert(0<=x and x<n and 0<=y and y<n);
    return leader(x)==leader(y); 
  }
  
  bool merge(int x,int y){
    assert(0<=x and x<n and 0<=y and y<n);
    x=leader(x);y=leader(y);
    if(x==y)return false;
    if(sz[x]<sz[y])swap(x,y);
    sz[x]+=sz[y];
    parent[y]=x;
    value[y]=AbelGroup::op(value[y],AbelGroup::inverse(value[x]));
    num--;
    return true;
  }
  
  int size(const int x){
    assert(0<=x and x<n);
    return sz[leader(x)];
  }
  
  int count()const{
    return num;
  }
};