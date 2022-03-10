struct UnionFind{
  int n,num;
  vector<int> r,p;
  UnionFind(){}
  UnionFind(int n):num(n),r(n,1),p(n,0){iota(p.begin(),p.end(),0);}
  
  int leader(int x){
    return (x==p[x]?x:p[x]=leader(p[x]));
  }
  
  bool same(int x,int y){
    return leader(x)==leader(y);
  }
  
  bool merge(int x,int y){
    x=leader(x);y=leader(y);
    if(x==y)return false;
    if(r[x]<r[y])swap(x,y);
    r[x]+=r[y];
    p[y]=x;
    num--;
    return true;
  }
  
  int size(const int x){
    return r[leader(x)];
  }
  
  int count() const{
    return num;
  }
};

/**
* @docs UnionFind.md
*/