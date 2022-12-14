#pragma once
#include "sequence/Trie.cpp"
template<typename CHAR,int SIGMA,typename AbelMonoid=GroupAdd<int>>
class AhoCorasick:Trie<CHAR,SIGMA,AbelMonoid>{
  using super=Trie<CHAR,SIGMA,AbelMonoid>;
  using super::nodes;
  using X=typename AbelMonoid::value_type;
  vector<int> suffix;
  bool prepared;
public:
  using super::nxt,super::add,super::node_idx,super::val,super::prefix_prod,super::suffix_prod,super::query,super::restore,super::prod,super::size;

  AhoCorasick():prepared(false){}

  bool is_prepared()const{ return prepared; }
 
  void build(){
    assert(!prepared);
    prepared=true;
    suffix.resize(nodes.size());
    queue<int> que;
    que.push(0);
    while(que.size()){
      int now=que.front();que.pop();
      for(int i=0;i<SIGMA;i++){
        int&nxt_id=nodes[now].nxt[i];
        if(~nxt_id){
          suffix[nxt_id]=(now?nodes[suffix[now]].nxt[i]:0);
          AbelMonoid::Rchop(val(nxt_id),val(suffix[nxt_id]));
          que.push(nxt_id);
        }
        else
          nxt_id=(now?nodes[suffix[now]].nxt[i]:0);
      }
    }
  }

  X path_prod(const vector<CHAR>&v){
    assert(prepared);
    X res=AbelMonoid::unit();
    int now=0;
    for(const CHAR&a:v){
      now=nxt(now,a);
      AbelMonoid::Rchop(res,val[now]);
    }
    return res;
  }
};