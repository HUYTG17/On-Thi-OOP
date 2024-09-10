#include <iostream>
#include <iomanip>
using namespace std;
class Virus {
    string name;
    float resistance;
public:
    void setname(string k) { name = k; }
    void setresistance(float k) { resistance = k; }
    string getname() { return name; }
    float getresistance() { return resistance; }
    Virus(string _name = "NoName", float _resistance = 0.1) {
        name = _name;
        resistance = _resistance;
    }
    Virus(const Virus &vr) {
        name = vr.name;
        resistance = vr.resistance;
    }
    ~Virus(){};
    void printVirus() {
        cout << name << "-" << fixed << setprecision(1) << resistance;
    }
    bool survive(float immunity) {
        if(immunity > resistance) {
            return false;
        }
        return true;
    }
};
int main () {
    int n;
    cin >> n;
    int c;
    string name;
    float b;
    Virus a[n];
    for(int i = 0; i < n; i++) {
        cin >> c;
        if(c == 1) {
            cin.ignore();
            getline(cin, name);
            a[i].setname(name);
        } else if(c == 2) {
            cin >> b;
            a[i].setresistance(b);
        } else {
            cin.ignore();
            getline(cin, name);
            cin >> b;
            a[i] = Virus(name, b);
        }
    }
    float immunity;
    cin >> immunity;
    for(int i = 0; i < n; i++) {
        a[i].printVirus();
        cout << endl;
    }
    for(int i = 0; i < n; i++) {
        if(a[i].survive(immunity)) {
            cout << "True\n";
        } else {
            cout << "False\n";
        }
    }
    float max = a[0].getresistance();
    for(int i = 0; i < n; i++) {
        if(max < a[i].getresistance()) max = a[i].getresistance();
    }
    for(int i = 0; i < n; i++) {
        if(max == a[i].getresistance()) cout << a[i].getname() << endl;
    }
}