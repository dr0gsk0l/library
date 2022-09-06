#pragma once

template<typename X>
struct Monoid_Gcd{
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return gcd(x,y); }
  static constexpr X unit() { return 0; }
  static constexpr bool commute = true;
};