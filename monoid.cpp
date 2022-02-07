template<class T,T (*op)(T, T)>
struct AsMonoid {
  std::optional<T> v;
  AsMonoid():v(){}
  AsMonoid(T x):v(std::move(x)){}
  friend AsMonoid operator+(AsMonoid l, AsMonoid r){
    if(!l.v)return r;
    if(!r.v)return l;
    return AsMonoid(op(*l.v,*r.v));
  }
};

/*
使用例1
static constexpr auto f=[](int l, int r){
  return std::min(l, r);
};
using MinInt = AsMonoid<int, f>;
*/