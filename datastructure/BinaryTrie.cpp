template<int LOG>
struct BinaryTrie{
  struct Node{
    array<int,2> nxt;
    int pre,//手前
        count,//自分の個数
        ancestor_count;//（自分を含まない）子孫の個数
    Node(int pre):pre(pre),count(0),ancestor_count(0){
      fill(nxt.begin(),nxt.end(),-1);
    }
  };
};