#pragma once
// https://xuzijian629.hatenablog.com/entry/2018/12/08/000452
#include "math/XorShift.cpp"
template<typename T>
class Treap{
  XorShift rnd;
  struct Node{
    T key;
    int priority;
    Node *l, *r;
    Node(T key,int priority=-1):key(key),priority(priority),l(nullptr),r(nullptr){
      if(priority<0)priority=rnd();
    }
  };
  Node* root=nullptr;
  using Tree = Node *;
  
  // t を key 未満と key 以上に分け、それぞれ l,r に代入
  void split(Tree t, T key, Tree& l, Tree& r) {
    if(!t)
      l = r = nullptr;
    else if(t->key < key){
      // t は l の担当
      l=t;
      split(t->r, key, t->r, r);
    } 
    else {
      r=t;
      split(t->l, key, l, t->l);
    }
  }

  // t に item を挿入
  void insert(Tree& t, Tree item) {
    if(!t)
      t=item;
    else if(item->priority > t->priority){
      // t の場所に item を置く
      // t とその部分木 は item の左右にくっつける
      split(t, item->key, item->l, item->r);
      t=item;
    }
    else
      insert(item->key < t->key ? t->l : t->r, item);
  }

  // 
  void merge(Tree& t, Tree l, Tree r) {
    if(!l or !r)
      t = l ? l : r;
    else if(l->priority > r->priority){
      merge(l->r, l->r, r);
      t = l;
    }
    else{
      merge(r->l, l, r->l);
      t = r;
    }
  }

  void erase(Tree& t, T key) {
    if (t->key == key)
      merge(t, t->l, t->r);
    else
      erase(key < t->key ? t->l : t->r, key);
  }

  bool find(Tree& t, T key){
    if(!t)
      return false;
    if(t->key == key)
      return true;
    return find(key < t->key ? t->l : t->r, key);
  }
public:
  void insert(T key){ insert(root,new Node(key)); }
  void erase(T key){ erase(root, key); }
  bool find(T key){ return find(root, key); }
};