#pragma once
template<typename T>
struct Line{
  T a,b;
  Line()=default;
  Line(T a,T b):a(a),b(b){}
  Line(pair<T,T> l):a(l.first),b(l.second){}
  Line(T c):a(0),b(c){}

  T operator()(const T x)const{ return a*x+b; }
  Line operator()(const Line&l)const{ return Line(a*l.a, a*l.b+b); }

  bool operator==(const Line&l)const{ return a==l.a and b==l.b; }
  bool operator!=(const Line&l)const{ return !(*this == l); }
  bool operator<(const Line&l)const{ return (a==l.a ? a<l.a : b<l.b); }

  Line&operator+=(const Line&l){ a+=l.a; b+=l.b; return *this; }
  Line operator+(const Line&l)const{return Line(*this) += l; }
  Line&operator-=(const Line&l){ a-=l.a; b-=l.b; return *this; }
  Line operator-(const Line&l)const{return Line(*this) -= l; }
  Line operator-()const{ return Line(-a,-b); }

  Line&operator+=(const T&c){ b+=c; return *this; }
  Line operator+(const T&c)const{ return Line(*this) += c; }
  Line&operator-=(const T&c){ b-=c; return *this; }
  Line operator-(const T&c)const{ return Line(*this) -= c; }
  Line&operator*=(const T&c){ a*=c; b*=c; return *this; }
  Line operator*(const T&c)const{ return Line(*this) *= c; }
  Line&operator/=(const T&c){ a/=c; b/=c; return *this; }
  Line operator/(const T&c)const{ return Line(*this) /= c; }

  Line inv()const{
    assert(a!=0);
    return Line(T(1)/a, -b/a);
  }

  friend istream&operator>>(istream&is,Line&l){
    is>>l.a>>l.b;
    return is;
  }
  friend ostream&operator<<(ostream&os,const Line&l){
    if(l.a==0 and l.b==0)os<<0;
    else if(l.a==0)os<<l.b;
    else if(l.b==0)os<<l.a<<"x";
    else if(l.b>0)os<<l.a<<"x+"<<l.b;
    else os<<l.a<<"x-"<<-l.b;
    return os;
  }
};