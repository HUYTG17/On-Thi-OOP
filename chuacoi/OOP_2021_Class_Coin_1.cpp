#include <iostream>
#include <iomanip>
using namespace std;
class Coin {
    string name;
    float price;
    float low;
    float high;
public:
    void setName(string k);
    void setPrice(float k);
    void setLow(float k);
    void setHigh(float k);
    string getName();
    float getPrice();
    float getLow();
    float getHigh();
    Coin(string _name = "NoName", float _price = 0, float _low = 0,
    float _high = 0);
    Coin(const Coin &c);
    float maxChange();
    friend istream& operator >> (istream& is, Coin &c);
    friend ostream& operator << (ostream& os, Coin m);
};
void Coin::setName(string k) { name = k; }
void Coin::setPrice(float k) { price = k; }
void Coin::setLow(float k) { low = k; }
void Coin::setHigh(float k) { high = k; }
string Coin::getName() { return name; }
float Coin::getPrice() { return price; }
float Coin::getLow() { return low; }
float Coin::getHigh() { return high; }
Coin::Coin(string _name, float _price, float _low,
float _high) {
    name = _name;
    price = _price;
    low = _low;
    high = _high;
}
Coin::Coin(const Coin &c) {
    name = c.name;
    price = c.price;
    low = c.low;
    high = c.high;
}
float Coin::maxChange() { return high - low; }
istream& operator >> (istream& is, Coin &c) {
    is >> c.name;
    is >> c.price >> c.low >> c.high;
    return is;
}
ostream& operator << (ostream& os, Coin m) {
    cout << fixed << setprecision(2) << m.name 
    << "-" << m.price << "-" << m.low << "-" << m.high << "-" << m.maxChange();
}
// class MCoin: public Coin {
//     int n;
//     Coin a[10];
// public:
//     void setN(int k);
//     int getN();
//     Coin& operator [] (int i) {
//         return a[i];
//     }
//     MCoin(int _n = 1, Coin _a[] = new Coin{}, 
//     string _name = "NoName", float _price = 0, float _low = 0,
//     float _high = 0): Coin(_name, _price, _low, _high) {
//         n = _n;
//         for(int i = 0; i < n; i++) {
//             a[i] = _a[i];
//         }
//     }
//     MCoin(const MCoin &m): Coin(m) {
//         n = m.n;
//         for(int i = 0; i < n; i++) {
//             a[i] = m.a[i];
//         }
//     }
//     friend istream& operator >> (istream& is, MCoin &m);
//     friend ostream& operator << (ostream& os, MCoin m);
// };
// void MCoin::setN(int k) { n = k; }
// int MCoin::getN() { return n; }
// istream& operator >> (istream& is, MCoin &m) {
//     string name;
//     float price, low, high;
//     int n;
//     Coin a[10];
//     is >> n;
//     for(int i = 0; i < n; i++) {
//         getline(is, name);
//         is >> price >> low >> high;
//     }
//     m = MCoin(n, a, name, price, low, high);
//     return is;
// }
// ostream& operator << (ostream& os, MCoin m) {
//     os << fixed << setprecision(2) << m.getName() 
//     << "-" << m.getPrice() << "-" << m.getLow() 
//     << "-" << m.getHigh() << "-" << m.maxChange();
//     return os;
// }
int main () {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        Coin a;
        cin >> a;
        cout << a << endl;
    }
}