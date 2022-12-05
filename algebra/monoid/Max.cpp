template<typename X>
struct MonoidMax{
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return max(x,y); }
  static constexpr void Rchop(X&x, const X&y){ if(x<y)x=y; }
  static constexpr void Lchop(const X&x, X&y){ if(y<x)y=x; }
  static constexpr X unit() { return numeric_limits<X>::min()/2; }
  static constexpr bool commute = true;
};