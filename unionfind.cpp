struct UnionFind{
  int n,num;
  vector<int> r,p;
  UnionFind(){}
  UnionFind(int n):num(n),r(n,1),p(n,0){iota(p.begin(),p.end(),0);}
  
  int find(int x){
    return (x==p[x]?x:p[x]=find(p[x]));
  }
  
  bool same(int x,int y){
    return find(x)==find(y);
  }
  
  bool merge(int x,int y){
    x=find(x);y=find(y);
    if(x==y)return false;
    if(r[x]<r[y])swap(x,y);
    r[x]+=r[y];
    p[y]=x;
    num--;
    return true;
  }
  
  int size(const int x){
    return r[find(x)];
  }
  
  int count() const{
    return num;
  }
};

/**
* @docs unionfind.md
*/