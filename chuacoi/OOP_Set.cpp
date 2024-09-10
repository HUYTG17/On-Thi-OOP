#include <iostream>
#include <algorithm>
using namespace std;
class Set {
private:
    int n;
    int a[100];
public:
    void setn(int k) { n = k; }
    int getn() { return n; }
    int& operator [] (int i) {
        return a[i];
    }
    Set(int _n = 0, int _a[] = new int {100}) {
        n = _n;
        for(int i = 0; i < n; i++) {
            a[i] = _a[i];
        }
    }
    Set(const Set &s) {
        n = s.n;
        for(int i = 0; i < n; i++) {
            a[i] = s.a[i];
        }
    }
    friend istream& operator >> (istream& is, Set &s) {
        is >> s.n;
        for(int i = 0; i < s.n; i++) {
            is >> s[i];
        }
        return is;
    }
    friend ostream& operator << (ostream& os, Set s) {
        if(s.n == 0) os << 0;
        else {
            for(int i = 0; i < s.n; i++) {
            os << s[i] << " ";
        }
    }
        os << endl;
        return os;
    }
    void Giao (Set b) {
        Set s;
        s.n = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < b.n; j++) {
                if(a[i] == b.a[j]) {
                    s.a[s.n] = a[i];
                    s.n++;
                }
            }
        }
        if(s.n == 0) {
            cout << 0;
        }
        else {
        sort(s.a, s.a + s.n);
        for(int i = 0; i < s.n; i++) {
            cout << s.a[i] << " ";
            }
        }
    }
    void Hop (Set b) {
        Set s;
        s.n = 0;
        if(n == 0 && s.n == 0) {
            cout << 0;
        }
        else {
        for(int i = 0; i < n; i++) {
            s.a[s.n] = a[i];
            s.n++;
        }
        for(int i = 0; i < b.n; i++) {
             s.a[s.n] = b.a[i];
            s.n++;
        }
        sort(s.a, s.a + s.n);
        for(int i = 0; i < s.n; i++) {
            if(s.a[i] == s.a[i + 1] && i + 1 <= s.n - 1) {
                continue;
            }
            else {
                cout << s.a[i] << " ";
                }
            }
        }
    }
};
int main () {
    Set a, b;
    cin >> a >> b;
    cout << a << b;
    a.Giao(b);
    cout << endl;
    a.Hop(b);
}