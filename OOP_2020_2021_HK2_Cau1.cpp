#include <iostream>
#include <iomanip>
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
};
int main () {
    int n;
    cin >> n;
    Rating a[100];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cout << a[i];
    }
}