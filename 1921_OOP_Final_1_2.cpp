#include <iostream>
using namespace std;
class Device {
private:
    string model;
    string manufactory;
    int power;
    double cost;
    int size;
public:
    void setmodel(string k) { model = k; }
    void setmanufactory(string k) { manufactory = k; }
    void setpower(int k) { power = k; }
    void setcost(double k) { cost = k; }
    string getmodel() { return model; }
    string getmanufactory() { return manufactory; }
    int getpower() { return power; }
    double getcost() { return cost; }
    void setsize(int k) { size = k; }
    int getsize() { return size; }
    Device(string _model = "", string _manufactory = "", int _power = 0, double _cost = 0, int _size = 0) {
        model = _model;
        manufactory = _manufactory;
        power = _power;
        cost = _cost;
        size = _size;
    }
    Device(const Device &d) {
        model = d.model;
        manufactory = d.manufactory;
        power = d.power;
        cost = d.cost;
        size = d.size;
    }
    double getTotalCost() {
        return (cost + cost * 0.1);
    }
    bool operator > (const Device &a) {
        if(power > a.power) return true;
        else if(power == a.power) {
            if(cost < a.cost) return true;
            }
        return false;
    }
    bool operator < (const Device &a)  {
        if(power < a.power) return true;
        else if(power == a.power) {
            if(cost > a.cost) return true;
        }
        return false;
    }
    bool operator == (const Device &a) {
        return power == a.power && cost == a.cost;
    }
    double operator * () {
        return getTotalCost() * size;
    }
    friend istream& operator >> (istream& is, Device &d) {
        getline(is >> ws, d.model);    
        getline(is >> ws, d.manufactory);
        is >> d.power;
        is >> d.cost;
        is >> d.size;
        return is;
    }
};
int main (){
    int n,b,c ;
    cin>>n;
    Device a[100];
    for (int i=0 ;i<n;i++){
        cin>>a[i];
    }
    cin.ignore();
    string d ,e ;
    getline (cin,d);
    getline (cin,e);
    double s =0 ; 
    for (int i=0 ; i<n ; i++){
       s += *a[i];
        if(a[i].getmodel() == d){
            b = i;
        }
        if(a[i].getmodel() ==e){
            c = i;
        }
    }
    cout<<s<<endl;
    if(a[b] > a[c]){
        cout<<">";
    }
    else if (a[b]<a[c]){
        cout<<"<";
    }
    else {
        cout<<"=";
    }
}