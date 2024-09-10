#include <iostream>
using namespace std;
class Person {
private:
    string ten;
    int ma;
    string sdt;
public:
    void setten(string k) { ten = k; }
    void setma(int k) { ma = k; }
    void setsdt(string k) { sdt = k; }
    string getten() { return ten; }
    int getma() { return ma; }
    string getsdt() { return sdt; }
    Person(string _ten = "", int _ma = 0, string _sdt = "") {
        ten = _ten;
        ma = _ma;
        sdt = _sdt;
    }
    Person(const Person &p) {
        ten = p.ten;
        ma = p.ma;
        sdt = p.sdt;
    }
    ~Person(){};
    friend istream& operator >> (istream& is, Person &p) {
        getline(is, p.ten);
        is >> p.ma;
        is.ignore();
        getline(is, p.sdt);
        return is;
    }
    friend ostream& operator << (ostream& os, Person p) {
        os << "Ten khach hang: " << p.ten << endl;
        os << "Ma khach hang: " << p.ma << endl;
        os << "So dien thoai: " << p.sdt << endl;
        return os;
    }
};
class KH : public Person {
private:
    int loai;
    int goi;
    int tg;
    string ngay;
public:
    void setloai(int k) { loai = k; }
    void setgoi(int k) { goi = k; }
    void settg(int k) { tg = k; }
    void setngay(int k) { ngay = k; }
    int getloai() { return loai; }
    int getgoi() { return goi; }
    int gettg() { return tg; }
    string getngay() { return ngay; }
    KH(string _ten = "", int _ma = 0, string _sdt = "", int _loai = 0, 
    int _goi = 0,int _tg = 0, string _ngay = "") : Person( _ten, _ma, _sdt) {
        loai = _loai;
        goi = _goi;
        tg = _tg;
        ngay = _ngay;
    }
    KH(const KH &k) : Person(k) {
        loai = k.loai;
        goi = k.goi;
        tg = k.tg;
        ngay = k.ngay;
    }
    ~KH(){};
    int ThanhTien() {
        int sum = 0;
        if(loai == 1 && tg == 1) {
            sum = 0.85 * 350000;
        } if(loai == 1 && tg == 2) {
            sum = 0.85 * 2100000;
        } if(loai == 1 && tg == 3) {
            sum = 0.85 * 3000000;
        }
        if(loai == 2 && tg == 1) {
            sum = 350000;
        } if(loai == 2 && tg == 2) {
            sum = 2100000;
        } if(loai == 2 && tg == 3) {
            sum = 3000000;
        }
        return sum;
    }
    friend istream& operator >> (istream& is, KH &k) {
        int loai;
        string ten;
        int ma;
        string sdt;
        string ngay;
        int goi;
        int tg;
        is >> loai;
        is.ignore();
        getline(is, ten);
        is >> ma;
        is.ignore();
        getline(is, sdt);
        getline(is, ngay);
        is >> goi;
        is >> tg;
        k = KH(ten, ma, sdt, loai, goi, tg, ngay);
        return is;
    }
    friend ostream& operator << (ostream& os, KH &k) {
        if(k.loai == 1) {
            os << "Loai khach hang: VIP" << endl;
        } else if(k.loai == 2) {
            os << "Loai khach hang: NOR" << endl;
        }
        os << "Ten khach hang: " << k.getten() << endl;
        os << "Ma khach hang: " << k.getma() << endl;
        os << "So dien thoai: " << k.getsdt() << endl;
        os << "Ngay dang ký: " << k.getngay() << endl;
        if(k.goi == 1) {
            os << "Goi tap: Gym" << endl;
        } else if(k.goi == 2) {
            os << "Goi tap: Yoga" << endl;
        }
        if(k.tg == 1) {
            os << "So thoi gian dang ky tap: 1 thang" << endl;
        } else if(k.tg == 2) {
            os << "So thoi gian dang ky tap: 6 thang" << endl;
        } else {
            os << "So thoi gian dang ky tap: 1 nam" << endl;
        }
        os << "Thanh tien: " << k.ThanhTien();
        return os;
    }
};
int main () {
    int n;
    cin >> n;
    KH a[100];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "So luong khach hang: " << n << endl;
    for(int i = 0; i < n; i++) {
        cout << "Khach hang thu: " << i + 1 << endl;
        cout << a[i] << endl;
        cout << endl;
    }
}