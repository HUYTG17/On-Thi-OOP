#include <iostream>
using namespace std;
class Karaoke {
private:
    string ten;
    int tg;
    int sp;
    int dg;
public:
    void setten(string k) { ten = k; }
    void settg(int k) { tg = k; }
    void setsp(int k) { sp = k; }
    void setdg(int k) { dg = k; }
    string getten() { return ten; }
    int gettg() { return tg; }
    int getsp() { return sp; }
    int getdg() { return dg; }
    Karaoke(string _ten = "", int _tg = 0, int _sp = 0, int _dg = 0) {
        ten = _ten;
        tg = _tg;
        sp = _sp;
        dg = _dg;
    }
    Karaoke(const Karaoke &k) {
        ten = k.ten;
        tg = k.tg;
        sp = k.sp;
        dg = k.dg;
    }
    virtual string getLoai() = 0;
    virtual double getTinhtien() = 0;
    void xuat() {
        cout << ". Loai khach: " << getLoai() << endl;
        cout << "Ho Ten: " << ten << endl;
        cout << "Thoi gian su dung: " << tg << endl;
        cout << "So phong: " << sp << endl;
        cout << "So tien phai tra: " << getTinhtien();
        cout << endl;
    }
};
class KHVIP : public Karaoke {
public:
    KHVIP(string _ten = "", int _tg = 0, int _sp = 0, 
    int _dg = 0) : Karaoke( _ten, _tg, _sp, _dg) {};
    string getLoai() { return "VIP"; }
    double getTinhtien() {
        return (getdg() * gettg()) - (getdg() * gettg() * 0.1); 
    }
};
class KHT : public Karaoke {
public:
    KHT(string _ten = "", int _tg = 0, int _sp = 0, 
    int _dg = 0) : Karaoke( _ten, _tg, _sp, _dg) {};
    string getLoai() { return "Thuong"; }
    double getTinhtien() {
        return gettg() * getdg(); 
    }
};
int main () {
    int n, dg;
    cin >> n >> dg;
    Karaoke *a[10];
    for(int i = 0; i < n; i++) {
        cin.ignore();
        string s;
        string ten;
        int tg, sp;
        cin >> s;
        cin.ignore();
        getline(cin, ten);
        cin >> tg >> sp;
        if(s == "T") {
            a[i] = new KHT( ten, tg, sp, dg);
        } else if(s == "VIP") {
            a[i] = new KHVIP( ten, tg, sp, dg);
        }
    }
    for(int i = 0; i < n; i++) {
        cout << i + 1;
        a[i]->xuat();
    }
}