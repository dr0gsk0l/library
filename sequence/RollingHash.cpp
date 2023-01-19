// reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
#pragma once
#include "mod/Modint61.cpp"
#include "sequence/ForString.cpp"

random_device rollonghash_rnd;
mt19937 rollonghash_mt(rollonghash_rnd());

template<typename CHAR=char, MINT=Modint61>
class RollingHash{
  using ll=long long;
  static constexpr ll mod = MINT.mod();
  using T = conditional_t< less<ll>(mod,ll(numeric_limits<int>::max())), int, ll>;
  inline static const MINT base=MINT::raw(rollonghash_mt()%(mod-2)+2);

  static MINT nxt_hash(MINT x,CHAR c){ return (x*base) + MINT::raw(c); }

  int n;
  vector<MINT> hash,power;
public:
  RollingHash(const vector<CHAR>&v):n(v.size()),hash(n+1,0),power(n+1,1){
    for(int i=0;i<n;i++){
      hash[i+1]=nxt_hash(hash[i],v[i]);
      power[i+1]=power[i]*base;
    }
  }
  
  T get_hash(int l=0,int r=-1){
    if(r<0)r=n;
    return (hash[r]-hash[l]*power[r-l]).v;
  }
  
  static T full_hash(const vector<CHAR>&v){
    MINT res=0;
    for(const char&c:v)res=nxt_hash(res,c);
    return res.v;
  }
};