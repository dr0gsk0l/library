#pragma once
#define REP_(i,n) for(int i=0;i<(n);i++)
#define RREP_(i,n) for(int i=(n)-1;i>=0;i--)

template<typename MINT>
vector<MINT> convolution(vector<MINT>f,vector<MINT>g){
  int nf=f.size(),ng=g.size();
  if(!nf or !ng)return vector<MINT>{};
  int M=nf+ng-1;

  if(nf<=60 or ng<=60){
    vector<MINT> res(M,0);
    REP_(i,nf)REP_(j,ng)res[i+j]+=f[i]*g[j];
    return res;
  }
  
  int lg;
  for(lg=0;(1<<lg)<M;lg++){}
  const int N=1<<lg;
  f.resize(N,0);
  g.resize(N,0);

  static_assert(MINT::mod == 998244353);
  MINT c=MINT(3).pow((MINT::mod-1)>>lg);
  vector<MINT> cs(N);
  REP_(i,N)cs[i] = (i ? cs[i-1]*c : 1);
  
  vector<int> x(N,0);
  REP_(h,lg)
    REP_(S,1<<h)
      REP_(T,1<<(lg-h-1)){
        int l=(S<<(lg-h))|T;
        int r=l|(1<<(lg-h-1));

        x[l] >>= 1;
        (x[r] >>= 1) |= 1<<(lg-1);

        MINT a=f[l];
        f[l] += f[r] * cs[x[l]];
        (f[r] *= cs[x[r]]) += a;

        a = g[l];
        g[l] += g[r] * cs[x[l]];
        (g[r] *= cs[x[r]]) += a;
      }
  REP_(i,N)f[i]*=g[i];

  fill(x.begin(),x.end(),0);
  c = c.inv();
  REP_(i,N)cs[i] = (i ? cs[i-1]*c : 1);
  RREP_(h,lg)
    REP_(S,1<<h)
      REP_(T,1<<(lg-h-1)){
        int l=(S<<(lg-h))|T;
        int r=l|(1<<(lg-h-1));

        x[l] >>= 1;
        (x[r] >>= 1) |= 1<<(lg-1);

        MINT a=f[l];
        f[l] += f[r] * cs[x[l]];
        (f[r] *= cs[x[r]]) += a;
      }
  f.resize(M);
  MINT Ninv=MINT(N).inv();
  REP_(i,M)f[i]*=Ninv;
  return f;
}
#undef REP_
#undef RREP_