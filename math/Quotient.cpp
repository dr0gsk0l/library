#pragma once
struct Quotient{
  // f(l,r,k) : {x\in[l,r] | floor(n/x)=k} についての操作
  template<typename T,typename F>
  static void enum_quotient(T n,const F&f){
    T l,r;
    for(l=1; l*l<=n; l++){
      T k = n/(double)l;
      f(l,l,k);
    }
    for(T k = n/(double); k; l=r+1,k--){
      r = n/(double)k;
      f(l,r,k);
    }
  }
};