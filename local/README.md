実験やデバッグなど、提出コードに反映されない箇所用のライブラリ  

実験に関しては実験用コードに include すれば良い  

デバッグは debug 関数を書いたままでも提出できるように、
```cpp
#ifdef __LOCAL
 #include "Debug.cpp"
#else
 #define debug(...) void(0)
#endif
```
とテンプレートに書いておき、手元の ```g++``` を alias などを用いて ```g++ -D __LOCAL``` に変えておく  
```vector``` や ```modint``` などの出力は提出でも使いたいためテンプレートの方で```<<``` を定義しているが、この際 ``` #include <debug>``` よりも先に定義をしないと CE になることがある