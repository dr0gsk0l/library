#pragma once
#include "algebra/group/CntSum.cpp"
#include "algebra/group/Affine.cpp"
template<typename X>
struct LazyRangeAffineRangeSum{
  using MX=GroupCntSum<X>;
  using MF=GroupAffine<X>;
  using P=typename MX::value_type;
  using F=typename MF::value_type;
  static constexpr P mapping(const F&f,const P&x){
    return {f.first*x.first+f.second*x.second, x.second};
  }
};
