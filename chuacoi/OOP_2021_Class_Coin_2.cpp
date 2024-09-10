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
    bool operator > (Coin a);
    bool operator < (Coin a);
    bool operator == (Coin a);
    Coin operator += (double a) {
        price = price + a;
        return *this;
    }
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
    is.ignore();
    is >> c.name;
    is >> c.price >> c.low >> c.high;
    return is;
}
ostream& operator << (ostream& os, Coin m) {
    os  << m.name << fixed << setprecision(2)
    << "-" << m.price << "-" << m.low << "-" << m.high << "-" << m.maxChange() << endl;
    return os;
}
bool Coin::operator > (Coin a) {
    return price > a.price;
}
bool Coin::operator < (Coin a) {
    return price < a.price;
}
bool Coin::operator == (Coin a) {
    return price == a.price;
}
int main () {
    int n;
    cin >> n;
    Coin a[100];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    string s;
    double b;
    for(int i = 0; i < m; i++) {
        getline(cin >> ws, s);
        cin >> b;
        for(int j = 0 ; j < n ; j++){
            if(s == a[j].getName()){
                  a[j] +=  b;
            }
        }
    }
    Coin max = a[0];
    for(int i = 1 ; i < n ; i++){
        if(max < a[i]) max = a[i];
    }
    cout << max;
}