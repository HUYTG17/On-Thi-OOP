#include <iostream>
using namespace std;
class KH {
    string name;
    int tgsd;
    int smsd;
    int dg;
public: 
    void setName(string k) { name = k; }
    void setTgsd(int k) { tgsd = k; }
    void setSmsd(int k) { smsd = k; }
    void setDg(int k) { dg = k; }
    string getName() { return name; }
    int getTgsd() { return tgsd; }
    int getSmsd() { return smsd; }
    int getDg() { return dg; }
    KH(string _name = "", int _tgsd = 0, int _smsd = 0, int _dg = 0) {
        name = _name; 
        tgsd = _tgsd;
        smsd = _smsd;
        dg = _dg;
    }
    KH(const KH &k) {
        name = k.name;
        tgsd = k.tgsd;
        smsd = k.smsd;
        dg = k.dg;
    }
    // ~KH(){};
    virtual string getLoai() = 0;
    virtual double getTinhtien() = 0;
    void xuat() {
        cout << ". Loai khach: " << getLoai() << endl;
        cout << "Ho Ten: " << name << endl;
        cout << "Thoi gian su dung: " << tgsd << endl;
        cout << "So may: " << smsd << endl;
        cout << "So tien phai tra: " << getTinhtien() << endl;
        cout << endl;
    }
};
class KHVIP : public KH {
    int dgvip;
public: 
    KHVIP(string _name = "", int _tgsd = 0, int _smsd = 0, int _dg = 0, 
    int _dgvip = 0): KH(_name, _tgsd, _smsd, _dg) {
        dgvip = _dgvip;
    }
    KHVIP(const KHVIP &k) : KH(k) {
        dgvip = k.dgvip;
    }
    // ~KHVIP(){};
    string getLoai() { return "VIP"; }
    double getTinhtien() {
        if(getTgsd() >= 4) return dgvip * 4;
        else return getDg() * getTgsd();
    }
};
class KHTX : public KH {
    int hskm;
public: 
    KHTX(string _name = "", int _tgsd = 0, int _smsd = 0, int _dg = 0, 
    int _hskm = 0): KH(_name, _tgsd, _smsd, _dg) {
        hskm = _hskm;
    }
    KHTX(const KHTX &k) : KH(k) {
        hskm = k.hskm;
    }
    // ~KHTX(){};
    string getLoai() { return "TX"; }
    double getTinhtien() {
        return (getTgsd() * getDg() - getTgsd() * hskm);
    }
};
class KHKTX : public KH {
    int dluongdl, dgdl;
public:
    KHKTX(string _name = "", int _tgsd = 0, int _smsd = 0, int _dg = 0, 
    int _dluongdl = 0, int _dgdl = 0): KH(_name, _tgsd, _smsd, _dg) {
        dluongdl = _dluongdl;;
        dgdl = _dgdl;
    }
    KHKTX(const KHKTX &k) : KH(k) {
        dluongdl = k.dluongdl;
        dgdl = k.dgdl;
    }
    ~KHKTX(){};
    string getLoai() { return "KTX"; }
    double getTinhtien() {
        return getTgsd() * getDg() + dluongdl * dgdl;
    }
};
int main () {
    KH *p[10];
    int n, dg, dgvip, dgdl;
    cin >> n >> dg >> dgvip >> dgdl;
    for(int i = 0; i < n; i++) {
        cin.ignore();
        string s;
        string name;
        int tgsd, smsd;
        cin >> s;
        cin.ignore();
        getline(cin, name);
        cin >> tgsd >> smsd;
        if(s == "VIP") {
            p[i] = new KHVIP(name, tgsd, smsd, dg, dgvip);
        }
        else if(s == "TX") {
            int hskm; cin >> hskm;
            p[i] = new KHTX(name, tgsd, smsd, dg, hskm);
        }
        else {
            int dluongdl; cin >> dluongdl;
            p[i] = new KHKTX(name, tgsd, smsd, dg, dluongdl, dgdl);
        }
    }
    for(int i = 0; i < n; i++) {
        cout << i + 1;
        p[i]->xuat();
    }
}