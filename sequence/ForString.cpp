template<char MARGIN>
struct ForString{
  inline char change(char c){ return c-MARGIN; }
  inline char restore(char a){ return a+MARGIN; }

  vector<char> change(const string&s){
    vector<char> v(s.size());
    for(int i=0;i<s.size();i++)v[i]=change(s[i]);
    return v;
  }
  string restore(const vector<char>&v){
    string s(v.size());
    for(int i=0;i<v.size();i++)s[i]=restore(v[i]);
    return s;
  }
};
struct FSAa{
  inline char change(char c){ return is_upper(c)?c-'A':26+c-'a'; }
  inline char restore(char a){ return a<26?'A':a-26+'a'; }
  vector<char> change(const string&s){
    vector<char> v(s.size());
    for(int i=0;i<s.size();i++)v[i]=change(s[i]);
    return v;
  }
  string restore(const vector<char>&v){
    string s(v.size());
    for(int i=0;i<v.size();i++)s[i]=restore(v[i]);
    return s;
  }
};
using FSA=ForString<'A'>;
using FSa=ForString<'a'>;
using FS0=ForString<'0'>;