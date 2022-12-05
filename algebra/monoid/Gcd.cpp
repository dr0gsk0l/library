template<typename X>
struct MonoidGcd{
  using value_type = X;
  static constexpr X op(const X&x, const X&y) noexcept { return gcd(x,y); }
  static constexpr void Rchop(X&x, const X&y){ x=gcd(x,y); }
  static constexpr void Lchop(const X&x, X&y){ y=gcd(x,y); }
  static constexpr X unit() { return 0; }
  static constexpr bool commute = true;
};