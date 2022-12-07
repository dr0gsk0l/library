```cpp
#pragma once
#include "algebra/M1"
#include "algebra/M2"
template<typename X,typename Y>
struct HogeHuga{
  using MX=M1<X>;
  using MF=M2<Y>;
  static constexpr MX::value_type mapping(const MF::value_type&f,const MX::value_type&x)
};
```

* ```Y``` は無い事も多い
* 名前の付け方は作用素→区間和の順
* ```MX::value_type = X``` の場合などは単に ```X``` と書けば良い
* ```MF::value_type``` についても同様
* 可読性のため ```using F=MF::value_type``` などを書いても良い（外から ```F``` を呼び出すことは無い）
