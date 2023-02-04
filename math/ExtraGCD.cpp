#pragma once
using ll=long long;
pair<ll,ll> ext_gcd(ll a,ll b){
  if(b==0)return {1,0};
  auto [X,Y]=ext_gcd(b,a%b);
  // bX + (a%b)Y = gcd(a,b)
  // a%b = a - b(a/b)
  // ∴ aY + b(X-(a/b)Y) = gcd(a,b)
  ll x=Y,y=X-(a/b)*Y;
  return {x,y};
}
