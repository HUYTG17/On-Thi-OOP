#include <iostream>
#include <algorithm>
#include <vector>
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
    ~Person(){};
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
};
class Employer : public Person {
    int requirement;
    int maxSalary;
public:
    void setrequirement(int k) { requirement = k; }
    void setmaxSalary(int k) { maxSalary = k; }
    int getrequirement() { return requirement; }
    int getmaxSalary() { return maxSalary; }
    Employer(int _id = 0, string _name = "", int _year = 0, string _gender = "",
    int _requirement = 0, int _maxSalary = 0) : Person( _id, _name, _year, _gender) {
        requirement = _requirement;
        maxSalary = _maxSalary;
    }
    Employer(const Employer &e) : Person(e){
        requirement = e.requirement;
        maxSalary = e.maxSalary;
    }
    ~Employer(){};
    friend istream& operator >> (istream& is, Employer &e) {
        int id, year, re, maxsala;
        string name, gender;
        is >> id;
        is.ignore();
        getline(is, name);
        is >> year;
        is.ignore();
        getline(is, gender);
        is >> re >> maxsala;
        e = Employer(id, name, year, gender, re, maxsala);
        return is;
    }
    friend ostream& operator << (ostream& os, Employer e) {
        os << e.getId() << "-" << e.getName() << "-" << e.getYearOld() << "-" << e.getGender();
        os << "-" << e.requirement << "Year-" << e.maxSalary << "USD\n";
        return os;
    }
};
class Employee : public Person {
    int exp;
    int deal;
public:
    void setexp(int k) { exp = k; }
    void setdeal(int k) { deal = k; }
    int getexp() { return exp; }
    int getdeal() { return deal; }
    Employee(int _id = 0, string _name = "", int _year = 0, string _gender = "",
    int _exp = 0, int _deal = 0) : Person( _id, _name, _year, _gender) {
        exp = _exp;
        deal = _deal;
    }
    Employee(const Employee &e) : Person(e){
        exp = e.exp;
        deal = e.deal;
    }
    ~Employee(){};
    friend istream& operator >> (istream& is, Employee &e) {
        int id, year, exp, deal;
        string name, gender;
        is >> id;
        is.ignore();
        getline(is, name);
        is >> year;
        is.ignore();
        getline(is, gender);
        is >> exp >> deal;
        e = Employee(id, name, year, gender, exp, deal);
        return is;
    }
    friend ostream& operator << (ostream& os, Employee e) {
        os << e.getId() << "-" << e.getName() << "-" << e.getYearOld() << "-" << e.getGender();
        os << "-" << e.exp << "Year-" << e.deal << "USD\n";
        return os;
    }
};
int main () {
    int n;
    cin >> n;
    vector<Employer> v;
    vector<Employee> v1;
    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        if(m == 0) {
            Employer a;
            cin >> a;
            cout << a;
            v.push_back(a);
        } else {
            Employee a;
            cin >> a;
            cout << a;
            v1.push_back(a);
        }
    }
    if(v.size() == 0) {
        cout << -1;
    } else {
        double max = v[0].getmaxSalary();
        for(int i = 0; i < v.size(); i++) {
            if(max < v[i].getmaxSalary()) max = v[i].getmaxSalary();
        }
        for(int i = 0; i < v.size(); i++) {
            if(max == v[i].getmaxSalary()) {
                cout << v[i].getId() << " ";
            }
        }
    }
    cout << endl;
    if(v1.size() == 0) {
        cout << -1;
    } else {
        double min = v1[0].getdeal();
        for(int i = 0; i < v1.size(); i++) {
            if(min > v1[i].getdeal()) min = v1[i].getdeal();
        }
        for(int i = 0; i < v1.size(); i++) {
            if(min == v1[i].getdeal()) {
                cout << v1[i].getId() << " ";
            }
        }
    }
    return 0;
}

/*or đổi tên lại thôi 
    int x;
    cin >> x;
    int n = 0;
    int N = 0;
    Television a[100];
    Refrigerator b[100];
    for(int i = 0; i < x; i++) {
        int m;
        cin >> m;
        cin.ignore();
        if(m == 0) {
            cin >> a[n++];
            cout << a[n - 1];
        } else {
            cin >> b[N++];
            cout << b[N - 1];
        }
    }
    if(n == 0) {
        cout << -1;
    } else {
        double min = a[0].getTotalCost();
        for(int i = 0; i < n; i++) {
            if(min > a[i].getTotalCost()) min = a[i].getTotalCost();
        }
        for(int i = 0; i < n; i++) {
            if(min == a[i].getTotalCost()) {
                cout << a[i].getmodel() << " ";
            }
        }
    }
    cout << endl;
    if(N == 0) {
        cout << -1;
    } else {
        double max = b[0].getTotalCost();
        for(int i = 0; i < N; i++) {
            if(max < b[i].getTotalCost()) max = b[i].getTotalCost();
        }
        for(int i = 0; i < N; i++) {
            if(max == b[i].getTotalCost()) {
                cout << b[i].getmodel() << " ";
            }
        }
    }
*/