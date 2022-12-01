// グラフ内に負閉路が存在するか
template<typename WG>
bool negative_cycle_find(const WG&g){
  using W=typename WG::weight_type;
  int n=g.n;
  vector<W> d(n,0);
  while(n--){
    bool update=false;
    for(const auto&e:g.edges)
      if(d[e.to]>d[e.from]+e.weight){
        d[e.to]=d[e.from]+e.weight;
        update=true;
      }
    if(!update)return false;
  }
  return true;
}