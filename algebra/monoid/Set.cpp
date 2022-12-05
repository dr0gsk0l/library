#pragma once
// 合成の順番は関数と一緒だよ
template<typename X>
struct MonoidSet{
  using O=optional<X>;
  using value_type=O;
  static constexpr O op(const O &x,const O &y)noexcept{ return (x.has_value()?x:y); }
  static constexpr void Rchop(O&x, const O&y){ if(!x)x=y; }
  static constexpr void Lchop(const O&x, O&y){ if(x)y=x; } 
  static constexpr O unit()noexcept{ return nullopt; }
  static constexpr bool commute=false;
};