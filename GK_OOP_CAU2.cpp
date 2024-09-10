#include <iostream>
#include <algorithm>
using namespace std;
class Chuoi {
private:
    string upper;
public:
    void setupper(string k) { upper = k; }
    string getupper() { return upper; }
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
    bool operator < (Chuoi c) {
        return getStringLength() < c.getStringLength();
    }
    int operator + (Chuoi a) {
        int s = getStringLength() + a.getStringLength();
        return s;
    }
    int operator - (Chuoi a) {
        int s = getStringLength() - a.getStringLength();
        return s;
    }
};
class Dao : public Chuoi {
public:
    Dao(string _upper = "") : Chuoi(_upper) {}
    string getStringInverse() {
        string s = getupper();
        reverse(s.begin(), s.end());
        return s;
    }
};
int main () {
    Dao a, b;
    cin >> a >> b;
    char c;
    cin >> c;
    cout << a.getStringInverse() << endl << b.getStringInverse() << endl;
    if(a > b) {
        cout << "LONHON\n";
    } else if(a < b) {
        cout << "BEHON\n";
    } else {
        cout << "BANG\n";
    }
    if(c == '+') {
        cout << a + b;
    } else {
        int s = a - b;
        cout << abs(s);
    }
}