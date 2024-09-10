#include <iostream>
using namespace std;
class Nhanvien {
    string name;
    double lcb;
    double bl; 
public:
    void setname(string k) { name = k; }
    void setlcb(double k) { lcb = k; }
    void setbl(double k) { bl = k; }
    string getname() { return name; }
    double getlcb() { return lcb; }
    double getbl() { return bl; }
    Nhanvien() {
        name = "";
        lcb = 500000;
        bl = 1;
    }
    Nhanvien(string hoTen, double luongcoban, double bacluong) {
        name = hoTen;
        lcb = luongcoban;
        bl = bacluong;
    }
    double TinhLuong() {
        return lcb * bl;
    }
    string Xeploai() {
        if(bl >= 5.0) return "Gioi";
        else if(bl >= 4.0) return "Kha";
        else if(bl >= 3.0) return "Trung binh";
        else return "Yeu";
    }
    friend istream& operator >> (istream& is, Nhanvien &nv) {
        getline(is, nv.name);
        is >> nv.lcb;
        is >> nv.bl;
        is.ignore();
    }
    friend ostream& operator << (ostream& os, Nhanvien nv) {
        os << nv.name << endl;
    }
};
class M {
    int n;
    Nhanvien a[100];
public:
    void setn(int k) { n = k; }
    int getn() { return n; }
    Nhanvien& operator [] (int i) {
        return a[i];
    }
    M(int _n = 0, Nhanvien _a[] = new Nhanvien {}) {
        n = _n;
        for(int i = 0; i < n; i++) {
            a[i] = _a[i];
        }
    }
    M(const M &m) {
        n = m.n;
        for(int i = 0; i < n; i++) {
            a[i] = m.a[i];
        }
    }
    double max() {
       double max = a[0].TinhLuong();
       for(int i = 1; i < n; i++) {
           if(max < a[i].TinhLuong()) max = a[i].TinhLuong();
       }
       return max;
    }
    int pos() {
        double max1 = max();
        int ind;
        for(int i = 0; i < n; i++) {
            if(max1 == a[i].TinhLuong()) {
                ind = i;
            } 
        }
        return ind;
    }
    friend istream& operator >> (istream& is, M &m) {
        is >> m.n;
        is.ignore();
        for(int i = 0; i < m.n; i++) {
            is >> m[i];
            is.clear();
        }
        return is;
    }
    friend ostream& operator << (ostream& os, M m) {
        os << m[m.pos()].getname() << endl << m[m.pos()].Xeploai();
        return os;
    }
};
int main () {
    M a;
    cin >> a;
    cout << a;
}