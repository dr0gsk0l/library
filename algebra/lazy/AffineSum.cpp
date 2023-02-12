#pragma once
#include "algebra/group/CntSum.cpp"
#include "algebra/group/Affine.cpp"
template<typename X>
struct LazyAffineSum{
  using MX=GroupCntSum<X>;
  using MF=GroupAffine<X>;
  using P=typename MX::value_type;
  using F=typename MF::value_type;
  static constexpr P mapping(const F&f,const P&x){
    return {f.a*x.first+f.b*x.second, x.second};
  }
};
