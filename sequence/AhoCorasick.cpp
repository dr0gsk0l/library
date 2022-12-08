#pragma once
#include "sequence/Trie.cpp"
template<typename CHAR,int SIGMA,typename COUNT=int>
struct AhoCorasick:Trie<CHAR,SIGMA,COUNT>{
  using super=Trie<CHAR,SIGMA,COUNT>;
  using super::nodes,super::nxt;
  
  vector<int> suffix;
 
  void build(){
    suffix.resize(nodes.size());
    queue<int> que;
    que.emplace(0);
    while(que.size()){
      int now=que.front();que.pop();
      for(int i=0;i<SIGMA;i++){
        int&nxt_id=nodes[now].nxt[i];
        if(~nxt_id){
          suffix[nxt_id]=(now?nodes[suffix[now]].nxt[i]:0);
          que.push(nxt_id);
        }
        else nxt_id=(now?nodes[suffix[now]].nxt[i]:0);
      }
    }
  }
 
  COUNT match_count(const vector<CHAR>&v){
    int now=0;
    COUNT res=0;
    for(const CHAR&a:v){
      now=nxt(now,a);
      res+=nodes[now].count;
    }
    return res;
  }
};