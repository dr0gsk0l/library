template<typename GRAPH>
GRAPH reverse_graph(const GRAPH&g){
  GRAPH r(g.n);
  for(const auto&e:g.edges)
    r.add_arc(e.to,e.from,e.cost);
  r.build();
  return r;
}