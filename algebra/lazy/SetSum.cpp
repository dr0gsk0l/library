#pragma once
#include "algebra/group/CntSum.cpp"
#include "algebra/monoid/Set.cpp"
template<typename X>
struct LazySetSum{
  using MX=GroupCntSum<X>;
  using MF=MonoidSet<X>;
  using P=typename MX::value_type;
  using F=typename MF::value_type;
  static constexpr P mapping(const F&f,const P&x){
    if(f.has_value())return {f.value()*x.second,x.second};
    return x;
  }
};