#include <iostream>
using namespace std;
class ARRINT {
private:
    int len;
    int *arr;
public:
    void setlen(int k) { len = k; }
    int getlen() { return len; }
    int& operator [] (int i) {
        return arr[i];
    }
    ARRINT(int _len = 0) {
        len = _len;
        arr = new int [_len];
    }
    ARRINT(const ARRINT &a) {
        len = a.len;
        arr = a.arr;
    }
    ARRINT operator - (ARRINT a) {
        ARRINT s = max(len, a.len);
        for(int i = 0; i < s.len; i++) {
            s[i] = arr[i] - a[i];
            if(s[i] < 0) {
                s[i] = abs(s[i]);
            }
        }
        return s;
    }
    friend istream& operator >> (istream& is, ARRINT &a) {
        for(int i = a.len - 1; i >= 0; i--) {
            is >> a[i];
        }
        return is;
    }
    friend ostream& operator << (ostream& os, ARRINT a) {
        os << a.len << ": ";
        for(int i = 0; i < a.len; i++) {
            os << a[i];
        }
        return os;
    }
};
int main () {
    int x, y;
    cin >> x >> y;
    ARRINT a(x), b(y);
    cin >> a >> b;
    cout << a - b;
}