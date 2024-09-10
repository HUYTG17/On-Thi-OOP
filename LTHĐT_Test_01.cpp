#include <iostream>
using namespace std;
class Hocsinh {
    string hoTen; 
    double diemVan;
    double diemToan;
public:
    void sethoTen(string k) { hoTen = k; }
    void stdiemVan(double k) { diemVan = k; }
    void setdiemToan(double k) { diemToan = k; }
    string gethoTen() { return hoTen; }
    double getdiemVan() { return diemVan; }
    double getdiemToan() { return diemToan; }
    Hocsinh() {
        hoTen = "";
        diemVan = 0;
        diemToan = 0;
    }
    Hocsinh(string _hoTen, double _diemVan, double _diemToan) {
        hoTen = _hoTen;
        diemVan = _diemVan;
        diemToan = _diemToan;
    }
    ~Hocsinh(){};
    double TinhDiemtrungbinh() {
        return (diemVan + diemToan) / 2;
    }
    string Xeploai() {
        if(TinhDiemtrungbinh() >= 8.0) return "Gioi";
        else if(TinhDiemtrungbinh() >= 7.0) return "Kha";
        else if(TinhDiemtrungbinh() >= 5.0) return "Trung binh";
        else return "Yeu";
    }
    friend istream& operator >> (istream& is, Hocsinh &hs) {
        getline(is, hs.hoTen);
        is >> hs.diemVan;
        is >> hs.diemToan;
        is.ignore();
        return is;
    }
    friend ostream& operator << (ostream& os, Hocsinh hs) {
        os << hs.hoTen << endl << hs.Xeploai();
        return os;
    }
};
int main () {
    int n;
    cin >> n;
    Hocsinh a[n];
    cin.ignore();
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double max = a[0].TinhDiemtrungbinh();
    for(int i = 1; i < n; i++) {
        if(max < a[i].TinhDiemtrungbinh()) max = a[i].TinhDiemtrungbinh();
    }
    for(int i = 0; i < n; i++) {
        if(max == a[i].TinhDiemtrungbinh()) {
            cout << a[i];
        }
    }
}