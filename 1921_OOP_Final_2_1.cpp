#include <iostream>
using namespace std;
class Person {
        int id;
        string name;
        int year;
        string gender;
    public:
        void setId(int k);
        void setName(string k);
        void setYear(int k);
        void setGender(string k);
        int getId();
        string getName();
        int getYear();
        string getGender();
        Person(int _id = 0, string _name = " ", int _year = 1900, string _gender = " ");
        int getYearOld();
        friend istream& operator >> (istream& is, Person &p);
        friend ostream& operator << (ostream& os, Person p);
};
void Person::setId(int k) { id = k; }
void Person::setName(string k) { name = k; }
void Person::setYear(int k) { year = k; }
void Person::setGender(string k) { gender = k; }
int Person::getId() { return id; }
string Person::getName() { return name; }
int Person::getYear() { return year; }
string Person::getGender() { return gender; }
Person::Person(int _id, string _name, int _year, string _gender) {
    id = _id;
    name = _name;
    year = _year;
    gender = _gender;
}
int Person::getYearOld() {
    float YearOld = 0;
    YearOld = 2020 - year;
    return YearOld;
}
istream& operator >> (istream& is, Person &p) {
    is >> p.id;
    is.ignore();
    getline(is, p.name);
    is >> p.year;
    is.ignore();
    getline(is, p.gender);
    return is;
}
ostream& operator << (ostream& os, Person p) {
    os << p.id << "-" << p.name << "-" << p.getYearOld() << "-" << p.gender;
    return os;
}
class Mps {
        int n;
        Person ds[100];
    public:
        void setN(int k);
        int getN();
        Person& operator [] (int i) {
            return ds[i];
        }
        Mps(int _n = 1, Person _ds[] = new Person{});
        Mps(const Mps &p);
        friend istream& operator >> (istream& is, Mps &p);
        friend ostream& operator << (ostream& os, Mps p);
        // int getYearOld();
};
void Mps::setN(int k) { n = k; }
int Mps::getN() { return n; }
Mps::Mps(int _n, Person _ds[]) {
    n = _n;
    for(int i = 0; i < n; i++) {
        ds[i] = _ds[i];
    }
}
Mps::Mps(const Mps &p) {
    n = p.n;
    for(int i = 0; i < n; i++) {
        ds[i] = p.ds[i];
    }
}
// int Mps::getYearOld() { return p.getYearOld; }
istream& operator >> (istream& is, Mps &p) {
    is >> p.n;
    for(int i = 0; i < p.n; i++) {
        is >> p.ds[i];
    }
    return is;
}
ostream& operator << (ostream& os, Mps p) {
    for(int i = 0; i < p.n; i++) {
        os << p.ds[i] << endl;
    }
    return os;
}
int main () {
    Mps a;
    cin >> a;
    cout << a;
}