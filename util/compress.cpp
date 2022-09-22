template<typename T>
struct Compress{
  map<T,int> mp;
  vector<T> rev;

  Compress()=default;
  Compress(const vector<T>&v,bool banpei=false){
    for(const T&a:v)mp[a];
    if(banpei)mp[numeric_limits<T>::max()],mp[numeric_limits<T>::min()];
    build();
  }
  
  void add(T a){ mp[a]; }
  void build(){
    int cnt=0;
    rev.resize(mp.size());
    for(auto&[val,id]:mp){
      rev[cnt]=val;
      id=cnt++;
    }
  }

  int operator[](T a)const{return mp.at(a);}
  int geq(T a)const{return mp.lower_bound(a)->second;}
  int leq(T a)const{return (--mp.upper_bound(a))->second;}
  int gt(T a)const{return mp.upper_bound(a)->second;}
  int lt(T a)const{return (--mp.lower_bound(a))->second;}

  T r(int id)const{return rev[id];}

  int size()const{return mp.size();}
};