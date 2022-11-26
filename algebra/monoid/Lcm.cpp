template<typename X>
struct MonoidLcm{
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return x/gcd(x,y)*y; }
  static constexpr X unit() { return 1; }
  static constexpr bool commute = true;
};