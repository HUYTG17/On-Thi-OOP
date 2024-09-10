#include <iostream>
#include <cmath>
using namespace std ;
class ARRINT{
private:
    int len ; 
    int *arr ;
public:
    ARRINT(int _len) {
        this->len = _len;
        this->arr = new int [_len];
    }
    ARRINT(const ARRINT &a) {
        len = a.len;
        arr = a.arr;
    }
    friend istream& operator >> (istream& is, ARRINT &a) {
        // is >> a.len;
        for(int i = a.len - 1; i >= 0; i--) {
            cin >> a.arr[i];
        }
        return is;
    }
    friend ostream& operator << (ostream& os, ARRINT a) {
        os << a.len << ": ";
        for(int i = 0; i < a.len; i++) {
            os << a.arr[i];
        }
        return os;
    }
    ARRINT operator + (ARRINT a) {
        ARRINT s = max(this->len, a.len);
        for(int i = 0; i < s.len; i++) {
            s.arr[i] = this->arr[i] + a.arr[i];
            if(s.arr[i] > 10) {
                s.arr[i] -= 10;
            }
        }
        return s;
    }
};
int main () {
    int a, b ;
    cin>> a >> b;
    ARRINT c(a), d(b);
    cin>> c >> d;
    ARRINT e = c + d ;
    cout<< e;
}