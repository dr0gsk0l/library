#pragma once
template<typename X>
struct Set{
  using O=optional<X>;
  using value_type=O;
  static constexpr O op(const O &x,const O &y)noexcept{ return (x.has_value()?x:y); }
  static constexpr O unit()noexcept{ return nullopt; }
  static constexpr bool commute=false;
};