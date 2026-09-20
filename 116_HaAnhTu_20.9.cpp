#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

class Nguoi {
protected:
    string hoTen;
    int namSinh;

public:
    void nhap() {
        cout << "  Nhap ho ten: ";
        getline(cin, hoTen);

        cout << "  Nhap nam sinh: ";
        cin >> namSinh;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void xuat() const {
        cout << "  Ho ten     : " << hoTen << endl;
        cout << "  Nam sinh   : " << namSinh << endl;
    }

    string getHoTen() const {
        return hoTen;
    }
};

class SinhVien : public Nguoi {
private:
    string maSV;
    float diemTB;

public:

    void nhap() {
        Nguoi::nhap();

        cout << "  Nhap ma sinh vien: ";
        getline(cin, maSV);

        cout << "  Nhap diem trung binh: ";
        cin >> diemTB;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void xuat() const {
        Nguoi::xuat();
        cout << "  Ma sinh vien: " << maSV << endl;
        cout << "  Diem TB    : " << diemTB << endl;
    }

    string getMaSV() const {
        return maSV;
    }
};

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<SinhVien> dsSinhVien(n);

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
        dsSinhVien[i].nhap();
    }
)
    string tuKhoa;
    cout << "\nNhap ma sinh vien hoac ho ten can tim: ";
    getline(cin, tuKhoa);

    bool timThay = false;
    cout << "\nKET QUA TIM KIEM:\n";
    for (int i = 0; i < n; i++) {
        if (dsSinhVien[i].getMaSV() == tuKhoa || dsSinhVien[i].getHoTen() == tuKhoa) {
            cout << "Tim thay sinh vien:\n";
            dsSinhVien[i].xuat();
            timThay = true;
        }
    }

    if (!timThay) {
        cout << "Khong tim thay sinh vien nao phu hop!\n";
    }

    return 0;
}
