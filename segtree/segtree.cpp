template<typename T>
struct SegmentTree{
  using F=function<T(T,T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;
  SegmentTree(){}
  SegmentTree(F f,T ti,int n_=1):f(f),ti(ti){
    n=1;
    while(n<n_)n<<=1;
    dat.assign(n<<1,ti);
  }
  SegmentTree(F f,T ti,const vector<T>&v):f(f),ti(ti){
    int n_=v.size();
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
    for(int i=0;i<n_;i++)dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  
  void init(int n_){
    n=1;
    while(n<n_)n<<=1;
    dat.assign(n<<1,ti);
  }
  
  void build(const vector<T>&v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++)dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }

  T operator [](int k) const{return dat[k+n];}
  
  void set_val(int k,T x){
    dat[k+=n]=x;  
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }
  
  T query(int a,int b){
    T vl=ti,vr=ti;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }
};