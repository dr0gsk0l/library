#pragma once

template<typename X>
struct Monoid_Max{
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return max(x,y); }
  static constexpr X unit() { return numeric_limits<X>::min()/2; }
  static constexpr bool commute = true;
};