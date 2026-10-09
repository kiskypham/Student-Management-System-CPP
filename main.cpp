
#include "Student.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    StudentManager manager;
    manager.docFile();

    int luaChon;

    do {
        cout << "\n========== STUDENT MANAGEMENT SYSTEM ==========\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Hien thi danh sach sinh vien\n";
        cout << "3. Tim kiem sinh vien\n";
        cout << "4. Cap nhat thong tin sinh vien\n";
        cout << "5. Xoa sinh vien\n";
        cout << "6. Sap xep theo diem giam dan\n";
        cout << "7. Luu du lieu vao file\n";
        cout << "8. Thoat\n";
        cout << "===============================================\n";
        cout << "Nhap lua chon: ";

        if (!(cin >> luaChon)) {
            cout << "Vui long nhap so!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (luaChon) {
            case 1:
                manager.themSinhVien();
                break;
            case 2:
                manager.hienThiDanhSach();
                break;
            case 3:
                manager.timKiemSinhVien();
                break;
            case 4:
                manager.capNhatSinhVien();
                break;
            case 5:
                manager.xoaSinhVien();
                break;
            case 6:
                manager.sapXepTheoDiem();
                break;
            case 7:
                manager.luuFile();
                break;
            case 8:
                manager.luuFile();
                cout << "Tam biet!\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (luaChon != 8);

    return 0;
}
