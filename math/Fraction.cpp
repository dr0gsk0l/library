#pragma once
template<typename T>
struct Fraction{
  T num,den;
  Fraction(T n=0,T d=1):num(n),den(d){
    assert(den!=0);
    if(den<0)num=-num,den=-den;
    T g=gcd(abs(num),abs(den));
    num/=g;
    den/=g;
  }

  Fraction operator+(const Fraction& b)const{ return Fraction( num*b.den + den*b.num, den*b.den ); }
  Fraction operator-(const Fraction& b)const{ return Fraction( num*b.den - den*b.num, den*b.den ); }
  Fraction operator*(const Fraction& b)const{ return Fraction( num*b.num, den*b.den ); }
  Fraction operator/(const Fraction& b)const{ return Fraction( num*b.den, den*b.num ); }
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
  Fraction operator+()const{ return *this; }
  Fraction operator-()const{ return Fraction(-num,den); }

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
  Fraction inv(){ return Fraction(den,num); }

  friend ostream& operator<<(ostream&os,const Fraction &a){os<<a.num<<"/"<<a.den;return os;}
  friend istream& operator>>(istream&is,Fraction &a){ is>>a.num;a.den=1; return is;}

#define define_cmp(op) \
  bool operator op (const Fraction& b) const{ return num*b.den op b.num*den; }
  define_cmp(==)
  define_cmp(!=)
  define_cmp(<)
  define_cmp(>)
  define_cmp(<=)
  define_cmp(>=)
#undef define_cmp
};