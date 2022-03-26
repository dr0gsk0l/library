template <class Monoid>
struct SWAG{
  stack<Monoid> back_stack;
  Monoid back_value;
  stack<pair<Monoid,Monoid>> front_stack;

  inline Monoid front_value(){
    if(front_stack.empty())return Monoid();
    return get<1>(front_stack.top());
  }

  void push_back(Monoid a){
    back_stack.push(a);
    back_value=back_value+a;
  }
  void push_front(Monoid a){
    front_stack.emplace(a,a+front_value());
  }
  void pop_front(){
    if(front_stack.empty()){
      if(back_stack.empty())return;
      while(back_stack.size()){
        push_front(back_stack.top());
        back_stack.pop();
      }
      back_value.v=Monoid();
    }
    front_stack.pop();
  }
  
  Monoid fold(){
    return front_value()+back_value;
  }
};
/*
SWAG<Monoid> で作成
push_back(a),push_front(a) がO(1)
pop_front は平均O(1)

fold() で現在入ってる値の積が出る
*/