#pragma once
#include "algebra/group/CntSum.cpp"
#include "algebra/group/Add.cpp"
template<typename X>
struct LazyRangeAddRangeSum{
  using MX=GroupCntSum<X>;
  using MF=GroupAdd<X>;
  using S=typename MX::value_type;
  static constexpr S mapping(const X&f,const S&x){
    return {x.first+f*x.second,x.second};
  }
};