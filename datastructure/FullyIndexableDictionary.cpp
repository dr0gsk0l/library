#pragma once
class FullyIndexableDictionary{
  int n,
      block; // 64個事に区切ったブロックの個数
  vector<unsigned long long> bit;
  vector<unsigned int> sum; // ブロック毎の累積和
  bool prepared;
public:
  FullyIndexableDictionary(){}
  FullyIndexableDictionary(int n)
    :n(n),block((n+63)>>6),bit(block,0),sum(block+1,0),prepared(false){}

  bool is_prepared(){ return prepared; }

  void set(int k){
    bit[k>>6]|=1ull<<(k&63);
    sum[(k>>6)+1]++;
  }
  void build(){ 
    assert(!prepared);
    prepared=true;
    for(int i=0;i<block;i++)sum[i+1]+=sum[i]; 
  }

  bool operator[](int k)const{
    return bool((bit[k>>6]>>(k&63))&1);
  }

  // [0,j) の合計
  int rank(int j,bool f=1){
    assert(prepared);
    int a=sum[j>>6]+__builtin_popcountll(bit[j>>6]&((1ull<<(j&63))-1));
    return (f?a:j-a);
  }
  // 0-indexed で k 番目の f の場所 
  int select(int k,bool f=1){
    assert(prepared);
    if(k<0 or rank(n,f)<=k)return -1;
    int l=0,r=n;
    while(r-l>1){
      int m=(l+r)>>1;
      (rank(m,f)>=k+1?r:l)=m;
    }
    return r-1;
  }
  // l以上で k 番目の f の場所
  int select(int k,bool f,int l){
    return select(rank(l,f)+k,f);
  }
};