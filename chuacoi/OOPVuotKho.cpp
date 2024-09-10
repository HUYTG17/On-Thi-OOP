#include <iostream>
#include <iomanip>
using namespace std;
class Resident {
private:
    string name; //Tên chủ (hoặc người thuê) căn hộ
    int age; //Tuổi chủ hộ
    int apartmentNumber; //Mã số căn hộ
    string phoneNumber; //Số điện thoại chủ hộ
    string email; //Email
public:
    void setname(string k) { name = k; }
    void setage(int k) { age = k; }
    void setapartmentNumber(int k) { apartmentNumber = k; }
    void setphoneNumber(string k) { phoneNumber = k; }
    void setemail(string k) { email = k; }
    string getname() { return name; }
    int getage() { return age; }
    int getapartmentNumber() { return apartmentNumber; }
    string getphoneNumber() { return phoneNumber; }
    string getemail() { return email; }
    Resident(string _name = "", int _age = 0, int _apartmentNumber = 0, 
    string _phoneNumber = "", string _email = "") {
        name = _name;
        age = _age;
        apartmentNumber = _apartmentNumber;
        phoneNumber = _phoneNumber;
        email = _email;
    }
    Resident(const Resident &r) {
        name = r.name;
        age = r.age;
        apartmentNumber = r.apartmentNumber;
        phoneNumber = r.phoneNumber;
        email = r.email;
    }
    virtual~Resident(){};
    friend istream& operator >> (istream& is, Resident &r) {
        getline(is, r.name);
        is >> r.age >> r.apartmentNumber;
        is >> r.phoneNumber;
        is >> r.email;
        return is;
    }
    friend ostream& operator << (ostream& os, Resident r) {
        os << "Ten      : " << r.name << endl;
        os << "Tuoi     : " << r.age << endl;
        os << "So nha   : " << r.apartmentNumber << endl;
        os << "SDT      : " << r.phoneNumber << endl;
        os << "Email    : " << r.email << endl;
        return os;
    }
};
class Owner : public Resident{
private:
    int purchaseYear;
public:
    void setpurchaseYear(int k) { purchaseYear = k; }
    int getpurchaseYear() { return purchaseYear; }
    Owner(string _name = "", int _age = 0, int _apartmentNumber = 0, 
    string _phoneNumber = "", string _email = "", 
    int _purchaseYear = 0) : Resident( _name, _age, _apartmentNumber, _phoneNumber, _email) {
        purchaseYear = _purchaseYear;
    }
    Owner(const Owner &r) : Resident(r){
        purchaseYear = r.purchaseYear;
    }
    ~Owner(){};
    friend istream& operator >> (istream& is, Owner &o) {
        Resident &r = o;
        is >> r;
        is >> o.purchaseYear;
        is.ignore();
        return is;
    }
    friend ostream& operator << (ostream& os, Owner o) {
        Resident r = o;
        os << r;
        os << "Nam mua  : " << o.purchaseYear << endl;
        return os;
    }
    bool operator <= (int year) {
        return purchaseYear <= year;
    } //So sánh năm mua căn hộ với year
};
class Renter : public Resident {
private:
    double price; //Là giá thuê căn hộ hàng tháng, có đơn vị là triệu
public:
    void setprice(double k) { price = k; }
    double getprice() { return price; }
    Renter(string _name = "", int _age = 0, int _apartmentNumber = 0, 
    string _phoneNumber = "", string _email = "", 
    int _price = 0) : Resident( _name, _age, _apartmentNumber, _phoneNumber, _email) {
        price = _price;
    }
    Renter(const Renter &r) : Resident(r){
        price = r.price;
    }
    ~Renter(){};
    friend istream& operator >> (istream& is, Renter &re) {
        Resident &r = re;
        is >> r;
        is >> re.price;
        is.ignore();
        return is;
    }
    friend ostream& operator << (ostream& os, Renter re) {
        Resident r = re;
        os << r; 
        os << "Gia thue : " << fixed << setprecision(2);
        os << re.price << " trieu" << endl;
        return os;
    }
    bool operator >= (double money) {
        return price >= money;
    } //So sánh số tiền thuê nhà với money
};
int main () {
    int n, m, loai, year;
    double money;
    cin >> n >> m;
    Owner o[n];
    Renter r[m];
    cin.ignore();
    for(Owner &x : o) {
        cin >> x;
    }
    for(Renter &x : r) {
        cin >> x;
    }
    cin >> loai;
    int index = 0;

    if(loai == 1) {
        cin >> money;
        cout << "Cac can ho co gia tu " << money << "trieu: \n";
        for(Renter x : r) {
            if(x >= money) {
                cout << "#" << ++index << endl;
                cout << x;
            }
        }
        if(index == 0) {
            cout << "Khong tim thay!\n";
        }
    } else {
        cin >> year;
        cout << "Cac can ho da ban den nam " << year << ":\n";
        for(Owner x : o) {
            if(x <= year) {
                cout << "#" << ++index << endl;
                cout << x;
            }
        }
        if(index == 0) {
            cout << "Khong tim thay!\n";
        }
    }
    return 0;
}