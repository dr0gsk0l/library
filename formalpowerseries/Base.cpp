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
  using vector<T>::back;
  using vector<T>::pop_back;
  using value_type=T;

  void strict(int n){ if(size()>n)resize(n); }
  void shrink(){ while(size() and back()==0)pop_back(); }

  FormalPowerSeries(const vector<T>&f){
    int n=min(MX,int(f.size()));
    resize(n);
    REP_(i,n)at(i)=f[i];
    shrink();
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

  // *this = f_1 + f_2 x^n ⇒ [*this←f_1, return f_2]
  FPS separate(int n){
    if(size()<=n)return FPS(0);
    FPS f_2(size()-n);
    for(int i=n;i<size();i++)f_2[i-n]=at(i);
    strict(n);
    return f_2;
  }

  FPS operator()(FPS g)const{
    assert(!g.size() or g[0]==0); // 自身が多項式なら g[0]!=0 でも良い
    if(size()==0)return *this;
    if(size()==1)return FPS(1,at(0));
    if(size()==2)return FPS(at(0)+at(1)*g);

    int m=sqrt(MX/20);
    FPS&g1=g;
    FPS g2=g1.separate(m);

    int z;
    for(z=1;z<g1.size() and g1[z]==0;z++){}
    if(z==g1.size()){
      FPS res(0),
          g2pow=FPS::unit();
      for(int i=0;i*m<MX and i<size();i++,g2pow*=g2)
        res += at(i) * g2pow<<(i*m);
      return res;
    }
    
    //　f[l,l+d) ○ g1 を再帰で計算
    auto rec=[&](auto rec,int l,int d){
      if(d==0 or l>=size())return FPS(0);
      if(d==1)return FPS(1,at(l));
      if(d==2)return at(l) + (l+1<size()?at(l+1)*g1:FPS(0));
      FPS f1=rec(rec,l,d>>1);
      FPS f2=rec(rec,l+(d>>1),d-(d>>1));
      f2 *= g1.pow(d>>1);
      return f1+f2;
    };
    FPS res = rec(rec,0,size());

    FPS dfg=res,
        g1inv=(differential(g)>>(--z)).inv(),
        g2pow=FPS::unit();
    T factinv=1;
    
    for(int i=1;i*m<MX;i++){
      dfg=(differential(dfg)>>z)*g1inv;
      dfg.strict(MX-m*i);
      (g2pow*=g2).strict(MX-m*i);
      factinv /= i;
      res += factinv * (dfg * g2pow) << (m*i);
    }
    return res;
  }

  // f(x+c)
  void taylor_shift(T c){
    shrink();
    if(size()<=1 or c==0)return;
    int n=size();
    T fact=1;
    REP_(i,n){
      if(i)fact*=i;
      at(i)*=fact;
    }
    reverse(begin(),end());
    *this *= exp(c).pre(n);
    strict(n);
    reverse(begin(),end());
    T finv=fact.inv();
    for(int i=n-1;i>=0;i--){
      at(i)*=finv;
      finv *= i;
    }
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
  // exp(nx)
  static FPS exp(const T n){
    if(n==0)return unit();
    FPS res(MX,1);
    for(int i=1;i<MX;i++)res[i]=res[i-1]*n/i;
    return res;
  }
};
#undef REP_