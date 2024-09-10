#include <iostream>
using namespace std;
class Student {
    int id;
    string firstName;
    string lastName;
    float dtb;
public:
    Student(int _id = 0, string _firstName = "a", string _lastName = "b", float _dtb = 0) {
        id = _id;
        firstName = _firstName;
        lastName =  _lastName;
        dtb = _dtb;
    }
    Student(const Student &s) {
        id = s.id;
        firstName = s.firstName;
        lastName = s.lastName;
        dtb = s.dtb;
    }
    friend istream& operator >> (istream& is, Student &s) {
        is >> s.id;
        cin.ignore();
        getline(is, s.firstName);
        getline(is, s.lastName);
        is >> s.dtb;
        return is;
    }
    friend ostream& operator << (ostream& os, Student s) {
        os << "Student{id=" << s.id << ",name=" << s.firstName << " " << s.lastName << ",score:" << s.dtb << ",";
        s.getRank();
        return os;
    }        
    void getRank() {
        if(dtb >= 8.5) {
            cout <<"ranking:A} PASSED";
        }
        else if(dtb >= 7.8 && dtb <= 8.4) {
            cout <<"ranking:B+} PASSED";
        }
        else if(dtb >= 7.0 && dtb <= 7.7) {
            cout <<"ranking:B} PASSED";
        }
        else if(dtb >= 6.3 && dtb <= 6.9) {
            cout <<"ranking:C+} PASSED";
        }
        else if(dtb >= 5.5 && dtb <= 6.2) {
            cout <<"ranking:C} PASSED";
        }
        else {
            cout <<"ranking:D} FAILED";
        } 
    }
};
int main () {
    Student a;
    cin >> a;
    cout << a;
    return 0;
}