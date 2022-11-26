template<typename X>
struct GroupXor {
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return x ^ y; }
  static constexpr X inverse(const X &x) noexcept { return x; }
  static constexpr X power(const X &x, long long n) noexcept { return (n&1?x:0); }
  static constexpr X unit() { return X(0); }
  static constexpr bool commute = true;
};