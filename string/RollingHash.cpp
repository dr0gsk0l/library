// reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
#pragma once
#include "mod/Modint61.cpp"
random_device rollonghash_rnd;
mt19937 rollonghash_mt(rollonghash_rnd());
class RollingHash{
  using ll=long long;
  inline static const Modint61 base=Modint61::raw(rollonghash_mt()%10000000+2);

  static Modint61 nxt_hash(Modint61 x,char c){ return (x*base)+Modint61::raw(c); }

  vector<Modint61> hash,power;
  int n;
public:
  RollingHash(const string&s):n(s.size()),hash(s.size()+1,0),power(s.size()+1,1){
    for(int i=0;i<n;i++){
      hash[i+1]=nxt_hash(hash[i],s[i]);
      power[i+1]=power[i]*base;
    }
  }
  
  ll get_hash(int l=0,int r=-1){
    if(r<0)r=n;
    return (hash[r]-hash[l]*power[r-l]).v;
  }
  
  static ll full_hash(const string&s){
    Modint61 res=0;
    for(const char&c:s)res=nxt_hash(res,c);
    return res.v;
  }
};