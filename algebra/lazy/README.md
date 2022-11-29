```cpp
#pragma once
#include "algebra/M1"
#include "algebra/M2"
template<typename X,typename Y> // Y は無いことも多い
struct LazyHogeHuga{ // Hoge が作用素、 Huga が区間和
  using MX=M1<X>;
  using MF=M2<Y>;
  static constexpr MX::value_type mapping(const MF::value_type&f,const MX::value_type&x)
  // MX::value_type = X の場合などは単に X と書けば良い
  // using F=MF::valuetype などを先に書いても良い
};
```
