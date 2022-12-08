#pragma once
template<typename CHAR,int SIGMA,typename COUNT=int>
class Trie{
  struct Node{
    array<int,SIGMA> nxt;
    COUNT count,//自分の個数
          ancestor_count;//（自分を含まない）子孫の個数
    Node():,count(0),ancestor_count(0){
      fill(nxt.begin(),nxt.end(),-1);
    }
  };
  vector<Node> nodes;

  inline int& nxt(int now,const CHAR&a){ return nodes[now].nxt[a]; }
public:
  Trie():nodes(1,Node()){}
  
  int add(const vector<CHAR>&v,COUNT num=1){
    int now=0;
    for(const CHAR&a:v){
      assert(0<=a and a<SIGMA);
      if(!~nxt(now,a)){
        nxt(now,a)=nodes.size();
        nodes.emplace_back();
      }
      nodes[now].ancestor_count+=num;
      now=nxt(now,a);
    }
    nodes[now].count+=num;
    return now;
  }
  int node_idx(const vector<CHAR>&v)const{
    // s の Node を返す　追加されて無ければ -1
    int now=0;
    for(const CHAR&a:v){
      if(!~nxt(now,a))return -1;
      now=nxt(now,a);
    }
    return now;
  }
  COUNT count(const vector<CHAR>&v)const{
    int id=node_idx(s);
    return (~id?nodes[id].count:0);
  }
  //vは含まない
  COUNT prefix_count(const vector<CHAR>&v)const{
    int now=0;
    COUNT sum=0;
    for(const CHAR&a:v){
      if(!~nxt(now,a))break;
      sum+=nodes[now].count;
      now=nxt(now,c);
    }
    return sum;
  }
  //vは含まない
  COUNT suffix_count(const vector<CHAR>&v)const{
    int id=node_idx(s);
    return (~id?nodes[id].ancestor_count:0);
  }

  COUNT size()const{ return nodes[0].ancestor_count; }

  // 辞書順, 0-indexed で並べた際の k 番目を出力
  vector<CHAR> k_th(COUNT k)const{
    assert(size()>k);
    vector<CHAR> res;
    int now=0;
    while(true){
      if(nodes[now].count>k)return res;
      k-=nodes[now].count;
      for(int i=0;i<SIGMA;i++){
        int to=nxt(now,i);
        if(to==-1)continue;
        COUNT c=nodes[to].count + nodes[to].ancestor_count;
        if(c<=k)k-=c;
        else{
          now=to;
          res.push_back(i);
          break;
        }
      }
    }
    return res; // ここに来ることは無い
  }
};