template <typename Monoid>
struct SegmentTree{
  int n;
  vector<Monoid> dat;
  SegmentTree(int n_):{
    n=1;
    while(n<n_)n<<=1;
    dat.assign(n<<1,{});
  }
  SegmentTree(const vector<Monoid> &v):{
    int n_=v.size();
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,{});
    for(int i=0;i<n_;i++)dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=dat[(i<<1)|0]+dat[(i<<1)|1];
  }
  
  Monoid operator [](int k) const{return dat[k+n];}
  
  void init(int n_){
    n=1;
    while(n<n_)n<<=1;
    dat.assign(n<<1,{});
  }
  
  void build(const vector<Monoid>&v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++)dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=dat[(i<<1)|0]+dat[(i<<1)|1];
  }
  
  void set_val(int k,Monoid x){
    dat[k+=n]=x;  
    while(k>>=1)
      dat[k]=dat[(k<<1)|0]+dat[(k<<1)|1];
  }

  Monoid query(int a,int b){
    Monoid vl{},vr{};
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=vl+dat[l++];
      if(r&1) vr=dat[--r]+vr;
    }
    return vl+vr;
  } 
};