/*
ZETA,LOWER [S]: sum T⊆S v[T]
ZETA,UPPER [S]: sum T⊇S v[T]
MOEBIUS,LOWER [S]: sum T⊆S (-1)^(|S\T|) v[T]
MOEBIUS,LOWER [S]: sum T⊆S (-1)^(|T\S|) v[T] 
*/

#define REP_(i,n) for(int i=0;i<(n);i++)
enum Query_Type{
  ZETA = 1;
  MOEBIUS = -1;
  LOWER = true;
  UPPER = false;
};
template<typename T>
vector<T> bitwise_convolution(vector<T> v,Query_Type q1,Query_Type q2){
  int n=__builtin_ctz(int(v.size()));
  REP_(k,n)REP_(S,1<<n)if(q2 ^ ((S>>k)&1))v[S]+=q1*v[S^(1<<k)];
  return v;
}
#undef REP_