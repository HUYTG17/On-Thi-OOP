#include <iostream>
#include <iomanip>
using namespace std;
class NV {
    string ma, name;
    double lcb;
public:
    void setma(string k) { ma = k; }
    void setname(string k) { name = k; }
    void setlcb(double k) { lcb = k; }
    string getma() { return ma; }
    string getname() { return name; }
    double getlcb() { return lcb; }    
    NV(string _ma = "", string _name = "", double _lcb = 0) {
        ma = _ma;
        name = _name;
        lcb = _lcb;
    }
    NV(const NV &nv) {
        ma = nv.ma;
        name = nv.name;
        lcb = nv.lcb;
    }
    ~NV(){};
    virtual string getLoai() = 0;
    virtual double gettinhTien() = 0;
    void print() {
        cout << "Loai nhan vien: " << getLoai() << endl;
        cout << "Ma nhan vien: " << ma << endl;
        cout << "Ho ten: " << name << endl;
        cout << "Tong luong: " << fixed << setprecision(0) << gettinhTien() << endl;
    }
};
class BC : public NV {
    double hsl;
    double pc;
public:
    BC(string _ma = "", string _name = "", double _lcb = 0,
    double _hsl = 0, double _pc = 0) : NV(_ma, _name, _lcb) {
        hsl = _hsl;
        pc = _pc;
    }
    BC(const BC &nv) : NV(nv) {
        hsl = nv.hsl;
        pc = nv.pc;
    }
    ~BC(){};
    string getLoai() { return "BC"; }
    double gettinhTien() {
        return getlcb() * hsl + pc;
    }
};
class HD : public NV {
    double tc;
    int sn;
    double hs;
public:
    HD(string _ma = "", string _name = "", double _lcb = 0, 
    double _tc = 0, int _sn = 0, double _hs = 0.1) : NV(_ma, _name, _lcb) {
        tc = _tc;
        sn = _sn;
        hs = _hs;
    }
    HD(const HD &nv) : NV(nv) {
        tc = nv.tc;
        sn = nv.sn;
        hs = nv.hs;
    }
    ~HD(){};
    string getLoai() { return "HD"; }
    double gettinhTien() {
        if(sn > 22) {
            int snv = sn - 22;
            double lvg = snv * hs * tc;
            return getlcb() + lvg;
        } else {
            return getlcb();
        }
    }
};
int main () {
    int n;
    cin >> n;
    NV *a[100];
    cin.ignore();
    for(int i = 0; i < n; i++) {
        string type, ma , name;
        double lcb;
        cin >> type;
        cin.ignore();
        getline(cin, ma);
        getline(cin, name);
        cin >> lcb;
        if(type == "BC") {
            double hsl, pc; cin >> hsl >> pc;
            a[i] = new BC(ma, name, lcb, hsl, pc);
        } else {
            double tc;
            int sn;
            double hs; 
            cin >> tc >> sn >> hs;
            a[i] = new HD(ma, name, lcb, tc, sn, hs);
        }
    }
    double max = a[0]->gettinhTien();
    for(int i = 0; i < n; i++) {
        if(max < a[i]->gettinhTien()) max = a[i]->gettinhTien();
    }
    for(int i = 0; i < n; i++) {
        if(max == a[i]->gettinhTien()) {
            a[i]->print();
            cout << endl;
        }
    }
    double s = a[0]->gettinhTien();
    for(int i = 1; i < n; i++) {
        s = s + a[i]->gettinhTien();
    }
    cout << "Tong luong tat ca nhan vien: ";
    cout << s;
}