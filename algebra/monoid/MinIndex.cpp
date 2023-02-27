#pragma once
template<typename X>
struct MonoidMinIndex{
  using P = pair<X,int>;
  using value_type = P;
  static constexpr P op(const P &x, const P &y) noexcept { return min(x,y); }
  static constexpr void Rchop(P&x, const P&y){ if(x>y)x=y; }
  static constexpr void Lchop(const P&x, P&y){ if(y>x)y=x; }
  static constexpr P unit() { return P(numeric_limits<X>::max()/2,-1); }
  static constexpr bool commute = true;
  static constexpr vector<P> arrange(const vector<X>&v){
    vector<P> w(v.size());
    for(int i=0;i<v.size();i++)w[i]=P(v[i],i);
    return w;
  }
};