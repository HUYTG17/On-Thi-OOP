#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class ToaDo {
private:
    double x, y;
public:
    void setx(double k) { x = k; }
    void sety(double k) { y = k; }
    int getx() { return x; }
    int gety() { return y; }
    ToaDo(int _x = 0, int _y = 0) {
        x = _x;
        y = _y;
    }
    ToaDo(const ToaDo &t) {
        x = t.x;
        y = t.y;
    }
    ~ToaDo(){};
    friend istream& operator >> (istream& is, ToaDo &t) {
        is >> t.x >> t.y;
        return is;
    }
    friend ostream& operator << (ostream& os, ToaDo t) {
        os << "(" << t.x << "," << t.y << ")";
        return os;
    }
    ToaDo operator + (ToaDo a) {
        ToaDo c;
        c.x = x + a.x;
        c.y = y + a.y;
        return c;
    }
    float kc(ToaDo a) {
        float c = sqrt(pow(a.x - x, 2) + pow(a.y -y, 2));
        return c;
    }
    bool thuocdt(double a, double b) {
        return (a*x + b*y == 0);
    }
};
int main () {
    ToaDo a, b;
    cin >> a >> b;
    cout << a << endl << b << endl;
    cout << a + b << endl;
    float d = a.kc(b);
    cout << fixed << setprecision(1) << d << endl;
    float e, f;
    cin >> e >> f;
    a.thuocdt(e, f) ? cout << "YES" : cout << "NO";
}