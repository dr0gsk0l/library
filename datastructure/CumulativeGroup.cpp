template<typename Group>
struct CumulativeGroup{
  using T=typename Group::value_type;
  vector<T> A;
  CumulativeGroup():A(1,Group::unit()){}
  CumulativeGroup(const vector<T>&v):A(v.size()+1,Group::unit()){
    for(int i=0;i<v.size();i++)A[i+1]=Group::op(A[i],v[i]);
  }
  void add(const T&a){ A.push_back(Group::op(A.back()+a)); }
  U sum(int l,int r){
    assert(0<=l and l<=r and r<A.size());
    return Group::op(A[r],Group::inverse(A[l])); 
  }
  U sum(){ return A.back(); }
};