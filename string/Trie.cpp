template<int char_size,int margin>
struct Trie{
  struct Node{
    array<int,char_size> nxt;
    int pre,//手前
        count,//自分の個数
        ancestor_count;//（自分を含まない）子孫の個数
    Node(int pre):pre(pre),count(0),ancestor_count(0){
      fill(nxt.begin(),nxt.end(),-1);
    }
  };
 
  vector<Node> nodes;
  Trie():nodes(1,Node(-1)){}
  
  inline int& nxt(int now,int c){
    return nodes[now].nxt[c-margin];
  }
 
  int add(const string&s,int num=1){
    int now=0;
    for(const char&c:s){
      if(!~nxt(now,c)){
        nxt(now,c)=nodes.size();
        nodes.emplace_back(Node(now));
      }
      nodes[now].ancestor_count+=num;
      now=nxt(now,c);
    }
    nodes[now].count+=num;
    return now;
  }
 
  int node_idx(const string&s){
    // s の Node を返す　追加されて無ければ -1
    int now=0;
    for(const char&c:s){
      if(!~nxt(now,c))return -1;
      now=nxt(now,c);
    }
    return now;
  }
 
  int count(const string&s){
    int a=node_idx(s);
    return (~a?nodes[a].count:0);
  }
 
  //sは含まない
  int preifx_count(const string&s){
    int now=0,sum=0;
    for(const char&c:s){
      if(!~nxt(now,c))break;
      sum+=nodes[now].count;
      now=nxt(now,c);
    }
    return sum;
  }
 
  //sは含まない
  int ancestor_count(const string&s){
    int a=node_idx(s);
    return (~a?nodes[a].ancestor_count:0);
  }
};