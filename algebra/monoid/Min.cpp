template<typename X>
struct MonoidMin{
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return min(x,y); }
  static constexpr X unit() { return numeric_limits<X>::max()/2; }
  static constexpr bool commute = true;
};