using namespace std;
#include <iostream>
class Coffee {
    string name;
    int quantity;
public:
    void setname(string k) { name = k; } 
    void setquantity(int k) { quantity = k; }
    string getname() { return name; }
    int getquantity() { return quantity; }
    Coffee(){}
    Coffee(string _name, int _quantity) {
        name = _name;
        quantity = _quantity;
    }
    Coffee(const Coffee &cf) {
        name = cf.name;
        quantity = cf.quantity;
    }
    int getTotal() {
        int total = 0;
        if(name == "CPDD") total = 15000;
        else if(name == "CPSD") total = 20000;
        else if(name == "CPCB") total = 25000;
        else if(name == "BX") total = 20000;
        else if(name == "CPCPCN") total = 30000;
        return total;
    }
    int getPrice() {
        return getTotal() * quantity;
    }
    string getFullName() {
        if(name == "CPDD") return "Ca phe den da";
        else if(name == "CPSD") return "Ca phe sua da";
        else if(name == "CPCB") return "Ca phe cold brew";
        else if(name == "BX") return "Bac xiu";
        else if(name == "CPCPCN") return "Ca phe capuchino";
    }
    friend istream& operator >> (istream& is, Coffee &cf) {
        getline(is, cf.name, '-');
        is >> cf.quantity;
        return is;
    }
    void xuat() {
        cout << "Loai ca phe: " << getFullName() << "-" << quantity;
    }
};
string slove(string s) {
    int day = stoi(s.substr(0, s.find('/')));
    s.erase(0, s.find('/') + 1);
    int month = stoi(s.substr(0, s.find('/')));
    s.erase(0, s.find('/') + 1);
    int year = stoi(s);
    string str = "";
    if(day < 10) str += "0";
    str += to_string(day) + "/";
    if(month < 10) str += "0";
    str += to_string(month) + "/";
    str += to_string(year);
    return str;
}
class Customer {
    string name;
    string day;
    Coffee coffee;
    int money;
public:
    void setname(string k) { name = k; }
    void setday(string k) { day = k; }
    void setcoffee(Coffee k) { coffee = k; }
    void setmoney(int k) { money = k; }
    string getname() { return name; }
    string getday() { return day; }
    Coffee getcoffee() { return coffee; }
    int getmoney() { return money; }
    Customer(string _name, string _day, Coffee _coffee, int _money) {
        name = _name;
        day = _day;
        coffee = _coffee;
        money = _money;
    }
    Customer(const Customer &cs) {
        name = cs.name;
        day = cs.day;
        coffee = cs.coffee;
        money = cs.money;
    }
    int Price() {
       return coffee.getPrice();
    }
    virtual bool enough() = 0;
    virtual int tinhtien() = 0;
    virtual void print() {
        cout << "Ho va ten: " << name << endl;
        cout << "Ngay sinh: " << slove(day) << endl;
        coffee.xuat();
    }
};
class Vip : public Customer {
    int score;
public:
    void setscore(int k) { score = k; }
    int getscore() { return score; }
    Vip(string _name, string _day, Coffee _coffee, int _money, int _score) : Customer(
        _name, _day, _coffee, _money) {
        score = _score;
    }
    Vip(const Vip &cs) : Customer(cs) {
        score = cs.score;
    }
    int getScore() {
        return Price() / 5000;
    }
    int getFull() {
        return score + getScore();
    }
    string getHang() {
        if(getFull() < 40) return "Thanh Vien Bac";
        else if(getFull() < 70) return "Thanh Vien Vang";
        else return "Thanh Vien Bach Kim";
    }
    int getUuDai() {
        string s = getHang();
        if(s == "Thanh Vien Bac") return 10;
        else if(s == "Thanh Vien Vang") return 15;
        else return 20;
    }
    float UuDai() {
        return (100 - getUuDai()) * 0.01;
    }
    int tinhtien() {
        return Price() * UuDai();
    }
    bool enough() {
        return getmoney() >= tinhtien(); 
    }
    void print() {
        Customer :: print();
        cout << "\nDiem:" << getFull() << " - Thu hang:" << getHang() << "(Duoc giam: ";
        cout << getUuDai() << "%)\n";
        cout << "==> Thanh tien: " << tinhtien() << endl;
        cout << "So tien khach tra: " << getmoney() << " VND\n";
        if(enough()) {
            cout << "So tien thoi lai: " << getmoney() - tinhtien() <<" VND\n";
            cout << "Xin cam on quy khach!";
        } else {
            cout << "So tien cua quy khach khong du!";
        }
    }
};
class Normal : public Customer {
    bool voucher;
public:
    Normal(string _name, string _day, Coffee _coffee, int _money, bool _voucher) : Customer(
        _name, _day, _coffee, _money) {
        voucher = _voucher;
    }
    Normal(const Normal &cs) : Customer(cs) {
        voucher = cs.voucher;
    }
    bool getvoucher() {
        return voucher == true;
    }
    int tinhtien() {
        int total = Price();
        if(getvoucher()) total *= 0.9;
        return total;
    }
    bool enough() {
        return getmoney() >= tinhtien();
    }
    void print() {
        Customer :: print();
        cout << "\nVoucher: ";
        if(getvoucher()) {
            cout << "true(Duoc giam 10%)\n";
        } else {
            cout << "false\n";
        }
        cout << "==> Thanh tien: " << tinhtien() << " VND\n";
        cout << "So tien khach tra: " << getmoney() << "\n";
        if(enough()) {
            cout << "So tien thoi lai: " << getmoney() - tinhtien() << " VND\n";
            cout << "Xin cam on quy khach!\n";
        } else {
            cout << "So tien cua quy khach khong du!\n";
        }
    }
};
void inp(string &name, string &day, Coffee &coffee, int &money) {
    cin.ignore();
    getline(cin, name);
    cin >> day;
    cin.ignore();
    cin >> coffee >> money; 
}
void sort(Customer *a[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(a[i]->tinhtien() > a[j]->tinhtien()) {
                swap(a[i], a[j]);
            }
        }
    }
}
int main () {
    int n;
    cin >> n;
    string type;
    Customer *a[n];
    for(int i = 0; i < n; i++) {
        cin >> type;
        string name, day;
        Coffee coffee;
        int money;
        inp(name, day, coffee, money);
        if(type == "Vip") {
            int score; cin >> score;
            a[i] = new Vip(name, day, coffee, money, score);
        } else if(type == "Normal") {
            string vc; cin >> vc;
            a[i] = new Normal(name, day, coffee, money, (vc == "true"));
        }
    }
    cout << "--------DANH SACH HOA DON--------\n";
    for(int i = 0; i < n; i++) {
        cout << i + 1 << ".Loai khach: " << type << "\n";
        a[i]->print();
        cout << endl;
    }
		sort(a, n);
		Customer *top;
		for (int i = n - 1; i >= 0; i += -1) {
	    	if (a[i]->enough()) {
	        	top = a[i];
	        	break;
	    	}
		cout << "Khach hang mua nhieu nhat: ";
		cout << top->getname() << " - Tong tien: " << top->tinhtien() << " VND";
	}
}