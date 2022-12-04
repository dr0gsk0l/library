class IntegerSumRuleUnionFind{
  using ll=long long;
  int n,num;
  vector<int> sz,parent;
  vector<pair<int,ll>> potential; 
  vector<optional<ll>> value; 
public:
  IntegerSumRuleUnionFind()=default;
  IntegerSumRuleUnionFind(int n):n(n),num(n),sz(n,1),parent(n,0),potential(n,{1,0}),value(n,nullopt){
    iota(parent.begin(),parent.end(),0);
  }

  tuple<int,int,ll> from_root(int x){
    if(x==parent[x])return {x,1,0LL};
    auto [r,a,b]=from_root(parent[x]);
    auto [c,d]=potential[x];
    parent[x]=r;
    potential[x]={a*c,b*c+d};
    return {r,a*c,b*c+d};
  }
  
  int leader(int x){ return get<0>(from_root(x)); }
  
  bool same(int x,int y){
    assert(0<=x and x<n and 0<=y and y<n);
    return leader(x)==leader(y); 
  }

  bool merge(int x,int y,ll sum){
    // 矛盾する場合は変更はせず false を返す
    assert(0<=x and x<n and 0<=y and y<n);
    auto [rx,a,b]=from_root(x);
    auto [ry,c,d]=from_root(y);
    if(rx==ry){
      // ar+b + cr+d = sum
      if(a==-c)return b+d==sum;
      if((sum-b-d)&1)return false;
      ll r=(sum-b-d)/(a+c);
      if(value[rx] and value[rx].value()!=r)return false; // これ起きる？
      value[rx]=r;
      return true;
    }
    if(sz[rx]<sz[ry]){
      swap(rx,ry);
      swap(a,c);
      swap(b,d);
    }
    // a * rx + b + c * ry + d == sum
    // rx = -c/a ry + (sum-b-d)/a
    // ry = -a/c rx + (sum-b-d)/c
    if(value[ry]){
      ll k = -c*a * value[ry].value() + (sum-b-d)*a;
      if(value[rx] and value[rx].value()!=k)return false;
      value[rx]=k;
    }
    sz[rx]+=sz[ry];
    parent[ry]=rx;
    potential[ry]={-a*c,(sum-b-d)*c};
    num--;
    return true;
  }

  optional<ll> val(int x){ 
    auto [r,a,b]=from_root(x);
    if(value[r])return value[r].value()*a+b;
    return nullopt;
  }

  // x と y が隣接してないなら nullopt
  // x と y が隣接しているが、sum が一意でない場合も nullopt
  optional<ll> sum(int x,int y){
    auto [rx,a,b]=from_root(x);
    auto [ry,c,d]=from_root(y);
    if(rx!=ry)return nullopt;
    if(a==c){
      assert(b==d);
      return nullopt;
    }
    return b+d;
  }

  int size(const int x){
    assert(0<=x and x<n);
    return sz[leader(x)];
  }
  
  int count()const{
    return num;
  }
};