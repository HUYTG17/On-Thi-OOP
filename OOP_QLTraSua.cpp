#include <iostream>
using namespace std;
class TraSua {
    string ten;
    int gia;
    int sl;
    string tp;
    string hsd;
public:
   void setTen(string k);
   void setGia(int k);
   void setSl(int k);
   void setTp(string k);
   void setHsd(string k);
   string getTen();
   int getGia();
   int getSl();
   string getTp();
   string getHsd();
   TraSua(string _ten = "a", int _gia = 0, int _sl = 0, string _tp = "b",
   string _hsd = "c");
   TraSua(const TraSua &ts);
   friend istream& operator >> (istream& is, TraSua &ts);
   friend ostream& operator << (ostream& os, TraSua ts);
   float getTb();
};
void TraSua::setTen(string k) { ten = k; }
void TraSua::setGia(int k) { gia = k; }
void TraSua::setSl(int k) { sl = k; }
void TraSua::setTp(string k) { tp = k; }
void TraSua::setHsd(string k) { hsd = k; } 
string TraSua::getTen() { return ten; }
int TraSua::getGia() { return gia; }
int TraSua::getSl() { return sl; }
string TraSua::getTp() { return tp; }
string TraSua::getHsd() { return hsd; }
TraSua::TraSua(string _ten, int _gia, int _sl, string _tp,
string _hsd) {
    ten = _ten; 
    gia = _gia;
    sl = _sl;
    tp = _tp;
    hsd = _hsd;
}
TraSua::TraSua(const TraSua &ts) {
    ten = ts.ten;
    gia = ts.gia;
    sl = ts.sl;
    tp = ts.tp;
    hsd = ts.hsd;
}
istream& operator >> (istream& is, TraSua &ts) {
    getline(is, ts.ten);
    is >> ts.gia;
    is >> ts.sl;
    is.ignore();
    getline(is, ts.tp);
    getline(is, ts.hsd);
    return is;
}
ostream& operator << (ostream& os, TraSua ts) {
    os << "Ten: " << ts.ten << endl;
    os << "Gia: " << ts.gia << endl;
    os << "So luong: " << ts.sl << endl;
    os << "Thanh phan: " << ts.tp << endl;
    os << "Han su dung: " << ts.hsd << endl;
}
float TraSua::getTb() {
    return gia*sl;
}
class TraSuaTranChau: public TraSua {
public:
    TraSuaTranChau(string _ten = "a", int _gia = 0, int _sl = 0, string _tp = "b",
   string _hsd = "c"): TraSua(_ten, _gia, _sl, _tp, _hsd){};
};
class TraSuaSocola: public TraSua {
public:
    TraSuaSocola(string _ten = "a", int _gia = 0, int _sl = 0, string _tp = "b",
   string _hsd = "c"): TraSua(_ten, _gia, _sl, _tp, _hsd){};
};
class TraSuaDau: public TraSua {
public:
    TraSuaDau(string _ten = "a", int _gia = 0, int _sl = 0, string _tp = "b",
   string _hsd = "c"): TraSua(_ten, _gia, _sl, _tp, _hsd){};
};
int main () {
    TraSuaTranChau a;
    TraSuaSocola b;
    TraSuaDau c;
    cin >> a >> b >> c;
    cout << "Thong tin cua tra sua tran chau:" << endl << a << endl;
    cout << "Thong tin cua tra sua socola:" << endl << b << endl;
    cout << "Thong tin cua tra sua dau:" << endl << c << endl;
    cout << "Tong tien cua tra sua tran chau: " << a.getTb() << endl;
    cout << "Tong tien cua tra sua socola: " << b.getTb() << endl;
    cout << "Tong tien cua tra sua dau: " << c.getTb() << endl;
}
