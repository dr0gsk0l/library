#pragma once
// 宣言はグローバルでする
// https://twitter.com/climpet/status/1598974781138694144
template<int MAX,bool PRIME_FACTOR=false,bool DIVISOR=false>
class PrimeUtil{
  using ll=long long;
  array<bool,MAX+1> isP;
  ll pow2(ll a){ return a*a; }
public:
  vector<int> primes;
  conditional_t< PRIME_FACTOR, array< vector<pair<int,int>>, MAX+1 >, bool> prime_factor;
  conditional_t< DIVISOR, array< vector<int>,MAX+1 >, bool> divisor; // 自明な約数は入らない
  
  PrimeUtil(){
    fill(isP.begin(),isP.end(),true);
    isP[0]=isP[1]=false;
    primes.reserve(MAX/10);
    for(int i=2;i<=MAX;i++){
      // 約数列挙
      if constexpr(DIVISOR){
        for(int j=2*i;j<=MAX;j+=i)
          divisor[j].push_back(i);
      }
      // エラトステネスの篩
      if(!isP[i])continue;
      primes.push_back(i);
      for(ll j=pow2(i);j<=MAX;j+=i)isP[j]=false;
      // 素因数分解
      if constexpr(PRIME_FACTOR){
        for(int j=i;j<=MAX;j+=i)prime_factor[j].emplace_back(i,1);
        int limit=MAX/i+1;
        for(ll j=pow2(i);j<=MAX;j*=i){
          for(int k=j;k<=MAX;k+=j)
            prime_factor[k].second++;
          if(j>limit)break;
        }
      }
    }
  }

  bool is_prime(ll x){
    if(x<=MAX)return isP[x];
    for(int p:primes){
      if(pow2(p)>x)return true;
      if(x%p==0)return false;
    }
    for(int p=primes.back()+1;pow2(p)<=x;p++)
      if(x%p==0)return false;
    return true;
  }
};