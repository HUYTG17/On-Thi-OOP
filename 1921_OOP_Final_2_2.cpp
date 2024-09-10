#include <iostream>
#include <algorithm>
using namespace std;
class Person {
        int id;
        string name;
        int year;
        string gender;
    public:
    void setId(int k) { id = k; }
    void setName(string k) { name = k; }
    void setYear(int k) { year = k; }
    void setGender(string k) { gender = k; }
    int getId() { return id; }
    string getName() { return name; }
    int getYear() { return year; }
    string getGender() { return gender; }
    Person(int _id = 0, string _name = "", int _year = 0, string _gender = "") {
        id = _id;
        name = _name;
        year = _year;
        gender = _gender;
    }
    int getYearOld() {
        float YearOld = 0;
        YearOld = 2020 - year;
        return YearOld;
    }
    friend istream& operator >> (istream& is, Person &p) {
        is >> p.id;
        is.ignore();
        getline(is , p.name);
        is >> p.year;
        is.ignore();
        getline(is, p.gender);
        return is;
    }
    friend ostream& operator << (ostream& os, Person p) {
        os << p.id << "-" << p.name << "-" << p.getYearOld() << "-" << p.gender << endl;
        return os;
    }
    bool operator > (Person a) {
        if(getYearOld() == a.getYearOld()) {
            return id > a.id;
        } 
        return getYearOld() > a.getYearOld();
    }
    bool operator < (Person a) {
        if(getYearOld() == a.getYearOld()) {
            return id < a.id;
        } 
        return getYearOld() < a.getYearOld();
    }
};

int main () {
    int n;
    cin >> n;
    Person a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int flag;
    cin >> flag;
    if(flag == 0) {
        sort(a, a + n);
    } 
    else if(flag == 1) {
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(a[i] < a[j]) {
                    swap(a[i], a[j]);
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << a[i];
    }
}