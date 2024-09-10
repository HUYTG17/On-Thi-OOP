#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Book {
    string ma;
    int ngay;
    int sl;
public:
   void setma(string k) { ma = k; }
   void setngay(int k) { ngay = k; }
   void setsl(int k) { sl = k; }
   string getma() { return ma; }
   int getngay() { return ngay; }
   int getsl() { return sl; }
   Book(string _ma = "", int _ngay = 1, int _sl = 1) {
       ma = _ma;
       ngay = _ngay;
       sl = _sl;
   }
   Book(const Book &b) {
       ma = b.ma;
       ngay = b.ngay;
       sl = b.sl;
   }
   ~Book(){};
   friend istream& operator >> (istream& is, Book &b) {
       is >> b.ma;
       is >> b.ngay >> b.sl;
       return is;
   }
   friend ostream& operator << (ostream& os, Book b)  {
       if(b.ma == "SGK") {
            os << "-Sach Giao Khoa ";
       } else if(b.ma == "SGT") {
           os << "-Sach Giao Trinh ";
       } else if(b.ma == "SPL") {
           os << "-Sach Phap Luat ";
       } else if(b.ma == "SCI") {
           os << "-Tap Chi Khoa Hoc ";
       } else {
           os << "-Sach Ngoai Ngu ";
       }
       os << b.ngay << "-Ngay " << b.sl << "-Quyen\n";
       return os;
   }
   double getphimuon() {
       if(ma == "SGK") {
           return 1.000;
       } else if(ma == "SGT") {
           return 1.100;
       } else if(ma == "SPL") {
           return 1.500;
       } else if(ma == "SCI") {
           return 2.000;
       } else {
           return 3.000;
       }
   }
   double getphicoc() {
       if(ma == "SGK") {
           return 30.000;
       } else if(ma == "SGT" || ma == "SPL") {
           return 35.000;
       } else if(ma == "SCI") {
           return 20.000;
       } else {
           return 40.000;
       }
   }
};
class KH {
    string loai, hang, ma1, name, sdt;
    int n;
    Book a[100];
    double money;
public: 
    void setmoney(double k) { money = k; }
    double getmoney() { return money; }
    void setloai(string k) { loai = k; }
    void sethang(string k) { hang = k; }
    void setma1(string k) { ma1 = k; }
    void setname(string k) { name = k; }
    void setsdt(string k) { sdt = k; }
    string getloai() { return loai; }
    string gethang() { return hang; }
    string getma1() { return ma1; }
    string getname() { return name; }
    string getsdt() { return sdt; }
    void setn(int k) { n = k; }
    int getn() { return n; }
    Book& operator [] (int i) {
        return a[i];
    }
    KH(string _loai = "", string _hang = "", string _ma1 = "", string  _name = "",
    string _sdt = "", int _n = 0, Book _a[] = new Book {}, double _money = 0) {
        loai = _loai;
        hang = _hang;
        ma1 = _ma1;
        name = _name;
        sdt = _sdt;
        n = _n;
        for(int i = 0; i < n; i++) {
            a[i] = _a[i];
        }
        money = _money;
    }
    KH(const KH &k) {
        loai = k.loai;
        hang = k.hang;
        ma1 = k.ma1;
        name = k.name;
        sdt = k.sdt;
        n = k.n;
        for(int i = 0; i < n; i++) {
            a[i] = k.a[i];
        }
        money = k.money;
    }
    virtual~KH(){}
    virtual double TOTAL() = 0;
    void xuat() {
        cout << "Loai Khach Hang: ";
        if(loai == "GV") {
            cout << "GiangVien/GiaoVien\n";
        } else {
            cout << "HocSinh/SinhVien\n";
        }
        cout << "Hang Khach Hang: " << hang << endl;
        cout << "Ma So Khach Hang: " << ma1 << endl;
        cout << "Ho va Ten: " << name << endl;
        cout << "So Dien Thoai: " << sdt << endl;
        cout << "So quyen sach muon: " << n << endl;
        cout << "Danh Sach Cac Quyen Sach Muon: " << endl;
        for(int i = 0; i < n; i++) {
            cout << a[i];
        }
        if(TOTAL() == 0) cout << "Tong Tien: 0" << endl; 
        else cout << "Tong Tien: " << TOTAL() << endl;
        cout << "Tien Tra Lai: " << fixed << (money - TOTAL());
    }
    double tongtien() {
        double phimuon = 0;
        double phicoc = 0;
        int tongsachgv = 0;
        for(int i = 0; i < n; i++) {
            if(loai == "GV") {
                tongsachgv += a[i].getsl();
                if(a[i].getngay() > 15 && a[i].getngay() <= 30) {
                    phimuon += (a[i].getphimuon() * a[i].getsl());
                } else if(a[i].getngay() > 30) {
                    phimuon += a[i].getphimuon() * (pow((1 + 0.03), (a[i].getngay() - 31))) * a[i].getsl();
                }
            } else {
                phicoc += a[i].getphicoc() * a[i].getsl();
                if(a[i].getngay() <= 15) {
                    phimuon += (a[i].getphimuon() * a[i].getsl());
                } else {
                    phimuon += a[i].getphimuon() * (pow((1 + 0.05), (a[i].getngay()-16))) * a[i].getsl();
                }
            }
        }
        if(loai == "GV") {
                if(tongsachgv >= 10) {
                return (phimuon + phicoc) * 0.5;
                }
            } else {
                return (phicoc + phimuon);
            }
    }
};
class GV : public KH {
public:
    GV(string _loai = "", string _hang = "", string _ma1 = "", string  _name = "",
    string _sdt = "", int _n = 0, Book _a[] = new Book {}, double _money = 0) : KH(_loai,
    _hang, _ma1, _name, _sdt, _n, _a, _money) {}
    ~GV(){}
    double TOTAL() {
        double total = tongtien();
        if(gethang() == "Vang") {
            total = total * 0.7;
        } else if(gethang() == "Bac") {
            total = total * 0.8;
        } else if(gethang() == "Dong") {
            total = total * 0.9;
        }
        return total;
    }
};
class HS : public KH {
public:
    HS(string _loai = "", string _hang = "", string _ma1 = "", string  _name = "",
    string _sdt = "", int _n = 0, Book _a[] = new Book {}, double _money = 0) : KH(_loai,
    _hang, _ma1, _name, _sdt, _n, _a, _money) {}
    ~HS(){}
    double TOTAL() {
        double total = tongtien();
        if(gethang() == "Vang") {
            total = total * 0.7;
        } else if(gethang() == "Bac") {
            total = total * 0.8;
        } else if(gethang() == "Dong") {
            total = total * 0.9;
        }
        return total;
    }
};
int main () {
    int n;
    cin >> n;
    KH *a[10];
    for(int i = 0; i < n; i++) {
        string type, hang, ma, name, sdt;
        int so;
        Book b[100];
        cin >> type >> hang >> ma;
        cin.ignore();
        getline(cin, name);
        cin >> sdt;
        cin >> so;
        for(int j = 0; j < so; j++) {
            cin >> b[j];
        }
        double money;
        cin >> money;
        if(type == "GV") {
            a[i] = new GV(type , hang, ma, name, sdt, so, b, money);
        } else {
            a[i] = new HS(type , hang, ma, name, sdt, so, b, money);
        }
    }
    for(int i = 0; i < n; i++) {
        a[i]->xuat();
        if(i != n - 1) {
            cout << endl << endl;
        }
    }
    return 0;
}