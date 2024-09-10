#include <iostream>
using namespace std;
class NV {
private:
    string ms;
    string ten;
    int nam;
    string mst;
    string loai;
public:
    void setms(string k) { ms = k; }
    void setten(string k) { ten = k; }
    void setnam(int k) { nam = k; }
    void setmst(string k) { mst = k; }
    void setloai(string k) { loai = k; }
    string getms() { return ms; }
    string getten() { return ten; }
    int getnam() { return nam; }
    string getmst() { return mst; }
    string getloai() { return loai; }
    NV(string _ms = "", string _ten = "", int _nam = 0, string _mst = "", string _loai = "") {
        ms = _ms;
        ten = _ten;
        nam = _nam;
        mst = _mst;
        loai = _loai;
    }
    NV(const NV &n) {
        ms = n.ms;
        ten = n.ten;
        nam = n.nam;
        mst = n.mst;
        loai = n.loai;
    }
    virtual ~NV(){};
    virtual int getTinhtien() = 0;
    static int lcb;
    static int tc;
};
int NV :: lcb;
int NV :: tc;
class TTG : public NV {
private:
    int bl, pc;
public:
    void setbl(int k) { bl = k; }
    void setpc(int k) { pc = k; }
    int getbl() { return bl; }
    int getpc() { return pc; }
    TTG(string _ms = "", string _ten = "", int _nam = 0, string _mst = "", string _loai = "",
    int _bl = 0, int _pc = 0) : NV(_ms, _ten, _nam, _mst, _loai) {
        bl = _bl;
        pc = _pc;
    }
    TTG(const TTG &n) : NV(n) {
        bl = n.bl;
        pc = n.pc;
    }
    ~TTG(){};
    int getTinhtien() {
        return bl * lcb + pc;
    }
};
class BTG : public NV {
private:
    int tg;
public: 
    void settg(int k) { tg = k; }
    int gettg() { return tg; }
    BTG(string _ms = "", string _ten = "", int _nam = 0, string _mst = "", string _loai = "",
    int _tg = 0) : NV(_ms, _ten, _nam, _mst, _loai) {
        tg = _tg;
    }
    BTG(const BTG &n) : NV(n) {
        tg = n.tg;
    }
    ~BTG(){};
    int getTinhtien() {
        if(getmst() != "#") {
            return tg * tc - (0.1 * tg * tc);
        } else {
            return tg * tc - (0.2 * tg* tc);
        }
    }
};
void hienThiLuong(NV *a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << endl << a[i]->getms() << ": " << a[i]->getten() << endl;
        cout << "Loai: ";
        if(a[i]->getloai() == "TTG") {
            cout << "Toan thoi gian\n";
        } else {
            cout << "Ban thoi gian\n";
        }
        cout << "Ma so thue:";
            if(a[i]->getmst() != "#") {
                cout << a[i]->getmst() << endl;
            } else {
                cout << "Khong co" << endl;
            }
        cout << "Nam sinh:" << a[i]->getnam() << endl;
        if(a[i]->getloai() == "TTG") {
            cout << "Bac: " << static_cast<TTG*>(a[i])->getbl() << endl;
            cout << "Phu cap: " << static_cast<TTG*>(a[i])->getpc() << endl;
            cout << "Luong: " << static_cast<TTG*>(a[i])->getbl() << "*";
            cout << NV::lcb << "+" << static_cast<TTG*>(a[i])->getpc() << "=";
            cout << a[i]->getTinhtien() << " (vnd)" << endl;
        } else {
            cout << "Thoi gian: " << static_cast<BTG*>(a[i])->gettg() << " (gio)" << endl;
            cout << "Luong: " << static_cast<BTG*>(a[i])->gettg() << "*";
            cout << NV::tc << "-" << static_cast<BTG*>(a[i])->gettg() << "*";
            cout << NV::tc << "*";
            if(a[i]->getmst() != "#") {
                cout << 10;
            } else {
                cout << 20;
            }
            cout << "%=" << a[i]->getTinhtien() << " (vnd)" << endl;
        }
    }
}
int main () {
    int n;
    cin >> n;
    cin >> NV:: lcb >> NV :: tc;
    NV *a [10];
    for(int i = 0; i < n; i++) {
        string loai;
        string ms;
        string ten;
        int nam;
        string mst;
        cin >> loai >> ms;
        cin.ignore();
        getline(cin, ten);
        cin >> nam >> mst;
        if(loai == "TTG") {
            int bl, pc; cin >> bl >> pc;
            a[i] = new TTG(ms, ten, nam, mst, loai, bl, pc);
        } else {
            int tg; cin >> tg;
            a[i] = new BTG(ms, ten, nam, mst, loai, tg);
        }
    }
    cout << "Bang Tien Luong Cong Ty" << endl;
    hienThiLuong(a , n);
}