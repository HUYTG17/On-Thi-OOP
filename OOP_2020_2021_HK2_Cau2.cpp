#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class Rating {
    int like;
    int dislike;
    int n;
    int comment[100];
public:
    void setlike(int k) { like = k; }
    void setdislike(int k) { dislike = k; }
    void setn(int k) { k = n; }
    int getlike() { return like; }
    int getdislike() { return dislike; }
    int getn() { return n; }
    int& operator [] (int i) {
        return comment[i];
    }
    Rating(int _like = 0, int _dislike = 0, int _n = 0, int _comment[] = new int {}) {
        like = _like;
        dislike = _dislike;
        n = _n;
        for(int i = 0; i < n; i++) {
            comment[i] = _comment[i]; 
        }
    }
    Rating(const Rating &ra) {
        like = ra.like;
        dislike = ra.dislike;
        n = ra.n;
        for(int i = 0; i < n; i++) {
            comment[i] = ra.comment[i]; 
        }
    }
    ~Rating(){};
    double getLikeRating() {
        return (static_cast<double>(like) / (like + dislike)) * 100.0;
    }
    double getDislikeRating() {
        return 100 - getLikeRating();
    }
    double getpositive() {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(comment[i] > 0) {
                cnt++;
            }
        }
        return (static_cast<double>(cnt)/(n)) * 100;
    }
    double getnegatice() {
        return 100 - getpositive();
    }
    double getGeneral() {
        return (static_cast<double>(getLikeRating() + getpositive()) / 200) * 100;
    }
    friend istream& operator >> (istream& is, Rating &ra) {
        is >> ra.like >> ra.dislike;
        is >> ra.n;
        for(int i = 0; i < ra.n; i++) {
            is >> ra[i];
        }
        return is;
    }
    friend ostream& operator << (ostream& os, Rating ra) {
        os << fixed << setprecision(2) << ra.getLikeRating() << "%-" << ra.getDislikeRating();
        os << "%-" << ra.getpositive() << "%-" << ra.getnegatice() << "%-";
        os <<  ra.getGeneral() << "%\n";
        return os;
    }
    int number() {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(comment[i] > 0) {
                cnt++;
            }
        }
        return cnt;
    }
    int tong() {
        int s = 0;
        for(int i = 0; i < n; i++) {
            if(comment[i] > 0) {
                s = s + comment[i];
            }
        }
        return s;
    }
    bool operator > (Rating a) {
        if(getGeneral() > a.getGeneral()) { 
            return true;
        } else if(getGeneral() == a.getGeneral()) {
            if(number() > a.number()) {
                return true;
            } else if(number() == a.number()) {
                if(tong() > a.tong()) {
                return true;
                }
            }
        }
        return false;
    }
    bool operator < (Rating a) {
        if(getGeneral() < a.getGeneral()) { 
            return true;
        } else if(getGeneral() == a.getGeneral()) {
            if(number() < a.number()) {
                return true;
            } else if(number() == a.number()) {
                if(tong() < a.tong()) {
                return true;
                }
            }
        }
        return false;
    }
    bool operator == (Rating a) {
        return getGeneral() == a.getGeneral() && number() == a.number() && tong() == a.tong();
    }
    Rating operator + (int x) {
        if(x < 0) dislike += abs(x);
        else like += x;
    }
};
int main () {
    Rating a[100];
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int k; 
    cin >> k;
    for(int i = 1; i <= k; i++) {
        int pos, val;
        cin >> pos >> val;
        a[pos] + val;
    }
    int x, y;
    cin >> x >> y;
    if(a[x] > a[y]) {
        cout << ">\n";
    } else if(a[x] < a[y]) {
        cout << "<\n";
    } else {
        cout << "=\n";
    }
    Rating max = a[1];
    for(int i = 1; i <= n; i++) {
        if(max < a[i]) max = a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(max == a[i]) cout << i << " ";
    }
}