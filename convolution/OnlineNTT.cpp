#pragma once
#define REP_(i,n) for(int i=0;i<(n);i++)
#define RREP_(i,n) for(int i=(n)-1;i>=0;i--)
template<typename MINT>
class OnlineNTT{
  static_assert(MINT::mod == 998244353);
  int d;
  vector<MINT> f,g,fg,change_f,change_g,tmp;
  vector<vector<MINT>> F,G;
  // F[i] : 幅 1<<i の DFT 結果
  vector<vector<MINT>> cs,cs_inv;
  vector<int> x,fst,lst;
  vector<MINT> inv;
  int d_lst,lg;

  void DFT(vector<MINT>&f,vector<MINT>&g,const int lg){
    // 1<<lg の DFT を行う
    const int n=1<<lg;
    // f[n/2,n) , g[n/2,n) = 0 が保証されている
    fill(x.begin(),x.begin()+n,0);
    REP_(h,lg)
      REP_(S,1<<h)
        REP_(T,1<<(lg-h-1)){
          int l=(S<<(lg-h))|T;
          int r=l|(1<<(lg-h-1));

          x[l] >>= 1;
          (x[r] >>= 1) |= 1<<(lg-1);

          MINT a=f[l];
          f[l] += f[r] * cs[lg][x[l]];
          (f[r] *= cs[lg][x[r]]) += a;

          a = g[l];
          g[l] += g[r] * cs[lg][x[l]];
          (g[r] *= cs[lg][x[r]]) += a;
        }
  }

  void IDFT(vector<MINT>&f,const int lg){
    const int n=1<<lg;
    fill(x.begin(),x.begin()+n,0);
    RREP_(h,lg)
      REP_(S,1<<h)
        REP_(T,1<<(lg-h-1)){
          int l=(S<<(lg-h))|T;
          int r=l|(1<<(lg-h-1));

          x[l] >>= 1;
          (x[r] >>= 1) |= 1<<(lg-1);

          MINT a=f[l];
          f[l] += f[r] * cs_inv[lg][x[l]];
          (f[r] *= cs_inv[lg][x[r]]) += a;
        }
    REP_(i,n)f[i]*=inv[lg];
  }

  void IDFT(vector<MINT>&f,vector<MINT>&g,const int lg){
    const int n=1<<lg;
    fill(x.begin(),x.begin()+n,0);
    RREP_(h,lg)
      REP_(S,1<<h)
        REP_(T,1<<(lg-h-1)){
          int l=(S<<(lg-h))|T;
          int r=l|(1<<(lg-h-1));

          x[l] >>= 1;
          (x[r] >>= 1) |= 1<<(lg-1);

          MINT a=f[l];
          f[l] += f[r] * cs_inv[lg][x[l]];
          (f[r] *= cs_inv[lg][x[r]]) += a;
          a=g[l];
          g[l] += g[r] * cs_inv[lg][x[l]];
          (g[r] *= cs_inv[lg][x[r]]) += a;
        }
    REP_(i,n){
      f[i]*=inv[lg];
      g[i]*=inv[lg];
    }
  }
public:
  OnlineNTT(int n,int m):
    d(0),d_lst(-1),lg(0),cs(1),cs_inv(1),inv(1),fg(n+m-1){}

  MINT query(MINT f_i,MINT g_i){
    f.push_back(f_i);
    g.push_back(g_i);

    fill(change_f.begin(),change_f.end(),0);
    fill(change_g.begin(),change_g.end(),0);

    REP_(h,F.size()){
      if(lst[h]+(1<<h)!=d)continue;
      REP(i,1<<h){
        change_f[i] = f[d-(1<<h)+1+i];
        change_g[i] = g[d-(1<<h)+1+i];
      }
      DFT(change_f,change_g,h+1);
      REP(i,1<<(h+1)){
        change_f[i] *= G[h][i];
        change_g[i] *= F[h][i];
      }
      IDFT(change_f,change_g,h+1);
      REP(i,(1<<(h+1))-1){
        if(fst[h] + lst[h]+1 + i >= fg.size())break;
        fg[ fst[h] + lst[h]+1 + i ] += change_f[i] + change_g[i];
      }
      lst[h] = d;
    }
    
    if(d_lst + (1<<lg) == d){
      // サイズ 1<<lg が完成（DFT 後のサイズは 1<<(lg+1))
      const int N=1<<(lg+1);
      F.emplace_back(vector<MINT>(N,0));
      G.emplace_back(vector<MINT>(N,0));
      REP_(i,1<<lg){
        F.back()[i] = f[d-(1<<lg)+1+i];
        G.back()[i] = g[d-(1<<lg)+1+i];
      }

      x.resize(N);
      MINT c = MINT(3).pow((MINT::mod-1)>>(lg+1));
      cs.emplace_back(vector<MINT>(N));
      REP_(i,N)cs.back()[i] = (i ? cs.back()[i-1]*c : 1);
      DFT(F.back(),G.back(),lg+1);
      
      tmp.resize(N);
      REP_(i,N)tmp[i] = F.back()[i] * G.back()[i];

      c = c.inv();
      cs_inv.emplace_back(vector<MINT>(N));
      REP_(i,N)cs_inv.back()[i] = (i ? cs_inv.back()[i-1]*c : 1);
      inv.push_back(MINT(N).inv());
      IDFT(tmp,lg+1);
      
      REP_(i,N-1){
        if((d_lst+1)*2+i >= fg.size())break;
        fg[(d_lst+1)*2+i] += tmp[i];
      }

      change_f.resize(N);
      change_g.resize(N);

      fst.push_back(d-(1<<lg)+1);
      lst.push_back(d);
      d_lst = d;
      lg++;
    }
    
    return fg[d++];
  }
};
#undef REP_
#undef RREP_