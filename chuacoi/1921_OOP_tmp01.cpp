#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class PS {
    int tu;
    int mau;
public:
    void setTu(int k);
    int getTu();
    void setMau(int k);
    int getMau();
    PS(int _tu = 0, int _mau = 1);
    PS(const PS &p);
    friend istream& operator >> (istream& is, PS &p);
    friend ostream& operator << (ostream& os, PS p);
    PS psRutGon();
    PS psNghichDao();
    double getGiaTri();
};
// int gcd(int a, int b) {
//     a = abs(a); b = abs(b);
//     while(a*b != 0) {
//         if(a > b) a %= b;
//         else b %= a;
//     }
//     return a + b;
// }
int gcd (int  a , int  b){
    if(b==0) return a;
    return gcd(b, a%b);
}
void PS::setTu(int k) { tu = k; }
int PS::getTu() { return tu; }
void PS::setMau(int k) { mau = k; }
int PS::getMau() { return mau; }
PS::PS(int _tu, int _mau) { 
    tu = _tu; 
    mau = _mau;
}
PS::PS(const PS &p) {
    tu = p.tu;
    mau = p.mau;
}
istream& operator >> (istream& is, PS &p) {
    is >> p.tu >> p.mau;
    if(p.tu < 0 && p.mau < 0) {
        p.tu = -p.tu;
        p.mau = -p.mau;
    }
    else if(p.mau < 0) {
        p.tu = -p.tu;
        p.mau = -p.mau;
    }
    return is;
}
ostream& operator << (ostream& os, PS p) {
    if(p.tu < 0 && p.mau < 0) {
        p.tu = -p.tu;
        p.mau = -p.mau;
    }
    else if(p.mau < 0) {
        p.tu = -p.tu;
        p.mau = -p.mau;
    }
    else if(p.mau == 0) {
        os << "0/1" << endl;
    }
    os << p.tu << "/" << p.mau;
    return os;
}
PS PS::psRutGon() {
    PS k;
    int uc = gcd(tu, mau);
    k.tu = tu / uc;
    k.mau = mau / uc;
    return k;
}
PS PS::psNghichDao() {
    if(tu == 0) return PS(0, 1);
    return PS(mau, tu);
}
double PS::getGiaTri() { 
    double s;
    s = (double)tu / mau;
    return s; 
}
int main () {
    PS a;
    PS b;
    // cout << a << endl << b << endl;
    cin >> a >> b;
    cout << a << endl << b << endl;
    cout << a.getTu() + b.getMau() << endl;
    cout << fixed << setprecision(3) << a.getGiaTri() << " ";
    cout << fixed << setprecision(3) << b.getGiaTri() << endl;
    PS k;
    k = a.psRutGon();
    cout << k << endl;
    PS kq;
    kq = (b.psNghichDao()).psRutGon();
    cout << kq;
    return 0;
}
