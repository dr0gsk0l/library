```cpp
template<typename X>
struct A{
  using value_type=X
  static constexpr X op(const X& x, const X& y)
  static constexpr X power(const X& x, const long long n)
  static constexpr X unit()
  static constexpr bool commute
};
```