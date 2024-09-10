#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Vector {
private:
    int x, y, z;
public:
    void setX(int px);
    void setY(int py);
    void setZ(int py);
    int getX();
    int getY();
    int getZ() ;
    Vector();
    Vector(int px, int py, int pz);
    Vector(const Vector& pu);
    double F();
    Vector operator + (Vector pv);
    Vector operator - (Vector pv);
    friend istream& operator >> (istream& cin, Vector& pu);
    friend ostream& operator << (ostream& cout, Vector& pu);
};
void Vector::setX(int px) { x = px; }
void Vector::setY(int py) { y = py; }
void Vector::setZ(int pz) { z = pz; }
int Vector::getX() { return x; }
int Vector::getY() { return y; }
int Vector::getZ() { return z; }
Vector::Vector() { x = 0; y = 0; z = 0; }
Vector::Vector(int px, int py, int pz) { x = pz; y = py; z = pz; }
Vector::Vector(const Vector& pu) { x = pu.x; y = pu.y; z = pu.z; }
double Vector::F() { return (float)sqrt(x*x + y*y + z*z); }
Vector Vector::operator + (Vector pv) { 
    Vector c;
    c.x = x + pv.x;
    c.y = y + pv.y;
    c.z = z + pv.z;
    return c;
}
Vector Vector::operator - (Vector pv) { 
    Vector c;
    c.x = x - pv.x;
    c.y = y - pv.y;
    c.z = z - pv.z;
    return c; 
}
istream& operator >> (istream& cin, Vector& pu) {
    cin >> pu.x >> pu.y >> pu.z;
    return cin;
}
ostream& operator << (ostream& cout, Vector& pu) {
    cout << "(" << pu.x << "," << pu.y << "," << pu.z << ")";
    return cout;
}
int main () {
    Vector a, b;
    cin >> a >> b;
    cout << a << endl;
    cout << round(a.F()*100)/100 << endl;
    cout << b << endl;
    cout << round(b.F()*100)/100 << endl;
    Vector c = a + b;
    cout << c << endl;
    Vector d = a - b;
    cout << d;
}