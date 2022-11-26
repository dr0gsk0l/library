以下の階層で作る  
同じ問題を使いたい場合は ABC001A(2).test.cpp のように書く  
### AtCoder
ABC001A.test.cpp のように書く  
通常コンテスト以外もなるべく似せる
### AOJ
ALDS1_14_B.test.cpp のように書く
### library-checker
LC の分け方に従って Polynomial や Matrix などのディレクトリを作る  
ファイル名はアッパーキャメルケースで、問題名をそのまま書く  
ただし、Matrix/MatrixProduct.test.cpp などは冗長なので単に　Matrix/Product.test.cpp と書いて良い  
### yukicoder
単に問題番号を用いて 1000.test.cpp と書く

### コードのテンプレート
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
}
```
