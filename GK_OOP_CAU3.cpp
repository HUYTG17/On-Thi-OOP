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
    double getStringLength() {
        return upper.size();
    }
    string stringUpperCase() {
        string tmp = upper;
        for(char &d : tmp) {
            d = toupper(d);
        }
        return tmp;
    }
};
class Dao : public Chuoi {
public:
    Dao(string _upper = "") : Chuoi(_upper) {}
    Dao(const Dao &d) : Chuoi(d){}
    string getStringInverse() {
        string s = getupper();
        reverse(s.begin(), s.end());
        return s;
    }
    ~Dao(){};
    friend istream& operator >> (istream& is, Dao &d) {
        string d1;
        getline(is, d1);
        d = Dao(d1);
        return is;
    }
    friend ostream& operator << (ostream& os, Dao d) {
        os << d.getupper();
        return os;
    }
};
class KC : public Dao {
public:
    KC(string _upper = "") : Dao(_upper) {}
    KC(const KC &k) : Dao(k){}
    ~KC(){};
    friend double operator / (KC a, KC b) {
        return a.getStringLength() / b.getStringLength();
    }
    string getStringInverse() {
        string s = getupper();
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == ' ' && s[i+1] == ' ') {
                s.erase(i,1);
                i--;
            }
        }
        setupper(s);
        return s;
    }
    string connectString(string s) {
        string s1 = getupper();
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == ' ' && s[i+1] == ' ') {
                s.erase(i, 1);
                i--;
            }
        }
        for(int i = 0; i < s1.size() - 1; i++) {
            if(s[i] == ' ' && s[i+1] == ' ') {
                s1.erase(i, 1);
                i--;
            }
        }
        return s1 + " " + s;
    }
    friend istream& operator >> (istream& is, KC &a) {
        string s;
        getline(cin, s);
        a = KC(s);
        return is;
    }
    friend ostream& operator << (ostream& os, KC a) {
        os << a.getupper();
        return os;
    }
};
int main () {
    KC a, b;
    cin >> a >> b;
    cout << a.connectString(b.getupper()) << endl;
    cout << a.getStringInverse() << endl << b.getStringInverse() << endl;
    cout << round((a / b)*100)/100;
    return 0;
}