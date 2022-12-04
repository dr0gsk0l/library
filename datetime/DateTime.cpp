class DateTime{
  static int day_of_week; // 1年1月1日の曜日
public:
  int year,month,day;
  DateTime(int y,int m,int d):year(y),month(m),day(d){}

  static bool is_leap_year(int y){ return !(y%400) or (!(y%4) and y%100); }
  static int month_days(int y,int m){
    if(m==2)return 28+is_leap_year(y);
    return 31-(m==4||m==6||m==9||m==11);
  }

  // 1年1月1日が 0 となるように変換
  int to_int()const{
    int y = (month <= 2 ? year - 1 : year);
    int m = (month <= 2 ? month + 12 : month);
    int d = day;
    return 365 * y + y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d - 429;
  }

  // to_int() の逆関数
  static DateTime from_int(int x){
    int y = x * 400 / 146097 + 1;
    int d = x - DateTime(y, 1, 1).to_int();
    int m = 1;
    while (d >= 28) {
      int k = month_days(y,m);
      if (d < k) break;
      ++m;
      d -= k;
    }
    if (m == 13) {
      ++y;
      m = 1;
    }
    ++d;
    return DateTime(y, m, d);
  }

  void set_day_of_week(int day_of_week_){
    int now=to_int()%7;
    day_of_week = day_of_week_ - now;
    if(day_of_week < 0)day_of_week += 7;
  }

  int weekday()const{ return ( day_of_week + to_int() ) % 7; }

  DateTime& operator++(){
    if(++day>month_days(year,month)){
      day=1;
      if(++month>12){
        ++year;
        month=1;
      }
    }
    return *this;
  }
  DateTime& operator++(int){ return ++(*this); }
  DateTime& operator--(){
    if(--day<0){
      if(--month<0){
        assert(--year>=1);
        month=12;
      }
      day=month_days(year,month);
    }
    return *this;
  }
  DateTime& operator--(int){ return --(*this); }
  DateTime& operator+=(int d){
    year+=(d/400)*146097;
    d%=400;
    while(d--)(*this)++;
    return *this;
  }
  DateTime& operator-=(int d){
    year-=(d/400)*146097;
    d%=400;
    while(d--)(*this)--;
    return *this;
  }
  DateTime operator+(int d){ return DateTime(year,month,day)+=d; }
  DateTime operator-(int d){ return DateTime(year,month,day)-=d; }

  // yyyy[sep]mm[sep]dd
  string to_string(string sep = "-") {
    string y = std::to_string(year);
    string m = std::to_string(month);
    string d = std::to_string(day);
    while (y.size() < 4) y = "0" + y;
    while (m.size() < 2) m = "0" + m;
    while (d.size() < 2) d = "0" + d;
    return y + sep + m + sep + d;
  }

  tuple<int,int,int> to_tuple()const{ return {year, month, day}; }

#define define_cmp(op) \
  bool operator op (const DateTime& a)const{return to_tuple() op a.to_tuple();}
  define_cmp(==)
  define_cmp(!=)
  define_cmp(<)
  define_cmp(>)
  define_cmp(<=)
  define_cmp(>=)
#undef define_cmp
};