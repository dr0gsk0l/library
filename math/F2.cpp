#pragma once
template<typename T,int LOG>
class F2{
  bool is_sorted;
  vector<T> B;
  void xor_chmin(T&a,T b){ a=min(a,a^b); }
public:
  F2():is_sorted(true){}
  F2(const vector<T>&v):is_sorted(true){
    for(const T&a:v)add(a);
  }

  void add(T a){
    if(B.size()==LOG)return;
    for(T e:B)xor_chmin(a,e);
    if(a){
      for(T&e:B)xor_chmin(e,a);
      if(B.size() and B.back()>a)is_sorted=false;
      B.push_back(a);
    }
  }

  vector<T> base(){
    if(!is_sorted){
      sort(B.begin(),B.end());
      is_sorted=true;
    }
    return B;
  }

  T kth_smallest(T k){
    assert( !(k>>(B.size())) );
    if(k==0)return 0;
    if(!is_sorted){
      sort(B.begin(),B.end());
      is_sorted=true;
    }
    T res=0;
    for(int i=0;i<B.size();i++)if((k>>i)&1)
      res ^= B[i];
    return res;
  }
  T kth_largest(T k){
    assert( !(k>>(B.size())) );
    return kth_smallest((T{1}<<B.size()) - k - 1);
  }
};