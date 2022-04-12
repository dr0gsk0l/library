template<typename T>
struct RangeTree{
  typedef vector<T> V;
  int n;
   
  vector<V> dat;

  static constexpr auto V_merge=[](const V&a,const V&b){
    V res;
    int aid=0,bid=0;
    while(aid<a.size() or bid<b.size())
      if(aid==a.size() or (bid<b.size() and a[aid]>b[bid]))
        res.push_back(b[bid++]);
      else
        res.push_back(a[aid++]);
    return res;
  };
  
  RangeTree(){}; 
  RangeTree(int n_){
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,V());
  }
  RangeTree(const V &v){
    int n_=v.size();
    n=1;
    while(n<n_)n<<=1;
    dat.assign(n<<1,V());
    for(int i=0;i<n_;i++)dat[n+i]=V(1,v[i]);
    for(int i=n-1;i;i--)dat[i]=V_merge(dat[2*i],dat[2*i+1]);
  }
  
  void set_val(int idx,T x){
    dat[idx+=n]=V(1,x);  
    while(idx>>=1)dat[idx]=V_merge(dat[2*idx],dat[2*idx+1]);
  }
  
  /*
  [a,b)の範囲でのcheck結果の総和を返す Rmergeは結合法則満たす
  例えば Q(v)=v内のk以上の個数 , Rmerge(a,b)=a+b とか
  */

  template<typename R>
  R query(int a,int b,function<R(const &V)> Q,function<R(R,R)> Rmerge){
    R vl,vr;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
      if(l&1)vl=Rmerge(vl,Q(dat[l++]));
      if(r&1)vr=Rmerge(dat[--r],vr);
    }
    return Rmerge(vl,vr);
  }
};