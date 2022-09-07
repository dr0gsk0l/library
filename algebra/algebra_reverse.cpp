template<typename Algebra>
struct Algebra_Reverse:Algebra{
  using X=typename Algebra::value_type;
  static constexpr X op(const X& x, const X& y){ return Algebra::op(y,x); }
};