#pragma once
template<typename GRAPH>
GRAPH reverse_graph(const GRAPH&g){
  GRAPH r(g.n);
  for(auto e:g.edges){
    swap(e.from,e.to);
    r.add_arc(e);
  }
  r.build();
  return r;
}