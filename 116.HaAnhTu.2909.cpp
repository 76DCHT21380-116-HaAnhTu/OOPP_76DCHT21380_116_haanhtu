#include <iostream>
#include <cmath>
using namespace std;

class SP1 {
protected:
    double thuc;
    double ao;
public:
    SP1(double t = 0, double a = 0) {
        thuc = t;
        ao = a;
    }
    void nhap() {
        cout << "Nhap phan thuc: ";
        cin >> thuc;
        cout << "Nhap phan ao: ";
        cin >> ao;
    }
    void in() {
        if (ao >= 0)
            cout << thuc << " + " << ao << "i";
        else
            cout << thuc << " - " << -ao << "i";
    }
    double module() {
        return sqrt(thuc * thuc + ao * ao);
    }
};

class SP2 : public SP1 {
public:
    SP2(double t = 0, double a = 0) : SP1(t, a) {}
    SP2& operator=(const SP2 &x) {
        if (this != &x) {
            thuc = x.thuc;
            ao = x.ao;
        }
        return *this;
    }
    bool operator>(SP2 &x) {
        return module() > x.module();
    }
};

int main() {
    SP2 ds[10];
    int n;
    do {
        cout <<
