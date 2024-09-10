#include <iostream>
using namespace std;
class Device {
private:
    string model;
    string manufactory;
    int power;
    double cost;
public:
    void setmodel(string k) { model = k; }
    void setmanufactory(string k) { manufactory = k; }
    void setpower(int k) { power = k; }
    void setcost(double k) { cost = k; }
    string getmodel() { return model; }
    string getmanufactory() { return manufactory; }
    int getpower() { return power; }
    double getcost() { return cost; }
    Device(string _model = "", string _manufactory = "", int _power = 0, double _cost = 0) {
        model = _model;
        manufactory = _manufactory;
        power = _power;
        cost = _cost;
    }
    Device(const Device &d) {
        model = d.model;
        manufactory = d.manufactory;
        power = d.power;
        cost = d.cost;
    }
    double getTotalCost() {
        return cost + cost * 0.1;
    }
    friend istream& operator >> (istream& is, Device &d) {
        is.ignore();
        getline(is, d.model);    // ko ignore() thì is >> ws nó xóa khoảng trắng lun is >> ws 2 chuỗi
        getline(is, d.manufactory);
        is >> d.power;
        is >> d.cost;
        return is;
    }
    friend ostream& operator << (ostream& os, Device d) {
        os << d.model << "-" << d.manufactory << "-";
        os << d.power << "W-" << d.getTotalCost();
        return os;
    }
};
class Mdv {
private:
    int n;
    Device a[10];
public:
    void setn(int k) { n = k; }
    int getn() { return n; }
    Device& operator [] (int i) {
        return a[i];
    }
    Mdv(int _n = 0, Device _a[] = new Device{}) {
        n = _n;
        for(int i = 0; i < n; i++) {
            a[i] = _a[i];
        }
    }
    Mdv(const Mdv &d) {
        n = d.n;
        for(int i = 0; i < n; i++) {
            a[i] = d.a[i];
        }
    }
    friend istream& operator >> (istream& is, Mdv &m) {
        is >> m.n;
        for(int i = 0; i < m.n; i++) {
            is >> m.a[i];
        }
        return is;
    }
    friend ostream& operator << (ostream& os, Mdv m) {
        for(int i = 0; i < m.n; i++) {
            os << m.a[i];
            // if(i != m.n) os << endl;
        }
        return os;
    }
};
int main () {
    Mdv a;
    cin >> a;
    cout << a;
}