#include "datastructure/UnionFind.cpp"
template<typename WG,typename E=typename WG::edge_type,typename W=typename WG::weight_type>
pair<W,vector<E>> minimum_spanning_tree(const WG&g){
  int n=g.n;
  UnionFind uf(n);
  auto edges=g.edges;
  sort(edges.begin(),edges.end(),[](const E&e1,const E&e2){
    return e1.weight<e2.weight;
  });
  W res=0;
  vector<E> tree;
  for(const auto&[from,to,weight]:edges){
    if(uf.same(from,to))continue;
    tree.emplace_back(from,to,weight);
    uf.merge(from,to);
    res+=weight;
  }
  assert(uf.count()==1);
  return {res,tree};
}