#include <iostream>
using namespace std;
class Chuoi {
private:
    string upper;
public:
    Chuoi() {
        upper = "";
    }
    Chuoi( string _upper) {
        upper = _upper;
    }
    Chuoi(const Chuoi &c) {
        upper = c.upper;
    }
    ~Chuoi(){};
    friend istream& operator >> (istream& is, Chuoi &c) {
        getline(is, c.upper);
        return is;
    }
    friend ostream& operator << (ostream& os, Chuoi c) {
        os << c.upper << endl;
        return os;
    }
    int getStringLength() {
        return upper.size();
    }
    string stringUpperCase() {
        string tmp = upper;
        for(char &d : tmp) {
            d = toupper(d);
        }
        return tmp;
    }
    bool operator > (Chuoi c) {
        return getStringLength() > c.getStringLength();
    }
};
int main () {
    Chuoi a, b;
    cin >> a >> b;
    cout << a << b;
    if(a > b) {
        cout << "YES" << endl;
        cout << a.stringUpperCase() << endl;
    }
    else {
        cout << "NO" << endl;
        cout << b.stringUpperCase();
    }
}