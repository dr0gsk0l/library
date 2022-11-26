// reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
random_device rollonghash_rnd;
mt19937 rollonghash_mt(rollonghash_rnd());
class RollingHash{
  using ull=unsigned long long;
  static const ull MASK30=(1ull<<30)-1;
  static const ull MASK31=(1ull<<31)-1;
  static const ull MOD=(1ull<<61)-1;
  static const ull BIGM=MOD*4;
  
  inline static const ull base = rollonghash_mt()%10000000+2;

  static ull mul(ull a,ull b){
    ull au=a>>31, ad=a&MASK31, bu=b>>31, bd=b&MASK31;
    ull mid= ad*bu + au*bd;
    ull midu=mid>>30,midd=mid&MASK30;
    return au*bu*2 + midu + (midd<<31) + ad*bd;
  }
  static ull calc_mod(ull x){
    ull xu=x>>61, xd=x&MOD;
    ull res=xu+xd;
    return (res<MOD?res:res-MOD);
  }
  static ull nxt_hash(ull x,char c){ return calc_mod(mul(x,base)+(int)c); }

  vector<ull> hash,power;
  int n;
public:
  RollingHash(const string&s):n(s.size()),hash(s.size()+1,0),power(s.size()+1,1){
    for(int i=0;i<n;i++){
      hash[i+1]=nxt_hash(hash[i],s[i]);
      power[i+1]=calc_mod(mul(power[i],base));
    }
  }
  
  ull get_hash(int l=0,int r=-1){
    if(r<0)r=n;
    return calc_mod(hash[r]+BIGM-mul(hash[l],power[r-l]));
  }
  
  static ull full_hash(const string&s){
    ull res=0;
    for(const char&c:s)res=nxt_hash(res,c);
    return res;
  }
};
