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
class Book : public Rating {
    string name;
    int year;
public:
    void setname(string k) { name = k; }
    string getname() { return name; }
    void setyear(int k) { year = k; }
    int getyear() { return year; }
    Book(int _like = 0, int _dislike = 0, int _n = 0, int _comment[] = new int {},
    string _name = "", int _year = 0) : Rating(_like, _dislike, _n, _comment) {
        name = _name;
        year = _year;
    }
    Book(const Book &ra) : Rating(ra) {
        name = ra.name;
        year = ra.year;
    }
    ~Book(){};
    bool operator > (Book a) {
        if(getGeneral() > a.getGeneral()) {
            return true;
        } else if(getGeneral() == a.getGeneral()) {
            if(year > a.year) {
                return true;
            } else if(year == a.year) {
                if(name < a.name) {
                    return true;
                }
            }
        }
        return false;
    }
    bool operator < (Book a) {
        if(getGeneral() < a.getGeneral()) {
            return true;
        } else if(getGeneral() == a.getGeneral()) {
            if(year < a.year) {
                return true;
            } else if(year == a.year) {
                if(name > a.name) {
                    return true;
                }
            }
        }
        return false;
    }
    friend istream& operator >> (istream& is, Book &b) {
        int like, dislike, n, comment[100], year;
        string name;
        getline(is, name);
        is >> year;
        is >> like >> dislike >> n;
        for(int i = 0; i < n; i++) {
            is >> comment[i];
        }
        b = Book(like, dislike, n, comment, name, year);
        return is;
    }
    friend ostream& operator << (ostream& os, Book b) {
        os << b.name << endl;
        return os;
    }
    bool operator == (Book a) {
        return getGeneral() == a.getGeneral() && name == a.name && year == a.year; 
    }
};
class Film : public Rating {
    string name1;
    int year1;
public:
    void setname1(string k) { name1 = k; }
    string getname1() { return name1; }
    void setyear1(int k) { year1 = k; }
    int getyear1() { return year1; }
    Film(int _like = 0, int _dislike = 0, int _n = 0, int _comment[] = new int {},
    string _name1 = "", int _year1 = 0) : Rating(_like, _dislike, _n, _comment) {
        name1 = _name1;
        year1 = _year1;
    }
    Film(const Film &ra) : Rating(ra) {
        name1 = ra.name1;
        year1 = ra.year1;
    }
    ~Film(){};
    bool operator > (Film a) {
        if(getGeneral() > a.getGeneral()) {
            return true;
        } else if(getGeneral() == a.getGeneral()) {
            if(year1 > a.year1) {
                return true;
            } else if(year1 == a.year1) {
                if(name1 < a.name1) {
                    return true;
                }
            }
        }
        return false;
    }
    bool operator < (Film a) {
        if(getGeneral() < a.getGeneral()) {
            return true;
        } else if(getGeneral() == a.getGeneral()) {
            if(year1 < a.year1) {
                return true;
            } else if(year1 == a.year1) {
                if(name1 > a.name1) {
                    return true;
                }
            }
        }
        return false;
    }
    friend istream& operator >> (istream& is, Film &b) {
        int like, dislike, n, comment[100], year1;
        string name1;
        getline(is, name1);
        is >> year1;
        is >> like >> dislike >> n;
        for(int i = 0; i < n; i++) {
            is >> comment[i];
        }
        b = Film(like, dislike, n, comment, name1, year1);
        return is;
    }
    friend ostream& operator << (ostream& os, Film b) {
        os << b.name1 << endl;
        return os;
    }
    bool operator == (Film a) {
        return getGeneral() == a.getGeneral() && name1 == a.name1 && year1 == a.year1; 
    }
};
int main () {
    int n; 
    cin >> n;
    int type;
    Book a[100];
    Film b[100];
    Book max[100];
    Film max1[100];
    int m = 0, k = 0;
    for(int i = 0; i < n; i++) {
        cin >> type;
        cin.ignore();
        if(type == 0) {
            cin >> a[m];
            m++;
        } else {
            cin >> b[k];
            k++;
        }
    }
    int y;
    cin >> y;
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            if(a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
    for(int i = 0; i < k; i++) {
        for(int j = i + 1; j < k; j++) {
            if(b[i] < b[j]) {
                swap(b[i], b[j]);
            }
        }
    }
    for(int i = 0; i < m; i++) {
        cout << a[i];
    }
    for(int i = 0; i < k; i++) {
        cout << b[i];
    }
    double maxBook = -0.1, maxFilm = -0.1;
    int size = 0, size1 = 0;
    for(int i = 0; i < m; i++) {
        if(a[i].getyear() == y) {
            if(maxBook < a[i].getGeneral()) {
                maxBook = a[i].getGeneral();
                max[size] = a[i];
                size++;
            } else if(a[i].getGeneral() == maxBook) {
                max[size] = a[i];
                size++;
            }
        }
    }
    for(int i = 0; i < k; i++) {
        if(b[i].getyear1() == y) {
            if(maxFilm < b[i].getGeneral()) {
                maxFilm = b[i].getGeneral();
                max1[size1] = b[i];
                size1++;
            } else if(b[i].getGeneral() == maxFilm) {
                max1[size1] = b[i];
                size1++;
            }
        }
    }
    if(size == 0) {
        cout << -1 << endl;
    } else {
        for(int i = 0; i < size; i++) {
         cout << max[i];
        }
    }
    if(size1 == 0) {
        cout << -1 << endl;
    } else {
        for(int i = 0; i < size1; i++) {
         cout << max1[i];
        }
    }
    return 0;
}