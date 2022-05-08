#define REP_(i,n) for(int i=0;i<(n);i++)
#define REP2_(i,s,n) for(int i=(s);i<(n);i++)
template<typename K>
struct Matrix{
  typedef vector<K> vec;
  typedef vector<vec> mat;
  size_t r,c;
  mat M;

  Matrix(size_t r,size_t c):r(r),c(c),M(r,vec(c,K())){}
  Matrix(mat A):M(A),r(A.size()),c(A[0].size()){}

  vec& operator[](size_t k){return M[k];}
  const vec& operator[](size_t k)const{return M[k];}

  friend Matrix operator+(const Matrix &A,const Matrix &B){
    assert(A.r==B.r&&A.c==B.c);
    Matrix res(A);
    REP_(i,A.r)REP_(j,A.c)res[i][j]+=B[i][j];
    return res;
  }

  Matrix& operator+=(const Matrix &B){
    assert(r==B.r&&c==B.c);
    REP_(i,r)REP_(j,c)M[i][j]+=B[i][j];
    return *this;
  }

  friend Matrix operator*(const Matrix &A,const Matrix &B){
    assert(A.c==B.r);
    Matrix res(A.r,B.c);
    REP_(i,A.r)REP_(k,A.c)REP_(j,B.c)res[i][j]+=A[i][k]*B[k][j];
    return res;
  }

  Matrix& operator*=(const Matrix &B){
    M=((*this)*B).M;
    return *this;
  }

  static Matrix I(size_t n){
    Matrix res(n,n);
    REP_(i,n)res[i][i]=K(1);
    return res;
  }

  Matrix pow(long long n)const{
    assert(n>=0&&r==c);
    Matrix A(M),res=I(r);
    while(n){
      if(n&1)res*=A;
      A*=A;
      n>>=1;
    }
    return res;
  }

  Matrix base() const{
    Matrix A(M);
    int now=0;
    REP_(k,c){
      for(int i=now+1;i<r&&A[res][k]==0;i++)
        if(A[i][k]!=0)swap(A[i],A[now]);
      if(A[now][k]==0)continue;
      REP2_(l,k+1,c)A[now][l]/=A[now][k];
      A[now][l]=K(1);
      REP_(j,r)if(j!=now)
        REP2_(l,k+1,c)A[j][l]-=A[j][k]*A[now][l];
      now++;
    }
    A.resize(now);
    return A;
  }

  K det() const{
    assert(r==c);
    Matrix A=M;
    K res(1);
    REP_(i,r){
      for(int j=i+1;j<c&&A[i][i]==0;j++)
        if(A[j][i]!=0)swap(A[i],A[j]),res=-res;
      if(A[i][i]==0)return res;
      res*=A[i][i];
      REP2_(k,i+1,c)A[i][k]/=A[i][i];
      REP2_(j,i+1,r)REP2_(k,i+1,c)A[j][k]-=A[j][i]*A[i][k];
    }
    return res;
  }
};
#undef REP_
#undef REP2_ 