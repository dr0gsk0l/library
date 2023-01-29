#pragma once
#define REP_(i,n) for(int i=0;i<(n);i++)
template<typename T,int MX>
struct FormalPowerSeries:vector<T>{
  using FPS=FormalPowerSeries;
  using vector<T>::resize;
  using vector<T>::size;
  using vector<T>::at;
  using vector<T>::assign;
  using vector<T>::vector;
  using vector<T>::begin;
  using vector<T>::end;

  void strict(int n){ if(size()>n)resize(n); }

  FormalPowerSeries(const vector<T>&f){
    while(f.size() and f.back()==0)f.pop_back();
    int n=min(MX,int(f.size()));
    resize(n);
    REP_(i,n)at(i)=f[i];
  }

  static FPS unit(){ return {1}; }
  static FPS x(){ return {0,1}; }
#pragma region operator
  FPS operator-()const{
    FPS g=*this;
    for(T&a:g)a=-a;
    return g;
  }
  
  FPS &operator+=(const FPS&g){
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
  
  FPS operator*(const FPS&g)const{ return FPS(convolution(*this,g)); }
  FPS&operator*=(const FPS&g){ return (*this)=(*this)*g; }

  FPS&operator*=(const T &a){
    REP_(i,size())at(i)*=a;
    return *this;
  }
  FPS operator*(const T &a)const{ return FPS(*this)*=a; }
  friend FPS operator*(const T&a,const FPS&f){return f*a;}

  FPS operator/(const FPS g)const{ return (*this)*g.inv(); }
  FPS&operator/=(const FPS&g){ return (*this)=(*this)/g; }

  FPS&operator/=(const T &a){ return *this *= a.inv(); }
  FPS operator/(const T &a){ return  FPS(*this)/=a; }

  FPS&operator<<=(const int d){
    if(d>=MX)return *this=FPS(0);
    resize(min(MX,int(size())+d));
    for(int i=int(size())-1-d;i>=0;i--)
      at(i+d)=at(i);
    for(int i=d-1;i>=0;i--)at(i)=0;
    return *this;
  }
  FPS operator<<(const int d)const{ return FPS(*this)<<=d; }
  FPS&operator>>=(const int d){
    if(d>=size())return *this=FPS(0);
    for(int i=d;i<size();i++)
      at(i-d)=at(i);
    strict(int(size())-d);
    return *this;
  }
  FPS operator>>(const int d)const{ return FPS(*this)>>=d; }
#pragma endregion operator

  FPS pre(int n)const{
    if(size()<=n)return *this;
    return FPS(begin(),begin()+n);
  }

  FPS inv()const{
    assert(size() and at(0)!=0);
    FPS res(1,at(0).inv());
    for(int n=0;(1<<n)<MX;n++){
      // mod[1<<n] → mod[1<<(n+1)]
      res *= (2- (res*pre(1<<(n+1))).pre(1<<(n+1)));
      res.strict(1<<(n+1));
    }
    return res;
  }

  FPS pow(int n)const{
    assert(n>=0);
    if(n==0)return unit();
    if(n==1)return *this;
    if(at(0)==1)return exp(n*log(*this));
    FPS res=unit(),now=*this;
    while(n){
      if(n&1)res*=now;
      now*=now;
      n>>=1;
    }
    return res;
  }

  FPS operator()(FPS f)const{
    assert(!f.size() or f[0]==0); // 自身が多項式なら f[0]!=0 でも良い
    if(size()==1)return FPS(1,at(0));
    if(size()==2)return FPS(at(0)+at(1)*f);
    int n=size()/2;
    FPS s=*this;
    s.strict(n);
    FPS t(size()-n);
    for(int i=n;i<size();i++)t[i-n]=at(i);
    return s(f)+f.pow(n)*t(f);
  }

  static FPS differential(FPS f){
    if(f.size()<=1)return FPS(0);
    REP_(i,f.size()-1)f[i]=(i+1)*f[i+1];
    f.resize(f.size()-1);
    return f;
  }
  static FPS integral(FPS f){
    if(f.size()<MX)f.resize(f.size()+1);
    for(int i=f.size()-1;i>0;i--)f[i]=f[i-1]/i;
    f[0]=0;
    return f;
  }

  static FPS log(const FPS&f){
    assert(f.size() and f[0]==1);
    return integral(differential(f)/f);
  }
  static FPS exp(const FPS f){
    if(!f.size())return unit();
    assert(f[0]==0);
    FPS res=unit();
    for(int n=0;(1<<n)<MX;n++){
      // mod[1<<n] → mod[1<<(n+1)]
      res *= (f.pre(1<<(n+1))+1-log(res).pre(1<<(n+1)));
      res.strict(1<<(n+1));
    }
    return res;
  }
};
#undef REP_