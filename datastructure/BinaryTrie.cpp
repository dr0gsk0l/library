template<int LOG,typename COUNT>
class BinaryTrie{
  using T=conditional_t< LOG<=32, unsigned int, unsigned long long >;
  struct Node{
    array<int,2> nxt;
    COUNT count; //
    Node():count(0){
      fill(nxt.begin(),nxt.end(),-1);
    }
  };
  vector<Node> nodes;
  inline int& nxt(int now,int a){ return nodes[now].nxt[a]; }
  inline int bit(const T&a,int i)const{ return (a>>i)&1; }
public:
  Trie():nodes(1,Node()){}

  int add(const T&a,COUNT num=1){
    int now=0;
    for(T i=LOG-1;i>=0;i--){
      if(!~nxt(now,bit(a,i))){
        nxt(now,bit(a,i))=nodes.size();
        nodes.emplace_back();
      }
      nodes[now].count+=num;
      now=nxt(now,bit(a,i));
    }
    nodes[now].count+=num;
    return now;
  }

  int node_idx(const T&a)const{
    int now=0;
    for(T i=LOG-1;i>=0;i--){
      if(!~nxt(now,bit(a,i)))return -1;
      now=nxt(now,bit(a,i));
    }
    return now;
  }
  COUNT count(const T&a)const{
    int id=node_idx(a);
    return (~id?nodes[id].count:0);
  }

  COUNT size()const{ return nodes[0].count; }

  // 数列の各数に xor_add をした後、0-indexed で昇順 k 番目を出力
  T k_th(COUNT k, T xor_add=0)const{
    assert(size()>k);
    T res=0;
    int now=0;
    for(T i=LOG-1;i>=0;i--){
      int f=bit(xor_add,i);
      int s=f^1;
      if(nxt(now,f)==-1){
        now=nxt(now,s);
        continue;
      }
      if(nodes[nxt(now,f)].count<=k){
        k-=nodes[nxt(now,f)].count;
        now=nodes[nxt(now,s)];
        res+=1<<i;
      }
      else
        now=nodes[nxt(now,f)];
    }
    return res;
  }
  T min(T xor_add=0)const{ return k_th(0,xor_add); }
  T max(T xor_add=0)const{ return k_th(size()-1,xor_add); }
};