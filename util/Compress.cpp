#pragma once
#define ALL_(v) v.begin(),v.end()
template<typename T,bool Sentinel=false>
class Compress{
  vector<T> v;
  bool prepared;
public:
  Compress():prepared(false){
    if constexpr(Sentinel){
      static_assert(std::numeric_limits<T>::is_specialized,"cannot use Sentinel");
      v={numeric_limits<T>::min(),numeric_limits<T>::max()};
    }
  }
  Compress(const vector<T>&w):v(w),prepared(false){
    if constexpr(Sentinel){
      static_assert(std::numeric_limits<T>::is_specialized,"cannot use Sentinel");
      v.push_back(numeric_limits<T>::min());
      v.push_back(numeric_limits<T>::max());
    }
    build();
  }
  
  void add(T a){ 
    assert(!prepared);
    v.push_back(a); 
  }
  void build(){
    assert(!prepared);
    prepared=true;
    sort(ALL_(v));
    v.erase(unique(ALL_(v)),v.end());
  }

  bool is_prepared()const{ return prepared; }

  int operator[](const T&a)const{
    assert(prepared);
    auto it=lower_bound(ALL_(v),a);
    assert(*it==a);
    return distance(v.begin(),it);
  }
  int geq(const T&a)const{
    assert(prepared);
    auto it=lower_bound(ALL_(v),a);
    return distance(v.begin(),it);
  }
  int gt(const T&a)const{
    assert(prepared);
    auto it=upper_bound(ALL_(v),a);
    return distance(v.begin(),it);
  }
  int leq(const T&a)const{
    assert(prepared);
    auto it=--upper_bound(ALL_(v),a);
    return distance(v.begin(),it);
  }
  int lt(const T&a)const{
    assert(prepared);
    auto it=--lower_bound(ALL_(v),a);
    return distance(v.begin(),it);
  }
  T r(int id)const{
    assert(prepared);
    return v[id];
  }
  bool exist(const T&a)const{
    assert(prepared);
    return (*lower_bound(ALL_(v),a))==a;
  }
  int size()const{return v.size();}
  T max()const{ return v.back(); }
  T min()const{ return v[0]; }

  friend ostream&operator<<(ostream&os, const Compress&C){ 
    for(int i=0;i<C.v.size();i++)os<<C.v[i]<<":"<<i<<" ";
    return os;
  }
};
#undef ALL_