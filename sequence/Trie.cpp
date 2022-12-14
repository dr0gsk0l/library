#pragma once
#include "algebra/group/Add.cpp"
template<typename CHAR,int SIGMA,typename AbelMonoid=GroupAdd<int>>
class Trie{
  using X=typename AbelMonoid::value_type;
  struct Node{
    array<int,SIGMA> nxt;
    int pre;
    X val,suffix_val; // suffix_val は自身を含まない
    Node(int pre):pre(pre),val(AbelMonoid::unit()),suffix_val(AbelMonoid::unit()){
      fill(nxt.begin(),nxt.end(),-1);
    }
  };
  vector<Node> nodes;
public:
  Trie():nodes(1,Node(-1)){}

  int& nxt(int now,const CHAR&a){ return nodes[now].nxt[a]; }
  
  int add(const vector<CHAR>&v,X x=1){
    int now=0;
    for(const CHAR&a:v){
      assert(0<=a and a<SIGMA);
      if(!~nxt(now,a)){
        nxt(now,a)=nodes.size();
        nodes.emplace_back(now);
      }
      AbelMonoid::Rchop(nodes[now].suffix_val,x);
      now=nxt(now,a);
    }
    AbelMonoid::Rchop(nodes[now].val,x);
    return now;
  }
  int node_idx(const vector<CHAR>&v){
    // s の Node を返す　追加されて無ければ -1
    int now=0;
    for(const CHAR&a:v){
      if(!~nxt(now,a))return -1;
      now=nxt(now,a);
    }
    return now;
  }
  X val(const vector<CHAR>&v){
    int id=node_idx(v);
    return ( ~id ? nodes[id].val : AbelMonoid::unit());
  }
  X& val(int node_id){ return nodes[node_id].val; }
  //vは含まない
  X prefix_prod(const vector<CHAR>&v){
    int now=0;
    X sum=AbelMonoid::unit();
    for(const CHAR&a:v){
      if(!~nxt(now,a))break;
      AbelMonoid::Rchop(sum,nodes[now].val);
      now=nxt(now,a);
    }
    return sum;
  }
  //vは含まない
  X suffix_prod(const vector<CHAR>&v)const{
    int id=node_idx(v);
    return (~id?nodes[id].suffix_val:AbelMonoid::unit());
  }
  vector<CHAR> restore(int node_id){
    assert(0<=node_id and node_id<nodes.size());
    vector<CHAR> res;
    while(~nodes[node_id].pre){
      int p=nodes[node_id].pre;
      for(int p:nodes[p].nxt)if(p==node_id)res.push_back(p);
      node_id=p;
    }
    reverse(res.begin(),res.end());
    return res;
  }
  X prod()const{ return nodes[0].suffix_val; }
  int size()const{ return nodes.size(); }

  template<typename F>
  void query(const vector<CHAR>&v,const F&f,int l=0,int r=-1){
    if(r<0)r=v.size();
    int now=0;
    for(int i=l;i<r;i++){
      now=nxt(now,v[i]);
      if(~now)f(now);
      else break;
    }
  }
};