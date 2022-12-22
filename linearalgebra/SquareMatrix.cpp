#pragma once
#define REP_(i,n) for(int i=0;i<(n);i++)
#define REP2_(i,s,n) for(int i=(s);i<(n);i++)
template<typename K,size_t N>
struct SquareMatrix{
  using value_type=K;
  using vec=array<K,N>;
  using mat=array<vec,N>;
  mat M;

  SquareMatrix(K a=0){ 
    for(vec& v:M)v.fill(0); 
    if(a!=0)REP_(i,N)M[i][i]=a;
  }
  SquareMatrix(const mat&A):M(A){}
  SquareMatrix(const vector<vector<K>>&v){
    assert(v.size()==N and v[0].size()==N);
    REP_(i,N)REP_(j,N)M[i][j]=v[i][j];
  }

  vec& operator[](size_t k){return M[k];}
  const vec& operator[](size_t k)const{return M[k];}
  
  SquareMatrix& operator+=(const SquareMatrix &A){
    REP_(i,N)REP_(j,N)M[i][j]+=A[i][j];
    return *this;
  }
  SquareMatrix& operator-=(const SquareMatrix &A){
    REP_(i,N)REP_(j,N)M[i][j]-=A[i][j];
    return *this;
  }
  SquareMatrix operator+(const SquareMatrix &A)const{ return SquareMatrix(M)+=A; }
  SquareMatrix operator-(const SquareMatrix &A)const{ return SquareMatrix(M)-=A; }

  friend SquareMatrix operator*(const SquareMatrix &A,const SquareMatrix &B){
    SquareMatrix res;
    REP_(i,N)REP_(k,N)REP_(j,N)res[i][j]+=A[i][k]*B[k][j];
    return res;
  }
  SquareMatrix& operator*=(const SquareMatrix &A){
    M=((*this)*A).M;
    return *this;
  }

  SquareMatrix& operator/=(const SquareMatrix&A){ return (*this) *= A.inv(); }
  SquareMatrix operator/(const SquareMatrix&A)const{ return SquareMatrix(M) /= A; }

  bool operator==(const SquareMatrix &A){
    REP_(i,N)REP_(j,N)if(M[i][j]!=A[i][j])return false;
    return true;
  }
  bool operator!=(const SquareMatrix &A){ return !((*this)==A); }
  
  static SquareMatrix I(){ return SquareMatrix(1); }
  
  SquareMatrix pow(long long n)const{
    assert(n>=0);
    SquareMatrix A(M),res(1);
    while(n){
      if(n&1)res*=A;
      A*=A;
      n>>=1;
    }
    return res;
  }

  pair<int,int> GaussJordan(){
    int rnk=0,cnt=0;
    REP_(k,N){
      if(M[rnk][k]==0)
        REP2_(i,rnk+1,N)
          if(M[i][k]!=0){
            swap(M[i],M[rnk]);
            cnt^=1;
            break;
          }
      if(M[rnk][k]==0)continue;
      REP_(i,N)if(i!=rnk){
        K x=M[i][k]/M[rnk][k];
        REP_(j,N)M[i][j]-=M[rnk][j]*x;
      }
      if(++rnk==N)break;
    }
    return {rnk,cnt};
  }

  K det()const{
    SquareMatrix A(M);
    const auto&[rnk,cnt]=A.GaussJordan();
    if(rnk!=N)return 0;
    K res=1;
    REP_(i,N)res*=A[i][i];
    return (cnt?-res:res);
  }

  SquareMatrix inv()const{
    SquareMatrix A(M),B(1);
    REP_(k,N){
      if(A[k][k]==0)
        REP2_(i,k+1,N)
          if(A[i][k]!=0){
            swap(A[i],A[k]);
            swap(B[i],B[k]);
          }
      assert(A[k][k]!=0);
      REP_(i,N)if(i!=k){
        K x=A[i][k]/A[k][k];
        REP_(j,N){
          A[i][j]-=A[k][j]*x;
          B[i][j]-=B[k][j]*x;
        }
      }
      K x=A[k][k];
      REP_(j,N){
        A[k][j]/=x;
        B[k][j]/=x;
      }
    }
    return B;
  }
  
  friend ostream& operator<<(ostream&os,const SquareMatrix &M){ os<<M.M; return os; }
  friend istream& operator>>(istream&is,SquareMatrix &M){ REP_(i,N)REP_(j,N)is>>M.M[i][j]; return is; }
};
#undef REP_
#undef REP2_
