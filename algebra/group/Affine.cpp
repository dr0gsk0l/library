#pragma once
#include "linearalgebra/Linear.cpp"
template<typename T>
struct GroupAffine{
  using L = Line<T>;
  using value_type = L;
  static constexpr L op(const L&f, const L&g)noexcept{ return f(g); }
  static constexpr void Rchop(L&f, const L&g){
    f.b += f.a*g.b;
    f.a *= g.a;
  }
  static constexpr void Lchop(const L&f, L&g){
    (g.b *= f.a) += f.b;
    g.a *= f.a;
  }
  static constexpr L inverse(const L&f){ return f.inv(); }
  /*
  static constexpr L power(const L& f,long long n) noexcept {
    if(a==1)return {1,n*b};
    K an=power(a,n);
    return {an,b*((1-an)/(1-a))};
  }
  */
  static constexpr L unit(){ return L(1,0); }
  static constexpr bool commute = false;
};