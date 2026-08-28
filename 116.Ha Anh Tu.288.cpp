#include <iostream>
using namespace std;

class MaTran {
private:
    int soHang;
    int soCot;
    int a[100][100]; // Khai báo mang 2 chieu luu các phan tu

public:
    // Khoi tao mac dinh
    MaTran() {
        soHang = 0;
        soCot = 0;
    }

    // Câu 2: Phuong thuc nhap ma tran
    void nhap() {
        cout << "Nhap so hang: ";
        cin >> soHang;
        cout << "Nhap so cot: ";
        cin >> soCot;

        cout << "Nhap cac phan tu cua ma tran:\n";
        for (int i = 0; i < soHang; i++) {
            for (int j = 0; j < soCot; j++) {
                cout << "a[" << i << "][" << j << "] = ";
                cin >> a[i][j];
            }
        }
    }

    // Câu 2: Phuong thuc xuat ma tran
    void xuat() const {
        for (int i = 0; i < soHang; i++) {
            for (int j = 0; j < soCot; j++) {
                cout << a[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // Khai báo hàm ban (friend function) de cong 2 ma tran
    friend MaTran congMaTran(const MaTran& m1, const MaTran& m2);
    
    // Hàm ho tro kiem tra kích thuoc ma tran
    bool kiemTraDongCap(const MaTran& m) const {
        return (this->soHang == m.soHang && this->soCot == m.soCot);
    }
};

// Câu 3: Ðinh nghia hàm ban thuc hien cong hai ma tran dang cap
MaTran congMaTran(const MaTran& m1, const MaTran& m2) {
    MaTran kq;
    kq.soHang = m1.soHang;
    kq.soCot = m1.soCot;

    for (int i = 0; i < m1.soHang; i++) {
        for (int j = 0; j < m1.soCot; j++) {
            kq.a[i][j] = m1.a[i][j] + m2.a[i][j];
        }
    }
    return kq;
}

int main() {
    MaTran m1, m2, mTong;

    cout << "=== NHAP MA TRAN 1 ===\n";
    m1.nhap();

    cout << "\n=== NHAP MA TRAN 2 ===\n";
    m2.nhap();

    // Kiem tra tính dang cap truoc khi cong
    if (!m1.kiemTraDongCap(m2)) {
        cout << "\nHai ma tran khong dong cap! Khong the thuc hien phep cong.\n";
        return 0;
    }

    // In lai hai ma tran ban d?u
    cout << "\n====================================\n";
    cout << "Ma tran 1 vua nhap:\n";
    m1.xuat();

    cout << "\nMa tran 2 vua nhap:\n";
    m2.xuat();

    // Thuc hien cong qua hàm ban
    mTong = congMaTran(m1, m2);

    // In ma tran ket qua
    cout << "\nMa tran tong (Ket qua):\n";
    mTong.xuat();

    return 0;
}

