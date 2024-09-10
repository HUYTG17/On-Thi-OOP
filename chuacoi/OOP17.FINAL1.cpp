#include <iostream>
using namespace std;
class Set {
    int n;
    int  a[100];
public:
    void setn(int k) { n = k; }
    int getn() { return n; }
    int& operator [] (int i) {
        return a[i];
    }
    Set() {
        n = 0;
    }
    Set(int _n) {
        if(_n == 0) {
            n = 0;
        } else {
            n = _n;
            for(int i = 0; i <= n; i++) {
                a[i] = i + 1;
            }
        }
    }
    Set(int b, int c) {
        if(b > c) {
            n = 0;
        } else {
            n = c-b+1;
            for(int i = 0; i < n; i++) {
                a[i] = b + i;
            }
        }
    }
    Set(const Set &s) {
        n = s.n;
        for(int i = 0; i < s.n; i++) {
            a[i] = s.a[i];
        }
    }
    ~Set(){};
    bool Contain(int x) {
        for(int i = 0; i < n; i++) {
            if(a[i] == x) {
                return true;
            }
            return false;
        }
    }
    bool Add(int x) {
        for(int i = 0; i < n; i++) {
            if(a[i] == x) {
                return false;
            }
        }
        n++;
        a[n-1] = x;
        return true;
    }
    bool Remove(int x) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == x) {
                cnt++;
            }
        }
        if(cnt < 1) {
            return false;
        } else {
            for(int i = 0; i < n; i++) {
                if(a[i] == x) {
                    for(int j = i; j < n; j++) {
                        a[j] = a[j+1];
                    }
                    break;
                }
            }
            n--;
            return true;
        }
    }
    Set operator & (Set b) {
        Set kq;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < b.n; j++) {
                if(a[i] == b.a[j]) {
                    kq.Add(a[i]);
                    break;
                }
            }
        }
        return kq;
    }
    Set operator | (Set b) {
        Set kq;
        if(n > b.n) {
            for(int i= 0; i < n; i++) {
                kq.Add(a[i]);
            }
            for(int i = 0; i < b.n; i++) {
                if(kq.Contain(b[i]) == false) {
                    kq.Add(b[i]);
                }
            }
        } else if(b.n > n) {
            for(int i = 0; i < b.n; i++) {
                kq.Add(b[i]);
            }
            for(int i = 0; i < n; i++) {
                if(kq.Contain(a[i]) == false) {
                    kq.Add(a[i]);
                }
            }
        }
        return kq;
    }
    friend ostream& operator << (ostream& os, Set &s) {
        if(s.n == 0) {
            os << "NULL";
        } else {
            for(int i = 0; i < s.n - 1; i++) {
                for(int j = i + 1; j < s.n; j++) {
                    if(s[i] > s[j]) {
                        swap(s[i], s[j]);
                    }
                }
            }
            for(int i = 0; i < s.n; i++) {
                os << s[i] << " ";
            }
        }
        os << endl;
        return os;
    }
};
int main () {
    int n, a, b;
    cin >> n >> a >> b;
    Set c(n); Set d(a, b);
    Set e = c & d; Set f = c | d;
    cout << f << e;
}