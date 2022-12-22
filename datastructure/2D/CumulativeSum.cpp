template<typename T>
class CumulativeSum2D{
  using U=conditional_t< is_same_v<T,int>,long long,T >;
  int h,w;
  vector<vector<U>> A;
  bool prepared;
public:
  CumulativeSum2D(int h=0,int w=0):h(h),w(w),A(h+1,vector<U>(w+1,0)),prepared(false){}
  CumulativeSum2D(const vector<vector<T>>&v):h(v.size()),w(v[0].size()),A(h+1,vector<U>(w+1,0)),prepared(false){
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)A[i+1][j+1]=v[i][j];
    build();
  }
  void add(int y,int x,const T&val=1){
    assert(!prepared);
    assert(0<=y and y<h and 0<=x and x<w);
    A[y+1][x+1]+=val;
  }
  void build(){
    assert(!prepared);prepared=true;
    for(int i=0;i<h;i++)for(int j=0;j<=w;j++)A[i+1][j]+=A[i][j];
    for(int i=0;i<=h;i++)for(int j=0;j<w;j++)A[i][j+1]+=A[i][j];
  }
  U sum(int u,int d,int l,int r){
    assert(prepared);
    assert(0<=u and u<=d and u<=h);
    assert(0<=l and l<=r and r<=w);
    return A[d][r]-A[d][l]-A[u][r]+A[u][l];
  }
  U sum(){
    assert(prepared);
    return A.back().back();
  }
};