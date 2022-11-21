template<typename Monoid>
class CumulativeSum{
  using T=typename Monoid::value_type;
  vector<T> pre,suf;
public:
  CumulativeSum():pre(1,Monoid::unit()),sum(pre){}
  CumulativeSum(const vector<T>&v):pre(v.size()+1,Monoid::unit()),sum(pre){
    for(int i=0;i<v.size();i++)pre[i+1]=Monoid::op(pre[i],v[i]);
    for(int i=v.size()-1;i>=0;i--)suf[i]=Monoid::op(v[i],suf[i+1]);
  }
  //[0,r)
  T pre_sum(int r){ return pre[r]; }
  // [l,n)
  T suf_sum(int l){ return suf[l]; }

  T sum(){ return pre.back(); }
}