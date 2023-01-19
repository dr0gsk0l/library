class XorShift{
  uint64_t x;
public:
  XorShift(){
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    x=rnd();
    for(int i=0;i<100;i++)(*this)();
  }
  uint64_t operator()(){
    x = x^(x<<7);
    return x = x^(x>>9);
  }
};