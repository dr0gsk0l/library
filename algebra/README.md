型を X とする  
必須要件などでは無く、単に関数名の統一のための備忘録  
実際には static constexpr を書く

## Monoid
```cpp
using value_type=X
X op(const X& x, const X& y)
X power(const X& x, const long long n)
X unit()
bool commute
```

## Group
```monoid```
```cpp
X inverse(const X& x)
```

### その他
型名は Monoid_Hoge や Group_Huga のように書き、Group の型は Monoid にもなるようにする  
Ring や Field に関しては未定  

例えば Group_Add は以下のように書くことで型を int,ll,modint,などに対応させられる  
一方で matrix は ``` X(0) ``` で加算単位元を返す実装にはおそらくしないので、operator が定義されていればいいと言うものでは無い  
```algebra_matrix``` と言う型を作っておくのはあり
```cpp
template<typename X>
struct Group_Add {
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return x + y; }
  static constexpr X inverse(const X &x) noexcept { return -x; }
  static constexpr X power(const X &x, long long n) noexcept { return X(n) * x; }
  static constexpr X unit() { return X(0); }
  static constexpr bool commute = true;
};
```
