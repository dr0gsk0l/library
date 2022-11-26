#include "string/Trie.cpp"

template<int char_size,int margin>
struct AhoCorasick:Trie<char_size,margin>{
  using super=Trie<char_size,margin>;
  using super::nodes,super::nxt;
  
  vector<int> suffix;
 
  void build(){
    suffix.resize(nodes.size());
    queue<int> que;
    que.emplace(0);
    while(que.size()){
      int now=que.front();que.pop();
      for(int i=0;i<char_size;i++){
        int&nxt_id=nodes[now].nxt[i];
        if(~nxt_id){
          suffix[nxt_id]=(now?nodes[suffix[now]].nxt[i]:0);
          que.push(nxt_id);
        }
        else nxt_id=(now?nodes[suffix[now]].nxt[i]:0);
      }
    }
  }
 
  int match_count(const string&s){
    int res=0,now=0;
    for(const char&c:s){
      now=nxt(now,c);
      res+=nodes[now].count;
    }
    return res;
  }
};