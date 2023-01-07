#pragma once
template<char MARGIN>
struct ForString{
  static constexpr char change(char c){ return c-MARGIN; }
  static constexpr char restore(char a){ return a+MARGIN; }

  static vector<char> change(const string&s){
    vector<char> v(s.size());
    for(int i=0;i<s.size();i++)v[i]=change(s[i]);
    return v;
  }
  static string restore(const vector<char>&v){
    string s(v.size(),'#');
    for(int i=0;i<v.size();i++)s[i]=restore(v[i]);
    return s;
  }
};
struct FSAa{
  static constexpr char change(char c){ return c<='Z'?c-'A':26+c-'a'; }
  static constexpr char restore(char a){ return a<26?'A':a-26+'a'; }
  static vector<char> change(const string&s){
    vector<char> v(s.size());
    for(int i=0;i<s.size();i++)v[i]=change(s[i]);
    return v;
  }
  static string restore(const vector<char>&v){
    string s(v.size(),'#');
    for(int i=0;i<v.size();i++)s[i]=restore(v[i]);
    return s;
  }
};
using FSA=ForString<'A'>;
using FSa=ForString<'a'>;
using FS0=ForString<'0'>;

#ifdef STR
  #define STRA(s) STR(s##tomato);auto s=FSA::change(s##tomato);
  #define STRa(s) STR(s##tomato);auto s=FSa::change(s##tomato);
  #define STR0(s) STR(s##tomato);auto s=FS0::change(s##tomato);
#endif