template<typename Lazy>
class DualSegmentTree{
  using MX = typename Lazy::MX;
  using MF = typename Lazy::MF;
  using X = typename MX::value_type;
  using F = typename MF::value_type;
  int n,log,size;
  vector<X> dat;
  vector<F> laz;

  void point_apply(int k,const F&f){
    if(k<size)MF::Lchop(f,laz[k]);
    else dat[k-size]=Lazy::mapping(f,dat[k-size]);
  }
  void push(int k){
    point_apply(2*k,laz[k]);
    point_apply(2*k+1,laz[k]);
    laz[k]=MF::unit();
  }
  void thrust(int k){ for(int i=log;i;i--)push(k>>i); }

public:
  DualSegmentTree() : DualSegmentTree(0) {}
  DualSegmentTree(int n):DualSegmentTree(vector<X>(n,MX::unit())) {}
  DualSegmentTree(const vector<X>&v) : n(v.size()),dat(v) {
    for(log=1;(1<<log)<n;log++){}
    size=1<<log;
    laz.assign(size,MF::unit());
  }

  void set(int p,X x){
    assert(0<=p and p<n);
    thrust(p+size);
    dat[p]=x;
  }

  X operator[](int p){
    assert(0<=p and p<n);
    thrust(p+size);
    return dat[p];
  }

  void apply(int l,int r,F f){
    assert(0 <= l && l <= r && r <= n);
    if(l==r)return;
    thrust(l+=size);
    thrust(r+=size-1);
    for(int L=l,R=r+1;L<R;L>>=1,R>>=1){
      if(L&1)point_apply(L++,f);
      if(R&1)point_apply(--R,f);
    }
  }
};