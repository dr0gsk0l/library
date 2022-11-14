template<typename Monoid,int LOG>
class Doubling{
  using X=typename Monoid::value_type;
  int n;
  bool is_prepared;
  
  using P=pair<int,X>;
  static constexpr P unit={-1,Monoid::unit()};
  vector<vector<P>> DP;

  P k_move(const P&a,int k){
    if(a.first==-1)return a;
    const auto [now,val]=a;
    const auto [nxt,cost]=DP[k][now];
    return {nxt,Monoid::op(val,cost)};
  }

  void build(){
    is_prepared=true;
    for(int k=0;k<LOG-1;k++)
      for(int v=0;v<n;v++)
        DP[k+1][v]=k_move(DP[k][v],k);
  }
public:
  Doubling(int n):n(n),is_prepared(false){
    DP.assign(LOG, vector<P>(n,unit));
  }

  void add_arc(int from,int to,X x){
    assert(!is_prepared);
    assert(-1<=to and to<n);
    DP[0][from]={to,x};
  }

  // [終点,値] 辺が出てない場所から移動する場合は -1 に着く
  P calc(int s,long long step){
    assert(step<=(1LL<<LOG));
    if(!is_prepared)build();

    P res{s,Monoid::unit()};
    for(int k=0;step;k++,step>>=1)
      if(step&1)res=k_move(res,k);
    return res;
  }
};