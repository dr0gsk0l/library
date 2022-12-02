struct Modint61{
  using ll=long long;
  static constexpr ll MOD=(1LL<<61)-1;
  ll v;
  Modint61(const ll x=0):v(x){
    if(v<0||v>=MOD){
      v%=MOD;
      if(v<0)v+=MOD;
    }
  }
  static Modint61 raw(ll v){
    Modint61 x;
    x.v=v;
    return x;
  }
private:
  template<int d>
  static constexpr pair<ll,ll> divide(const ll&a){
    return {a>>d, a&((1LL<<d)-1)};
  }
public:
  Modint61 pow(long long k){
    Modint61 res(1),tmp(v);
    while(k){
      if(k&1)res*=tmp;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }

  Modint61 inv(){ return pow(MOD-2); }

  Modint61& operator+=(Modint61 a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Modint61& operator-=(Modint61 a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Modint61& operator*=(Modint61 a){
    const auto [vu,vd]=divide<31>(v);
    const auto [au,ad]=divide<31>(a.v);
    ll x = vd*au + vu*ad;
    const auto [xu,xd]=divide<30>(x);
    v = vu*au*2 + xu + (xd<<31) + vd*ad;
    if(v>=MOD){
      const auto [vu2,vd2]=divide<61>(v);
      v=vu2+vd2;
    }
    if(v>=MOD)v-=MOD;
    return *this;
  }
  Modint61& operator/=(Modint61 a){
    return (*this)*=a.inv();
  }
  Modint61 operator+(Modint61 a) const{return Modint61(v)+=a;}
  Modint61 operator-(Modint61 a) const{return Modint61(v)-=a;}
  Modint61 operator*(Modint61 a) const{return Modint61(v)*=a;}
  Modint61 operator/(Modint61 a) const{return Modint61(v)/=a;}

  Modint61 operator+() const{return *this;}
  Modint61 operator-() const{return v?Modint61(MOD-v):Modint61(v);}

  bool operator==(const Modint61 a)const{return v==a.v;}
  bool operator!=(const Modint61 a)const{return v!=a.v;}
  bool operator<(const Modint61 a)const{return v<a.v;}
};