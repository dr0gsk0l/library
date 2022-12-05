// op(f,g) = f(g(x))
template<typename K>
struct GroupAffine{
  using F = pair<K, K>;
  using value_type = F;
  static constexpr F op(const F &f, const F &g) noexcept {
    return F({f.first * g.first, f.first * g.second + f.second});
  }
  static constexpr void Rchop(F&f, const F&g){
    f.second += f.first*g.second;
    f.first *= g.first;
  }
  static constexpr void Lchop(const F&f, F&g){
    (g.second *= f.first) += f.second;
    g.first *= f.first;
  }
  static constexpr F inverse(const F &x) {
    auto [a, b] = x; assert(a!=0);
    a = K(1) / a;
    return {a, a * (-b)};
  }
  /*
  static constexpr F power(const F& f,long long n) noexcept {
    if(a==1)return {1,n*b};
    K an=power(a,n);
    return {an,b*((1-an)/(1-a))};
  }
  */
  static constexpr F unit() { return {K(1), K(0)}; }
  static constexpr bool commute = false;

  static constexpr K eval(const F &f, K x) noexcept {
    return f.first * x + f.second;
  }
};