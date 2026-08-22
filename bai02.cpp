// c1 
#include <iostream>
#include <string>
#include <iomanip> 
struct NhanVien {
    int id;
    std::string ten;
    double luong;
};

int main() {
    NhanVien ds[10] = {
        {1, "Nguyen Van A", 1000},
        {2, "Tran Thi B", 1200},
        {3, "Le Van C", 1100},
        {4, "Pham Van D", 1500},
        {5, "Hoang Thi E", 1300},
        {6, "Vu Van F", 900},
        {7, "Dang Thi G", 1400},
        {8, "Bui Van H", 1050},
        {9, "Dinh Thi I", 1250},
        {10, "Ngo Van K", 1350}
    };
    std::cout << "---------------------------------------------\n";
    std::cout << std::left 
              << std::setw(8)  << "ID" 
              << std::setw(20) << "Ho va Ten" 
              << std::setw(12) << "Luong" << "\n";
    std::cout << "---------------------------------------------\n";
    for (int i = 0; i < 10; i++) {
        std::cout << std::left 
                  << std::setw(8)  << ds[i].id 
                  << std::setw(20) << ds[i].ten 
                  << std::setw(12) << ds[i].luong << "\n";
    }

    std::cout << "---------------------------------------------\n";

    return 0;
}
//  c2
 #include <iostream>
#include <string>
#include <iomanip>

struct NhanVien {
    int ma;
    std::string ten;
    double luong;
};

int main() {
    NhanVien *ds = new NhanVien[10];

  
    for (int i = 0; i < 10; i++) {
        std::cout << "--- Nhap nhan vien " << i + 1 << " ---\n";
        ds[i].ma = i + 1;
        
        std::cout << "Nhap ten: ";
        std::getline(std::cin >> std::ws, ds[i].ten);
        
        std::cout << "Nhap luong: ";
        std::cin >> ds[i].luong;
    }

    std::cout << "\n---------------------------------------------\n";
    std::cout << std::left 
              << std::setw(8)  << "ID" 
              << std::setw(20) << "Ho va Ten" 
              << std::setw(12) << "Luong" << "\n";
    std::cout << "---------------------------------------------\n";

    for (int i = 0; i < 10; i++) {
        std::cout << std::left 
                  << std::setw(8)  << ds[i].ma 
                  << std::setw(20) << ds[i].ten 
                  << std::setw(12) << ds[i].luong << "\n";
    }
    std::cout << "---------------------------------------------\n";
    delete[] ds;

    return 0;
}
// c3 
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct NhanVien {
    int ma;
    std::string ten;
    double luong;
};

int main() {
    std::vector<NhanVien> ds(10);

    for (int i = 0; i < 10; i++) {
        std::cout << "--- Nhap nhan vien " << i + 1 << " ---\n";
        ds[i].ma = i + 1;
        
        std::cout << "Nhap ten: ";
        std::getline(std::cin >> std::ws, ds[i].ten);
        
        std::cout << "Nhap luong: ";
        std::cin >> ds[i].luong;
    }
    std::cout << "\n---------------------------------------------\n";
    std::cout << std::left 
              << std::setw(8)  << "ID" 
              << std::setw(20) << "Ho va Ten" 
              << std::setw(12) << "Luong" << "\n";
    std::cout << "---------------------------------------------\n";

    for (int i = 0; i < 10; i++) {
        std::cout << std::left 
                  << std::setw(8)  << ds[i].ma 
                  << std::setw(20) << ds[i].ten 
                  << std::setw(12) << ds[i].luong << "\n";
    }
    std::cout << "---------------------------------------------\n";

    return 0;
}