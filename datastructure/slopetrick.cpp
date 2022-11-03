// reference:https://maspypy.com/slope-trick-1-解説編
template<typename T>
class Slope_Trick{
  static constexpr T MIN=numeric_limits<T>::lowest()/2;
  static constexpr T MAX=numeric_limits<T>::max()/2;
  priority_queue<T> L;
  priority_queue<T,vector<T>,greater<T>> R;
  T add_l,add_r;
  
  T L0()const{ return L.size()?L.top()+add_l:MIN; }
  T R0()const{ return R.size()?R.top()+add_r:MAX; }
  void push_L(T a){ L.push(a-add_l); }
  void push_R(T a){ R.push(a-add_r); }
public:
  T min_f;
  Slope_Trick():add_l(0),add_r(0),min_f(0){}
  Slope_Trick(const vector<T>&l,const vector<T>&r,T min_f=0):
    L(l.begin().l.end()),R(r.begin(),r.end()),min_f(min_f),add_l(0),add_r(0){}

  int size()const{ return L.size()+R.size(); }

  tuple<T,T,T> get_min_range()const{return{L0(),R0(),min_f};}
  
  void operator+=(const T&a){ min_f += a; }

  // (x-a)+
  void add_x_minus_a(T a){
    if(a<L0()){
      min_f+=L0()-a;
      push_R(L0());L.pop();
      push_L(a);
    }
    else push_R(a);
  }

  // (a-x)+
  void add_a_minus_x(T a){
    if(a>R0()){
      min_f+=a-R0();
      push_L(R0());R.pop();
      push_R(a);
    }
    else push_L(a);
  }

  // |x-a|
  void add_abs(T a){
    add_x_minus_a(a);
    add_a_minus_x(a);
  }

  // 増加側を消して、減少側のみにする
  void clear_inc(){ R={}; }
  // 減少側を消して、増加側のみにする
  void clear_dec(){ L={}; }

  // g(x) = min_{x-b <= y <= x-a} f(y)
  void sliding_window_minimum(const T&a,const T&b){
    add_l += a;
    add_r += b;
  }

  void shift(const T&a){ sliding_window_minimum(a,a); }

  // O(nlogn) n=size
  T operator()(T x)const{
    T y=min_f;
    if(x<L0()){
      auto L_cpy=L;
      while(L_cpy.size()){
        T a=L_cpy.top()+add_l;L_cpy.pop();
        if(a<=x)break;
        y+=a-x;
      }
    }
    if(x>R0()){
      auto R_cpy=R;
      while(R_cpy.size()){
        T a=R_cpy.top()+add_r;R_cpy.pop();
        if(x<=a)break;
        y+=x-a;
      }
    }
    return y;
  }

  // O(mlog(n+m)) n=size,m=g.size()
  Slope_Trick& operator+=(Slope_Trick g){
    min_f += g.min_f;
    while( g.L.size() ){
      T a=g.L0();g.L.pop();
      add_a_minus_x(a);
    }
    while( g.R.size() ){
      T a=g.R0();g.R.pop();
      add_x_minus_a(a);
    }
    return *this;
  }

  Slope_Trick operator+(Slope_Trick g)const{ return (*this)+=g; }
};