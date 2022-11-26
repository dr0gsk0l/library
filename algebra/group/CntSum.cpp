template<typename X>
struct GroupCntSum{
  using P=pair<X,X>;
  using value_type=P;
  static constexpr P op(const P &x, const P &y){
    return {x.first + y.first, x.second + y.second};
  }
  static constexpr P inverse(const P &x){ return {-x.fi, -x.se}; }
  static constexpr P unit() { return {0, 0}; }
  static constexpr bool commute = true;
};