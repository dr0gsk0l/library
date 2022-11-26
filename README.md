[![Actions Status](https://github.com/dr0gsk0l/library/workflows/verify/badge.svg)](https://github.com/dr0gsk0l/library/actions) 
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://dr0gsk0l.github.io/akinator/game.html)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://dr0gsk0l.github.io/library/) 
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://dr0gsk0l.github.io/kaibungenerator/tmp.html)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://dr0gsk0l.github.io/othello/othello/)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://dr0gsk0l.github.io/game/game.html)

### ライブラリのディレクトリ名
全て小文字  
単語間は _ で繋げても良い（スネークケース）が、繋げても良い（formalpowerseriesなど）
### ライブラリファイルの名前
アッパーキャメルケース  
各単語の最初の文字を大文字で書く  
HLD のように略語を使う際は全て大文字を使う
### 構造体などの名前
アッパーキャメルケース  
HLD のように略語を使う際は全て大文字を使う
### 関数の名前
ディレクトリ名と同じ  
### testファイル
以下の階層でディレクトリを作る
#### AtCoder
識別番号を使う ABC001A など
LibraryChecker は 問題名を使う
重複する場合は ABC001A(2).test.cpp のようにする
### テンプレート引数
```template<typename Graph>``` のように実在する構造体の名前を書きたい場合は  
```template<typename GRAPH>``` のように全て大文字で書く  
```template<typename G>``` や ```template<typename WG>``` と略すのは自由  
```template<typename Monoid>``` はこのままでok（Monoid と言う名前の構造体は存在しないので）