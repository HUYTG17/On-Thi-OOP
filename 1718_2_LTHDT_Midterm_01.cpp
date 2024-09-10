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
    void setfirstName(string k) { firstName = k; }
    void setlastName(string k) { lastName = k; }
    void stsalary(double k) { salary = k; }
    int getid() { return id; }
    string getfirstName() { return firstName; }
    string getlastName() { return lastName; }
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
        double c = 12 * salary;
        return c;
    }
    double raiseSalary(double a) {
        a = a/100;
        double d = (1 + a) * salary;
        return d;
    }
    friend istream& operator >> (istream& is, Employee &e) {
        is >> e.id;
        cin.ignore();
        getline(is, e.firstName);
        getline(is, e.lastName);
        is >> e.salary;
        return is;
    }
    friend ostream& operator << (ostream& os, Employee e) {
        os << "Employee[id=" << e.id << ",name=" << e.firstName << " ";
        os << e.lastName << ",salary=$";
        os << fixed << setprecision(2) << e.salary << "]" << endl;
        return os;
    }
};
int main () {
    Employee a;
    cin >> a;
    cout << a;
    double b;
    cin >> b;
    double c = a.raiseSalary(b);
    cout << "$" << c << endl;
    c = c * 12;
    cout << "$" << c;
}