#pragma once
#include "algebra/monoid/Min.cpp"
#include "algebra/monoid/Set.cpp"
template<typename X>
struct LazyRangeSetRangeMin{
  using MX=MonoidMin<X>;
  using MF=MonoidSet<X>;
  using F=typename MF::value_type;
  static constexpr X mapping(const F&f,const X&x){
    return f.value_or(x);
  }
};