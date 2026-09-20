#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class MonHoc {
protected:
    string tenMonHoc;
    float diemCC;   
    float diemKT;   
    float diemDT;   

public:
    MonHoc() {
        tenMonHoc = "";
        diemCC = diemKT = diemDT = 0;
    }

    void nhapMonHoc() {
        cout << "  - Ten mon hoc: ";
        getline(cin, tenMonHoc);
        cout << "  - Diem chuyen can (CC): ";
        cin >> diemCC;
        cout << "  - Diem kiem tra (KT): ";
        cin >> diemKT;
        cout << "  - Diem thi (DT): ";
        cin >> diemDT;
    }

    void xuatMonHoc() const {
        cout << "Mon hoc     : " << tenMonHoc << endl;
        cout << "Diem CC     : " << diemCC << endl;
        cout << "Diem KT     : " << diemKT << endl;
        cout << "Diem DT     : " << diemDT << endl;
    }

    float getCC() const { return diemCC; }
    float getKT() const { return diemKT; }
    float getDT() const { return diemDT; }
};

class SinhVien : public MonHoc {
private:
    string hoTen;
    string lop;
    string maSV;

public:
    SinhVien() : MonHoc() {
        hoTen = lop = maSV = "";
    }

    void nhap() {
        cout << "- Ma sinh vien: ";
        cin.ignore();
        getline(cin, maSV);
        cout << "- Ho ten      : ";
        getline(cin, hoTen);
        cout << "- Lop         : ";
        getline(cin, lop);
        cout << "Nhap diem mon hoc:\n";
        nhapMonHoc();
    }

    void xuat() const {
        cout << "Ma SV       : " << maSV << endl;
        cout << "Ho ten      : " << hoTen << endl;
        cout << "Lop         : " << lop << endl;
        xuatMonHoc();
        cout << fixed << setprecision(2);
        cout << "Diem HP     : " << tinhDiemHocPhan() << endl;
        if (bkCamThi())
            cout << "  ==> CAM THI\n";
    }

    float tinhDiemHocPhan() const {
        return diemCC * 0.1f + diemKT * 0.3f + diemDT * 0.6f;
    }

    bool bkCamThi() const {
        return (diemCC < 5) || (diemKT == 0);
    }

    string getHoTen() const { return hoTen; }
    string getMaSV() const { return maSV; }
};


int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    vector<SinhVien> ds(n);

    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin sinh vien thu " << i + 1 << " ---\n";
        ds[i].nhap();
    }

    cout << "\n===== DANH SACH SINH VIEN =====\n";
    for (int i = 0; i < n; i++) {
        cout << "\n-- Sinh vien " << i + 1 << " --\n";
        ds[i].xuat();
    }

    cout << "\n===== DANH SACH SINH VIEN BI CAM THI =====\n";
    bool coCamThi = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].bkCamThi()) {
            coCamThi = true;
            cout << "\n-- Sinh vien " << i + 1 << " --\n";
            ds[i].xuat();
        }
    }
    if (!coCamThi)
        cout << "Khong co sinh vien nao bi cam thi.\n";

    return 0;
}
