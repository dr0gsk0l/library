#pragma once
template<typename T>
struct XY{
  T x,y;
  XY()=default;
  XY(T x,T y):x(x),y(y){}

  XY operator+()const{ return *this; }
  XY operator-()const{ return XY(-x,-y); }

  XY& operator++(){ x++;y++;return *this; }
  XY& operator--(){ x--;y--;return *this; }
  XY& operator++(int){ XY a=*this; ++*this; return a; }
  XY& operator--(int){ XY a=*this; --*this; return a; }

  XY& operator+=(const XY& v){ x+=v.x; y+=v.y; return *this; }
  XY& operator-=(const XY& v){ x-=v.x; y-=v.y; return *this; }
  XY& operator*=(const T& a){ x*=a; y*=a; return *this; }
  XY& operator/=(const T& a){ x/=a; y/=a; return *this; }

  friend XY operator+(const XY& u,const XY& v){ return XY(u)+=v; }
  friend XY operator-(const XY& u,const XY& v){ return XY(u)-=v; }
  friend XY operator*(const XY&u,const T& a){ return XY(u)*=a; }
  friend XY operator*(const T& a,const XY&u){ return XY(u)*=a; }
  friend XY operator/(const XY&u,const T& a){ return XY(u)/=a; }

  bool operator<(const XY&v)const{ return x!=v.x ? x<v.x : y<v.y; }
  bool operator>(const XY&v)const{ return x!=v.x ? x>v.x : y>v.y; }
  bool operator==(const XY&v)const{ return x==v.x and y==v.y; }
  bool operator!=(const XY&v)const{ return !(*this==v); }

  friend T dot(const XY&u,const XY& v){ return u.x*v.x + u.y*v.y; }
  T square_abs(){ return dot(*this,*this); }
  T abs(){ return sqrt(square_abs()); }

  friend istream&operator>>(istream&is,XY&v){ is>>v.x>>v.y; return is; }
  friend ostream&operator<<(ostream&os,const XY&v){ os<<v.x<<" "<<v.y; return os;}
};