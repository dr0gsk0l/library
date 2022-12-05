template<typename AbelMonoid>
class UnionFind{
  using T=AbelMonoid::value_type;
  int n,num;
  vector<int> sz,parent;
  vector<T> value;
public:
  UnionFind()=default;
  UnionFind(int n):n(n),num(n),sz(n,1),parent(n),value(n,AbelMonoid::unit()){
    iota(parent.begin(),parent.end(),0);
  }
  UnionFind(const vector<T>&v):n(v.size()),num(n),sz(n,1),parent(n),value(v){
    iota(parent.begin(),parent.end(),0);
  }
  
  int leader(int x){ 
    assert(0<=x and x<n);
    return (x==parent[x]? x : parent[x]=leader(parent[x])); 
  }

  T sum(int x){ return value[leader(x)]; }

  void multiply(int x,T a){
    AbelMonoid::Rchop(value[leader(x)],a);
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
    AbelMonoid::Rchop(value[x],value[y]);
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