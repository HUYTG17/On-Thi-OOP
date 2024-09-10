#include <iostream>
using namespace std;
class Ve {
    string tenc;
    int a[10];
    int gia;
public:
    void settenc(string k) { tenc = k; }
    void setgia(int k) { gia = k; }
    string gettenc() { return tenc; }
    int& operator [] (int i) {
        return a[i];
    }
    Ve(string _tenc = "", int _a[] = new int {}, int _gia = 0) {
        tenc = _tenc;
        for(int i = 0; i < 3; i++) {
            a[i] = _a[i];
        }
        gia = _gia;
    }
    Ve(const Ve &v) {
        tenc = v.tenc;
        for(int i = 0; i < 3; i++) {
            a[i] = v.a[i];
        }
        gia = v.gia;
    }
    ~Ve(){};
    friend istream& operator >> (istream& is, Ve &v) {
        getline(is >> ws, v. tenc);
        for(int i = 0; i < 3; i++) {
            is >> v.a[i];
        }
        is >> v.gia;
        return is;
    }
    friend ostream& operator << (ostream& os, Ve v) {
        os << "- Thong Tin Chuyen Bay:\n";
        os << "Ten Chuyen: " << v.tenc << "\n";
        os << "Ngay Bay:\n";
        os << "tNgay/Thang/Nam: ";
        for(int i = 0; i < 3; i++) {
            os << v.a[i];
            if(i != 2) {
                cout << "/";
            }
        }
        os << "\n";
        os << "Gia Ve: " << v.gia << endl;
    }
};
class Person {
    string hoten;
    string gt;
    int tuoi;
    int n;
    Ve a[100];
public:
    Person(string _hoten = "", string _gt = "", int _tuoi = 0, int _n = 0, 
    Ve _a[] = new Ve {}) {
        hoten = _hoten;
        gt = _gt;
        tuoi = _tuoi;
        n = _n;
        for(int i = 0; i < n; i++) {
            a[i] = _a[i];
        }
    }
    Person(const Person &p) {
       hoten = p.hoten;
        gt = p.gt;
        tuoi = p.tuoi;
        n = p.n;
        for(int i = 0; i < n; i++) {
            a[i] = p.a[i];
        }
    }
    ~Person(){};
    friend istream& operator >> (istream& is, Person &p) {
        string hoten, gt;
        int tuoi, n;
        Ve a[100];
        getline(cin >> ws, hoten);
        getline(cin >> ws, gt);
        cin >> tuoi;
        cin >> n;
        cin.ignore();
        for(int i = 0; i < p.n; i++) {
            cin >> p.a[i];
        }
        p = Person(hoten, gt, tuoi, n, a);
        return is;
    }
    friend ostream& operator << (ostream& os, Person p) {
        os << "- Thong Tin Khach Hang:\n";
        os << "Ho Ten: " << p.hoten << endl;
        os << "Gioi tinh: " << p.gt << endl;
        os << "Tuoi: " << p.tuoi << endl;
        for(int i = 0; i < p.n; i++) {
            os << p.a[i] << endl;
        }
        return os;
    }
};
int main () {
    Person a;
    cin >> a;
    cout << a;
    
}