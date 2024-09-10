#include <iostream>
#include <iomanip>
using namespace std;
class Person {
    string name;
    string id;
    double salary;
public:
    void setname(string k) { name = k; }
    void setid(string k) { id = k; }
    void setsalary(double k) { salary = k; }
    string getname() { return name; }
    string getid() { return id; }
    double getsalary() { return salary; }
    Person(string _name = "", string _id = "", double _salary = 0) {
        name = _name;
        id = _id;
        salary = _salary;
    }
    Person(const Person &p) {
        name = p.name;
        id = p.id;
        salary = p.salary;
    }
    ~Person(){};
    virtual string getLoai() = 0;
    virtual double gettinhTien() = 0;
    virtual bool ktr() = 0;
    void xuat() {
        cout << ". " << getLoai() << endl;
        cout << "Ho va ten : " << name << endl;
        cout << "Ma sinh vien : " << id << endl;
        cout << "Luong co ban : " << fixed << setprecision(0) << salary << endl;
        cout << "Tong luong : " << fixed << setprecision(0) << gettinhTien() << endl;
        if(ktr()) {
            cout << "True";
        } else {
            cout << "False";
        }
    }
};
class CN : public Person {
    double hsl, tien;
public:
    CN(string _name = "", string _id = "", double _salary = 0, double _hsl = 0,
    double _tien = 0) : Person(_name, _id, _salary) {
        hsl = _hsl;
        tien = _tien;
    }
    CN(const CN &p) : Person(p) {
        hsl = p.hsl;
        tien = p.tien;
    }
    ~CN(){};
    string getLoai() { return "Cu nhan"; }
    double gettinhTien() {
        return hsl * getsalary();
    }
    bool ktr() {
        if(getsalary() >= tien) {
            return true;
        }
        return false;
    }
};
class ThS : public Person {
    double hb, tien1;
public:
    ThS(string _name = "", string _id = "", double _salary = 0, double _hb = 0,
    double _tien1 = 0) : Person(_name, _id, _salary) {
        hb = _hb;
        tien1 = _tien1;
    }
    ThS(const ThS &p) : Person(p) {
         hb = p.hb;
        tien1 = p.tien1;
    }
    ~ThS(){};
    string getLoai() { return "Thac si"; }
    double gettinhTien() {
        return hb + getsalary();
    }
    bool ktr() {
        if(getsalary() >= tien1) {
            return true;
        }
        return false;
    }
};
class TS : public Person {
    double tc, tda;
public:
    TS(string _name = "", string _id = "", double _salary = 0, double _tc = 0,
    double _tda = 0) : Person(_name, _id, _salary) {
        tc = _tc;
        tda = _tda;
    }
    TS(const TS &p) : Person(p) {
         tc = p.tc;
        tda = p.tda;
    }
    ~TS(){};
    string getLoai() { return "Tien si"; }
    double gettinhTien() {
        return tc + getsalary();
    }
    bool ktr() {
        if(getsalary() >= tda) {
            return true;
        }
        return false;
    }
};
int main () {
    int n;
    cin >> n;
    cin.ignore();
    Person *p[10];
    for(int i = 0; i < n; i++) {
        string s, name, id;
        double lcb;
        cin >> s;
        cin.ignore();
        getline(cin, name);
        getline(cin, id);
        cin >> lcb;
        if(s == "CN") {
            double hsl, tien; cin >> hsl >> tien;
            p[i] = new CN(name, id, lcb, hsl, tien);
        } else if(s == "ThS") {
            double hb, tien1; cin >> hb >> tien1;
            p[i] = new ThS(name, id, lcb, hb, tien1);
        } else {
            double tc, tda; cin >> tc >> tda;
            p[i] = new TS(name, id, lcb, tc, tda);
        }
    }
    for(int i = 0; i < n; i++) {
        cout << i + 1;
        p[i]->xuat();
        cout << endl << endl;
    }
    cout << "Danh sach nhan vien co luong max\n";
    int max = p[0]->gettinhTien();
    int cnt = 0; // 3 tk trùng 
    for(int i = 0; i < n; i++) {
        if(max < p[i]->gettinhTien()) max = p[i]->gettinhTien();
        cnt++;
    }
    if(cnt == 0) {
        cout << 0;
    } else {
        for(int i = 0; i < n; i++) {
            if(max == p[i]->gettinhTien()) {
                cout << p[i]->getname() << " : " << p[i]->gettinhTien() << endl;
            }
        }
    }
}