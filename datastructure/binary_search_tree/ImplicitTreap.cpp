#pragma once
// https://xuzijian629.hatenablog.com/entry/2018/12/08/000452
#include "math/XorShift.cpp"
template<typename Lazy>
class ImplicitTreap {
  using MX = typename Lazy::MX;
  using MF = typename Lazy::MF;
  using X = typename MX::value_type;
  using F = typename MF::value_type;
  struct Node{
    X val,prod;
    F lazy;
    int priority, cnt;
    bool rev;
    Node *l, *r;
    Node(X val,int priority=-1):value(val),prod(MX::unit()),lazy(MF::unit()),priority(priority),cnt(1),rev(false),l(nullptr),r(nullptr){
      if(priority<0)priority=rnd();
    }
  };
  Node* root=nullptr;
  using Tree = Node *;

  int size(Tree t){ return t ? t->cnt : 0; }
  X prod(Tree t){ return t ? Lazy::mapping(t->lazy,t->prod) : MX::unit(); }

  void pushup(Tree t){
    if(!t)return;
    t->cnt = 1+size(t->l)+size(t->r);
    t->prod = MX::op(t->val, MX::op(prod(t->l),prod(t->r)));
  }
  void pushdown(Tree t){
    if(!t)return;
    if(t->lazy != MF::unit()){
      t->val = Lazy::mapping(t->val, t->lazy);
      if(t->l)
        MF::Rchop(t->l->lazy,t->lazy);
      if (t->r)
        MF::Rchop(t->r->lazy,t->lazy);
      t->lazy = MF::unit();
    }
    pushup(t);
  }
    
  void split(Tree t, int key, Tree& l, Tree& r) {
    if(!t){
      l = r = nullptr;
      return;
    }
    pushdown(t);
    int implicit_key = size(t->l)+1;
    if(key < implicit_key){
      r = t;
      split(t->l, key, l, t->l);
    }
    else{
      l=t;
      split(t->r, key - implicit_key, t->r, r), l = t;
    }
    pushup(t);
  }
    
  void insert(Tree& t, int key, Tree item){
    Tree t1, t2;
    split(t, key, t1, t2);
    merge(t1, t1, item);
    merge(t, t1, t2);
  }

  void merge(Tree& t, Tree l, Tree r) {
    pushdown(l);
    pushdown(r);
    if(!l or !r)
      t = l ? l : r;
    else if(l->priority > r->priority){
      t=l;
      merge(l->r, l->r, r);
    }
    else{
      t=r;
      merge(r->l, l, r->l);
    }
    pushup(t);
  }
  
  void erase(Tree& t, int key) {
    Tree t1, t2, t3;
    split(t, key + 1, t1, t2);
    split(t1, key, t1, t3);
    merge(t, t1, t2);
  }

  void add(Tree t, int l, int r, int x) {
    Tree t1, t2, t3;
    split(t, l, t1, t2);
    split(t2, r - l, t2 , t3);
    t2->lazy += x;
    t2->min += x;
    merge(t2, t2, t3);
    merge(t, t1, t2);
  }

  int findmin(Tree t, int l, int r) {
    Tree t1, t2, t3;
    split(t, l, t1, t2);
    split(t2, r - l, t2, t3);
    int ret = t2->min;
    merge(t2, t2, t3);
    merge(t, t1, t2);
    return ret;
  }

    // [l, r)の先頭がmになるように左シフトさせる。std::rotateと同じ仕様
    void rotate(Tree t, int l, int m, int r) {
        reverse(t, l, r);
        reverse(t, l, l + r - m);
        reverse(t, l + r - m, r);
    }

    void dump(Tree t) {
        if (!t) return;
        pushdown(t);
        dump(t->l);
        cout << t->value << " ";
        dump(t->r);
    }
    
public:
    void insert(int pos, int x) {
        insert(root, pos, new Node(x, rnd.random()));
    }

    void add(int l, int r, int x) {
        add(root, l, r, x);
    }

    int findmin(int l, int r) {
        return findmin(root, l, r);
    }

    void erase(int pos) {
        erase(root, pos);
    }

    void reverse(int l, int r) {
        reverse(root, l, r);
    }

    void rotate(int l, int m, int r) {
        rotate(root, l, m, r);
    }

    void dump() {
        dump(root);
        cout << endl;
    }
};