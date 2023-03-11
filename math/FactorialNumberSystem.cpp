#pragma once
#include "datastructure/FenwickTree.cpp"
namespace factorial_number_system{
  // vector<int> で表す
  // v[i]*i! の総和を表現している(0<=v[i]<=i)
  // 特に v[0]=0 は確定

  // N 桁の階乗進数 K に対して、N の順列で 0-indexed K 番目を返す
  static vector<int> to_permutation(const vector<int>&v){
    int N=v.size();
    vector<int> p(N);
    FenwickTree<GroupAdd<int>> ft(vector<int>(N,1));
    for(int i=0;i<N;i++){
      p[i]=ft.kth(v[N-1-i]);
      ft.add(p[i],-1);
    }
    return p;
  }

  // N の順列が 0-indexed K 番目であるとき、N 桁の階乗進数 K を返す
  static vector<int> to_factorial(const vector<int>&p){
    int N=p.size();
    vector<int> v(N);
    FenwickTree<GroupAdd<int>> ft(vector<int>(N,1));
    for(int i=0;i<N;i++){
      int k=ft.sum(p[i]);
      v[N-1-i]=k;
      ft.add(p[i],-1);
    }
    return v;
  }

  // N 桁の階乗進数の和 mod N!
  vector<int> sum(vector<int> p,const vector<int>&q){
    int N=p.size();
    assert(q.size()==N);
    for(int i=0;i<N;i++){
      p[i] += q[i];
      if(p[i]>i){
        p[i]-=i+1;
        if(i+1<N)p[i+1]++;
      }
    }
    return p;
  }

  // sum(p,q)=0 となる q を返す
  vector<int> inv(vector<int> p){
    int N=p.size();
    vector<int> q(N);
    for(int i=0;i<N;i++){
      if(p[i]){
        q[i] = i+1-p[i];
        if(i+1<N)p[i+1]++;
      }
      else q[i]=0;
    }
    return q;
  }
}
