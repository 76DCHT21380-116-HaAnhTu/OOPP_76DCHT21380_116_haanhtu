#include <iostream>
using namespace std;
class PS1 {
protected:
    int tuSo;
    int mauSo;

public:
    int UCLN(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    void Nhap() {
        cout << "Nhap tu so: ";
        cin >> tuSo;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> mauSo;
            if (mauSo == 0)
                cout << "Mau so khong duoc bang 0, nhap lai!\n";
        } while (mauSo == 0);
    }

    void In() {
        cout << tuSo << "/" << mauSo;
    }

    void ToiGian() {
        int uc = UCLN(tuSo, mauSo);
        if (uc != 0) {
            tuSo /= uc;
            mauSo /= uc;
        }
        if (mauSo < 0) {
            mauSo = -mauSo;
            tuSo = -tuSo;
        }
    }

    int getTu() { return tuSo; }
    int getMau() { return mauSo; }
};

class PS2 : public PS1 {
public:
    PS2& operator=(const PS2& other) {
        tuSo = other.tuSo;
        mauSo = other.mauSo;
        return *this;
    }

    bool operator>(const PS2& other) {
        return (this->tuSo * other.mauSo) > (other.tuSo * this->mauSo);
    }
};

int main() {
    const int MAX = 10;
    PS2 ds[MAX];
    int n;

    cout << "Nhap so luong phan so (toi da 10): ";
    cin >> n;
    if (n > MAX) n = MAX;

    for (int i = 0; i < n; i++) {
        cout << "\nNhap phan so thu " << i + 1 << ":\n";
        ds[i].Nhap();
        ds[i].ToiGian();
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (ds[j + 1] > ds[j]) {
                PS2 tam;
                tam = ds[j];       
                ds[j] = ds[j + 1]; 
                ds[j + 1] = tam;   
            }
        }
    }
    
    cout << "\nDanh sach phan so sau khi sap xep giam dan:\n";
    for (int i = 0; i < n; i++) {
        ds[i].In();
        cout << "\t";
    }
    cout << endl;

    return 0;
}
