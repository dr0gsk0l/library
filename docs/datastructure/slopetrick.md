---
title: SlopeTrick
documentation_of: //datastructure/slopetrick.cpp
---

基本的な用語などは reference と同じ  

* ```tuple<T,T,T> get_min_range()```  
最小値とそれを取る閉区間が返る  
最小値だけ取得したい時は ```min_f``` を直接参照する  

* ```void operator+=(const T&a)```  
定数加算

* ```T operator()(T x)```  
$f(x)$ を返す  
priority_queue を走査するので時間がかかる  

* ```Slope_Trick& operator+=(Slope_Trick g)```  
$f(x)+=g(x)$  
マージテクでは ```size()``` の大きい方をメインにする



 
