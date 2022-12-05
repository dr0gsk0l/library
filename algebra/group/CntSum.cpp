template<typename X>
struct GroupCntSum{
  using P=pair<X,X>;
  using value_type=P;
  static constexpr P op(const P &x, const P &y){
    return {x.first + y.first, x.second + y.second};
  }
  static constexpr void Rchop(P&x, const P&y){
    x.first+=y.first;
    x.second+=y.second;
  }
  static constexpr void Lchop(const P&x, P&y){
    y.first+=x.first;
    y.second+=x.second;
  }
  static constexpr P inverse(const P &x){ return {-x.fi, -x.se}; }
  static constexpr P unit() { return {0, 0}; }
  static constexpr bool commute = true;
};
template<typename X>
vector<pair<X,X>> cnt_init(int n,const X&x){
  return vector<pair<X,X>>(n,{x,1});
}
template<typename X>
vector<pair<X,X>> cnt_init(const vector<X>&v){
  int n=v.size();
  vector<pair<X,X>> res(n);
  for(int i=0;i<n;i++)res[i]={v[i],1};
  return res;
}