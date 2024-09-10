#include <iostream>
#include <vector>
using namespace std;
class Device {
private:
    string model;
    string manufactory;
    int power;
    double cost;
public:
    // void setmodel(string k) { model = k; }
    // void setmanufactory(string k) { manufactory = k; }
    // void setpower(int k) { power = k; }
    // void setcost(double k) { cost = k; }
    string getmodel() { return model; }
    // string getmanufactory() { return manufactory; }
    // int getpower() { return power; }
    // double getcost() { return cost; }
    Device(string _model = "", string _manufactory = "", int _power = 0, double _cost = 0) {
        model = _model;
        manufactory = _manufactory;
        power = _power;
        cost = _cost;
    }
    Device(const Device &d) {
        model = d.model;
        manufactory = d.manufactory;
        power = d.power;
        cost = d.cost;
    }
    double getTotalCost() {
        return (cost + cost * 0.1);
    }
    friend istream& operator >> (istream& is, Device &d) {
        getline(cin , d.model);
        getline(cin , d.manufactory);
        is >> d.power;
        is >> d.cost;
        return is;
    }
    friend ostream& operator << (ostream& os, Device &d) {
        os << d.model << "-" << d.manufactory << "-" << d.power << "W-";
        os << d.getTotalCost() << "USD";
        return os;
    }
};
class Television : public Device {
    int size;
    int width;
    int height;
public:
    // void setsize(int k) { size = k; }
    // void setwidth(int k) { width = k; }
    // void setheight(int k) { height = k; }
    // int getsize() { return size; }
    // int getwidth() { return width; }
    // int getheight() { return height; }
    Television(string _model = "", string _manufactory = "", int _power = 0,
    double _cost = 0, int _size = 0, int _width = 0, int _height = 0) : Device( _model,
    _manufactory, _power, _cost) {
        size = _size;
        width = _width;
        height = _height;
    }
    Television(const Television &te) : Device(te) {
        size = te.size;
        width = te.width;
        height = te.height;
    }
    friend istream& operator >> (istream& is, Television &d) {
        Device &d1 = d;
        is >> d1;
        is >> d.size >> d.width >> d.height;
        return is;
    }
    friend ostream& operator << (ostream& os, Television d) {
        Device d1 = d;
        os << d1;
        os << "-" << d.size << "Inch-" << d.width << "x" << d.height;
        return os;
    }
};
class Refrigerator : public Device {
    int capacity;
    double weight;
public:
    void setcapacity(int k) { capacity = k; }
    void setweight(int k) { weight = k; }
    int getcapacity() { return capacity; }
    int getweight() { return weight; }
    Refrigerator(string _model = "", string _manufactory = "", int _power = 0,
    double _cost = 0, int _capacity = 0, double _weight = 0) : Device( _model, _manufactory, _power, _cost) {
        capacity = _capacity;
        weight = _weight;
    }
    Refrigerator(const Refrigerator &te) : Device(te) {
        capacity = te.capacity;
        weight = te.weight;
    }
    friend istream& operator >> (istream& is, Refrigerator &d) {
        Device &d1 = d;
        is >> d1;
        is >> d.capacity >> d.weight;
        return is;
    }
    friend ostream& operator << (ostream& os, Refrigerator d) {
        Device d1 = d;
        os << d1;
        os << "-" << d.capacity << "Lit-" << d.weight << "Kg";
        return os;
    }
};
int main (){
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
}
cả 3 ý đều ra nhưng ưu tiên ý 1 vì OOP ko bt thầy có cho xài vector không
/*int n;
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
}*/

/* xài void Device :: nhap()
            Device :: xuat()
            
    Television m ,tel[100];
    int cnt = 0;
    Refrigerator n ,ref[100];
    int cnt1 = 0;
    int pt;
    cin >> pt;
    int x;
    double min = 10000;
    double max = -10000;
    for(int i = 0 ; i < pt ; i++){
        cin >>x;
        cin.ignore();
        if(x == 0){
            m.nhapTel();
            m.xuatTel();
            tel[cnt++] = m ;
                for(int i = 0 ; i < cnt ; i++){
                    if(min > tel[i].getTotalCost()) min = tel[i].getTotalCost();
                }
            cout<<endl;
        }
        else if(x == 1){
            n.nhapRef();
            n.xuatRef();
            ref[cnt1++] = n;
            for(int i = 0 ; i < cnt1 ; i++){
                if(max < ref[i].getTotalCost()) max = ref[i].getTotalCost();
            }
            cout << endl;
        }
    }
    
    if(cnt == 0){ 
        cout << "-1";
    }
    else {
        for(int i = 0 ; i < cnt ; i++){
            if(min == tel[i].getTotalCost())cout << tel[i].getModel() << " ";
        }
    }
    cout << endl;
    
    if(cnt1 == 0){
        cout << "-1";
    } 
    else {
        for(int i = 0 ; i < cnt1 ; i++){
            if(max == ref[i].getTotalCost()) cout << ref[i].getModel() << " ";
        }
    }
    return 0;
}
*/
cách 2
#include <iostream>
const int maxn = (int)10000;
using namespace std;
class Device {
private:
    string model;
    string manufactory;
    int power;
    double cost;
public:
    void setmodel(string k) { model = k; }
    void setmanufactory(string k) { manufactory = k; }
    void setpower(int k) { power = k; }
    void setcost(double k) { cost = k; }
    string getmodel() { return model; }
    string getmanufactory() { return manufactory; }
    int getpower() { return power; }
    double getcost() { return cost; }
    Device(string _model = "", string _manufactory = "", int _power = 0, double _cost = 0) {
        model = _model;
        manufactory = _manufactory;
        power = _power;
        cost = _cost;
    }
    Device(const Device &d) {
        model = d.model;
        manufactory = d.manufactory;
        power = d.power;
        cost = d.cost;
    }
    double getTotalCost() {
        return (cost + cost * 0.1);
    }
    friend istream& operator >> (istream& is, Device &d) {
        getline(is >> ws, d.model);    
        getline(is >> ws, d.manufactory);
        is >> d.power;
        is >> d.cost;
        return is;
    }
    friend ostream& operator << (ostream& os, Device d) {
        os << d.model << "-" << d.manufactory << "-" << d.power << "W-";
        os << d.getTotalCost() << "USD-";
        return os;
    }
};
class Television : public Device {
    int size;
    int width;
    int height;
public:
    void setsize(int k) { size = k; }
    void setwidth(int k) { width = k; }
    void setheight(int k) { height = k; }
    int getsize() { return size; }
    int getwidth() { return width; }
    int getheight() { return height; }
    Television(string _model = "", string _manufactory = "", int _power = 0,
    double _cost = 0, int _size = 0, int _width = 0, int _height = 0) : Device( _model,
    _manufactory, _power, _cost) {
        size = _size;
        width = _width;
        height = _height;
    }
    Television(const Television &te) : Device(te) {
        size = te.size;
        width = te.width;
        height = te.height;
    }
    friend istream& operator >> (istream& is, Television &d) {
        is >> static_cast<Device&>(d);
        is >> d.size >> d.width >> d.height;
        return is;
    }
    friend ostream& operator << (ostream& os, Television d) {
        os << static_cast<Device>(d);
        os << d.size << "Inch-" << d.width << "x";
        os << d.height << endl;
        return os;
    }
};
class Refrigerator : public Device {
    int capacity;
    double weight;
public:
    void setcapacity(int k) { capacity = k; }
    void setweight(int k) { weight = k; }
    int getcapacity() { return capacity; }
    int getweight() { return weight; }
    Refrigerator(string _model = "", string _manufactory = "", int _power = 0,
    double _cost = 0, int _capacity = 0, double _weight = 0) : Device( _model, _manufactory, _power, _cost) {
        capacity = _capacity;
        weight = _weight;
    }
    Refrigerator(const Refrigerator &te) : Device(te) {
        capacity = te.capacity;
        weight = te.weight;
    }
    friend istream& operator >> (istream& is, Refrigerator &te) {
        is >> static_cast<Device&>(te);
        is >> te.capacity;
        is >> te.weight;
        return is;
    }
    friend ostream& operator << (ostream& os, Refrigerator te) {
        os << static_cast<Device>(te);
        os << te.capacity << "Lit-" << te.weight << "Kg\n";
        return os;
    }
};
int main (){
    int n;
    cin >> n;
    Device arr[100];
    double max = -maxn;
    double min = maxn;
    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        // cin.ignore();
        if(m == 0) {
            Television a;
            cin >> a;
            cout << a;
            arr[i] = static_cast<Device>(a);
            if(min > a.getTotalCost()) {
                min = a.getTotalCost();
            }
        } else {
            Refrigerator a;
            cin >> a;
            cout << a;
            arr[i] = static_cast<Device>(a);
            if(max < a.getTotalCost()) {
                max = a.getTotalCost();
            }
        }
    }
    int check = 0, check1 = 0;
    for(int i = 0; i < n; i++) {
        if(check == 0) {
            if(min == maxn) {
                cout << -1;
                check = 1;
            } else if(min == arr[i].getTotalCost()) {
                cout << arr[i].getmodel() << " ";
                check = 0;
            }
        }
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        if(check1 == 0) {
            if(max == -maxn) {
                cout << -1;
                check1 = 1;
            } else if(max == arr[i].getTotalCost()) {
                cout << arr[i].getmodel() << " ";
                check1 = 0;
            }
        }
    }
    return 0;
}