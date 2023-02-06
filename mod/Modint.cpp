#pragma once
#include "math/ExtraGCD.cpp"
template<typename T,T MOD=998244353>
struct Mint{
  inline static constexpr T mod = MOD;
  T v;
  Mint():v(0){}
  Mint(signed v):v(v){}
  Mint(long long t){v=t%MOD;if(v<0)v+=MOD;}
  
  static Mint raw(int v){
    Mint x;
    x.v=v;
    return x;
  }

  Mint pow(long long k)const{
    Mint res(1),tmp(v);
    while(k){
      if(k&1)res*=tmp;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }

  static Mint add_identity(){return Mint(0);}
  static Mint mul_identity(){return Mint(1);}

  //Mint inv()const{return pow(MOD-2);}
  Mint inv()const{ return Mint(ext_gcd(v,mod).first); }

  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}

  Mint operator+(Mint a) const{return Mint(v)+=a;}
  Mint operator-(Mint a) const{return Mint(v)-=a;}
  Mint operator*(Mint a) const{return Mint(v)*=a;}
  Mint operator/(Mint a) const{return Mint(v)/=a;}
#define FRIEND(op) friend Mint operator op (int a,Mint b){ return Mint(a) op b; }
  FRIEND(+);
  FRIEND(-);
  FRIEND(*);
  FRIEND(/);
#undef FRIEND
  Mint operator+() const{return *this;}
  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}

  static Mint comb(long long n,int k){
    Mint num(1),dom(1);
    for(int i=0;i<k;i++){
      num*=Mint(n-i);
      dom*=Mint(i+1);
    }
    return num/dom;
  }

  friend ostream& operator<<(ostream&os,const Mint &m){os<<m.v;return os;}
  friend istream& operator>>(istream&is,Mint &m){is>>m.v;m.v%=MOD;if(m.v<0)m.v+=MOD;return is;}
};