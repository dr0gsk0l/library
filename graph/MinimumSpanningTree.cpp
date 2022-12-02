#include "datastructure/UnionFind.cpp"
template<typename WG,typename W=typename WG::weight_type>
pair<W,vector<int>> minimum_spanning_tree(const WG&g){
  assert(g.is_prepared());
  int n=g.n,m=g.edges.size();
  UnionFind uf(n);
  vector<int> id(m);
  iota(id.begin(),id.end(),0);
  sort(id.begin(),id.end(),[&](const int i,const int j){
    return g.edges[i].weight<g.edges[j].weight;
  });
  W res=0;
  vector<int> tree;
  tree.reserve(n-1);
  for(int i:id){
    const auto&[from,to,weight]=g.edges[i];
    if(uf.same(from,to))continue;
    tree.push_back(i);
    uf.merge(from,to);
    res+=weight;
  }
  assert(uf.count()==1);
  return {res,tree};
}