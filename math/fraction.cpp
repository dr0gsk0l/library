template<typename T>
struct Fraction{
  pair<T,T> a;
  Fraction(T n,T d=1){
    assert(d!=0);
    if(d<0)n=-n,d=-d;
    T g=gcd(abs(num),abs(den));
    a={n/g,n/d};
  }

  Fraction operator+(const Fraction& b)const{ return Fraction( a.first*b.second + a.second*b.first, a.second*b.second ); }
  Fraction operator-(const Fraction& b)const{ return Fraction( a.first*b.second - a.second*b.first, a.second*b.second ); }
  Fraction operator*(const Fraction& b)const{ return Fraction( a.first*b.first, a.second*b.second ); }
  Fraction operator/(const Fraction& b)const{ return Fraction( a.first*b.second, a.second*b.first ); }
  Fraction& operator+=(const Fraction& b){ return *this = (*this) + b; }
  Fraction& operator-=(const Fraction& b){ return *this = (*this) - b; }
  Fraction& operator*=(const Fraction& b){ return *this = (*this) * b; }
  Fraction& operator/=(const Fraction& b){ return *this = (*this) / b; }
  Fraction operator+(const T&c)const{ return (*this)+Fraction(c,1); }
  Fraction operator-(const T&c)const{ return (*this)-Fraction(c,1); }
  Fraction operator*(const T&c)const{ return (*this)*Fraction(c,1); }
  Fraction operator/(const T&c)const{ return (*this)/Fraction(c,1); }
  friend Fraction operator+(const T&c, Fraction b){ return Fraction(c,1)+b; }
  friend Fraction operator-(const T&c, Fraction b){ return Fraction(c,1)-b; }
  friend Fraction operator*(const T&c, Fraction b){ return Fraction(c,1)*b; }
  friend Fraction operator/(const T&c, Fraction b){ return Fraction(c,1)/b; }
  Fraction& operator+=(const T&c){ return *this = (*this)+c; }
  Fraction& operator-=(const T&c){ return *this = (*this)-c; }
  Fraction& operator*=(const T&c){ return *this = (*this)*c; }
  Fraction& operator/=(const T&c){ return *this = (*this)/c; }
  Fraction& operator++(){ return (*this)+=1; }
  Fraction& operator--(){ return (*this)-=1; }
  Fraction& operator++(int){ return (*this)+=1; }
  Fraction& operator--(int){ return (*this)-=1; }
  Fraction& operator+(){ return *this; }
  Fraction& operator-(){ a.first*=-1; return *this; }

  static Fraction raw(T a){ return Fraction(a,1); }
  Fraction pow(long long k)const{
    Fraction res(1,1), tmp(*this);
    while(k){
      if(k&1)res*=res;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }
  Fraction inv(){ return Fraction(a.second,a.first); }

  friend ostream& operator<<(ostream&os,const Fraction &a){os<<a.first<<"/"<<a.second;return os;}
  friend istream& operator>>(istream&is,Fraction &a){ is>>a.first;a.second=1; return is;}

#define define_cmp(op) \
  bool operator op (const Fraction& b) const{ return a.first*b.second op b.first*a.second; }
  define_cmp(==)
  define_cmp(!=)
  define_cmp(<)
  define_cmp(>)
  define_cmp(<=)
  define_cmp(>=)
#undef define_cmp
};