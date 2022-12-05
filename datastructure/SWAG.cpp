#pragma once
template<typename Monoid>
class SWAG{
  using X=typename Monoid::value_type;

  stack<X> back_stack,front_stack; // back は後ろの各要素 front は前の累積和
  X back_value;

  inline X front_value()const{
    return front_stack.size()?front_stack.top():Monoid::unit();
  }
public:
  SWAG():back_value(Monoid::unit()){}
  void push_back(X x){
    back_stack.push(x);
    Monoid::Rchop(back_value,a);
  }
  void push_front(Monoid a){
    front_stack.push(Monoid::op(a,front_value));
  }
  void pop_front(){
    if(front_stack.empty()){
      if(back_stack.empty())return;
      while(back_stack.size()){
        push_front(back_stack.top());
        back_stack.pop();
      }
      back_value=Monoid::unit();
    }
    front_stack.pop();
  }
  X fold(){
    return Monoid::op(front_value(),back_value);
  }
};