#define REP_(i,n) for(int i=0;i<(n);i++)
template<typename T,int MX>
struct FormalPowerSeries:vector<T>{
  using FPS=FormalPowerSeries<T,MX>;
  using vector<T>::resize;
  using vector<T>::size;
  using vector<T>::at;

  FormalPowerSeries()=default;
  FormalPowerSeries(int n,T a={}){
    resize(min(MX,n),a);
  }
  FormalPowerSeries(const vector<T>&f){
    int n=min(MX,int(f.size()));
    resize(n);
    REP_(i,n)at(i)=f[i];
  }
  FormalPowerSeries(const vector<pair<T,int>>&sparse){
    int n=0;
    for(const auto&[co,deg]:sparse)n=max(n,deg+1);
    n=min(MX,n);
    assign(n,T(0));
    for(const auto&[co,deg]:sparse)if(deg<n)at(deg)=co;
  }

  FPS operator-()const{
    FPS g=*this;
    for(T&a:g)a=-a;
    return g;
  }
  
  FPS &operator+=(const FPS &g){
    if(size()<g.size())resize(g.size());
    REP_(i,g.size())at(i)+=g[i];
    return *this;
  }
  FPS operator+(const FPS &g)const{return FPS(*this)+=g;}

  FPS &operator+=(const T &a){
    if(!size())resize(1);
    at(0)+=a;
    return *this;
  }
  FPS operator+(const T& a)const{return FPS(*this)+=a;}
  friend FPS operator+(const T&a,const FPS&f){return f+a;}

  FPS &operator-=(const FPS &g){
    if(size()<g.size())resize(g.size());
    REP_(i,g.size())at(i)-=g[i];
    return *this;
  }
  FPS operator-(const FPS &g)const{return FPS(*this)-=g;}

  FPS &operator-=(const T &a){
    if(!size())resize(1);
    at(0)-=a;
    return *this;
  }
  FPS operator-(const T& a){return FPS(*this)-=a;}
  friend FPS operator-(const T&a,const FPS&f){return a+(-f);}
  
  FPS operator*(const FPS&g)const{
    return FPS(convolution(*this,g));
  }

  FPS &operator*=(const FPS&g){
    return (*this)=(*this)*g;
  }

  FPS &operator*=(const T &a){
    REP_(i,size())at(i)*=a;
    return *this;
  }

  FPS operator*(const T &a)const{
    FPS res(*this);
    for(T&p:res)p*=a;
    return res;
  }
  friend FPS operator*(const T&a,const FPS&f){return f*a;}

  FPS operator/(const FPS g)const{
    return convolution(*this,g.inv());
  }

  FPS &operator/=(const FPS&g){
    return (*this)=(*this)/g;
  }

  FPS &operator/=(const T &a){
    REP_(i,size())at(i)/=a;
    return *this;
  }

  FPS inv()const{
    assert(size() and at(0)!=0);
    FPS res(1,at(0).inv());
    for(int i=0;(1<<i)<size();i++)res*=(2-res*(*this));
    return res;
  }

  void strict(int n){
    if(size()>n)resize(n);
  }

  FPS pow(int n)const{
    assert(n>=0);
    if(n==0)return FPS(1,1);
    if(n==1)return *this;
    return exp(n*log(*this));
  }

  FPS operator()(FPS f)const{
    if(size()==1)return FPS(1,at(0));
    if(size()==2)return FPS(at(0)+at(1)*f);
    int n=size()/2;
    FPS s=*this;
    s.strict(n);
    FPS t(size()-n);
    for(int i=n;i<size();i++)t[i-n]=at(i);
    return s(f)+f.pow(n)*t(f);
  }

  static FPS differential(const FPS f){
    if(f.size()<=1)return FPS(0);
    FPS res(f.size()-1);
    REP_(i,f.size()-1)res[i]=(i+1)*f[i+1];
    return res;
  }

  static FPS integral(const FPS f){
    FPS res(f.size()+1,0);
    REP_(i,f.size())res[i+1]=f[i]/(i+1);
    return res;
  }

  static FPS log(const FPS f){
    return integral(differential(f)/f);
  }

  static FPS exp(const FPS f){
    FPS res(1,1);
    for(int i=0;(1<<i)<MX;i++)res*=f+T(1)-log(res);
    return res;
  }
};
#undef REP_