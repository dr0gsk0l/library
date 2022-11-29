#pragma once
#include "algebra/group/Add.cpp"
#include "algebra/monoid/Min.cpp"
template<typename X>
struct LazyAddMin{
  using MX=MonoidMin<X>;
  using MF=GroupAdd<X>;
  static constexpr X mapping(const X&f,const X&x){
    return f+x;
  }
};