#include <iostream>
#include <iomanip>
using namespace std;
class Employee {
private:
    int id;
    string firstName;
    string lastName;
    double salary;
public:
    void setid(int k) { id = k; }
    int getid() { return id; }
    void setfirstName(string k) { firstName = k; }
    string getfirstName() { return firstName; }
    void setlastName(string k) { lastName = k; }
    string getlastName() { return lastName; }
    void setsalary(double k) { salary = k; }
    double getsalary() { return salary; }
    Employee(int _id = 0, string _firstName = "", string _lastName = "", double _salary = 0) {
        id = _id;
        firstName = _firstName;
        lastName = _lastName;
        salary = _salary;
    }
    Employee(const Employee &e) {
        id = e.id;
        firstName = e.firstName;
        lastName = e.lastName;
        salary = e.salary;
    }
    double getAnnualSalary() {
        return 12 * salary;
    }
    double raiseSalry(double a) {
        return (1 + a) * salary;
    }
    friend istream& operator >> (istream& is, Employee &e) {
        is >> e.id;
        is.ignore();
        getline(is, e.firstName);
        getline(is, e.lastName);
        is >> e.salary;
        return is;
    }
    friend ostream& operator << (ostream& os, Employee e) {
        os << "Employee[id=" << e.id << ",name=" << e.firstName << " ";
        os << e.lastName << ",salary=$" << fixed << setprecision(2) << e.salary << "]";
        os << endl;
        return os;
    }
    Employee operator ++ () {
        salary *= 1.1;
        return salary;
    }
    Employee operator -- () {
        salary *= 0.9;
        return salary;
    }
    Employee operator + (double a) {
        return salary + a;
    }
    Employee operator - (double a) {
        return salary - a;
    }
    bool operator > (Employee a) {
        return getAnnualSalary() > a.getAnnualSalary();
    }
    bool operator < (Employee a) {
        return getAnnualSalary() < a.getAnnualSalary();
    }
    bool operator == (Employee a) {
        return getAnnualSalary() == a.getAnnualSalary();
    }
    bool operator != (Employee a) {
        return getAnnualSalary() != a.getAnnualSalary();
    }
};
int main () {
    Employee a, b;
    cin >> a >> b;
    cout << a << b;
    if(a == b) cout << "BANG NHAU" << endl;
    else if(a > b) cout << "LON HON" << endl;
    else cout << "NHO HON" << endl;
    double x, y;
    cin >> x >> y;
    double c = a.getsalary() - x;
    cout << "$" << c << endl;
    --b;
    double d = b.getsalary() + y;
    cout << "$" << d;
}