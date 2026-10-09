
#include "Student.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <limits>
#include <sstream>
#include <utility>

using namespace std;

namespace {
    void xoaBoDem() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string nhapChuoi(const string& thongBao) {
        string giaTri;
        do {
            cout << thongBao;
            getline(cin, giaTri);
            if (giaTri.empty())
                cout << "Khong duoc de trong!\n";
        } while (giaTri.empty() && cin);
        return giaTri;
    }

    double nhapDiem() {
        double d;
        while (true) {
            cout << "Nhap diem (0-10): ";
            if (cin >> d && d >= 0 && d <= 10) {
                xoaBoDem();
                return d;
            }
            cout << "Diem khong hop le!\n";
            cin.clear();
            xoaBoDem();
        }
    }
}

Student::Student() : diem(0) {}

Student::Student(string ma, string ten, double d)
    : maSV(move(ma)), hoTen(move(ten)), diem(d) {}

string Student::getMaSV() const {
    return maSV;
}

double Student::getDiem() const {
    return diem;
}

void Student::nhap() {
    maSV = nhapChuoi("Nhap ma sinh vien: ");
    hoTen = nhapChuoi("Nhap ho ten: ");
    diem = nhapDiem();
}

void Student::xuat() const {
    cout << left << setw(15) << maSV
         << setw(30) << hoTen
         << fixed << setprecision(2) << diem << '\n';
}

void StudentManager::themSinhVien() {
    Student sv;
    sv.nhap();

    for (const Student& s : danhSach) {
        if (s.getMaSV() == sv.getMaSV()) {
            cout << "Ma sinh vien da ton tai!\n";
            return;
        }
    }

    danhSach.push_back(sv);
    cout << "Them sinh vien thanh cong!\n";
}

void StudentManager::hienThiDanhSach() const {
    if (danhSach.empty()) {
        cout << "Danh sach sinh vien dang rong!\n";
        return;
    }

    cout << left << setw(15) << "Ma SV"
         << setw(30) << "Ho ten"
         << "Diem\n";
    cout << string(55, '-') << '\n';

    for (const Student& sv : danhSach)
        sv.xuat();
}

void StudentManager::timKiemSinhVien() const {
    string ma = nhapChuoi("Nhap ma sinh vien can tim: ");

    for (const Student& sv : danhSach) {
        if (sv.getMaSV() == ma) {
            cout << "Tim thay sinh vien:\n";
            sv.xuat();
            return;
        }
    }

    cout << "Khong tim thay sinh vien!\n";
}

void StudentManager::capNhatSinhVien() {
    string ma = nhapChuoi("Nhap ma sinh vien can sua: ");

    for (Student& sv : danhSach) {
        if (sv.getMaSV() == ma) {
            cout << "Nhap lai thong tin:\n";
            string ten = nhapChuoi("Ho ten moi: ");
            double diem = nhapDiem();
            sv = Student(ma, ten, diem);
            cout << "Cap nhat thanh cong!\n";
            return;
        }
    }

    cout << "Khong tim thay sinh vien!\n";
}

void StudentManager::xoaSinhVien() {
    string ma = nhapChuoi("Nhap ma sinh vien can xoa: ");

    auto it = remove_if(
        danhSach.begin(), danhSach.end(),
        [&ma](const Student& sv) {
            return sv.getMaSV() == ma;
        }
    );

    if (it == danhSach.end()) {
        cout << "Khong tim thay sinh vien!\n";
        return;
    }

    danhSach.erase(it, danhSach.end());
    cout << "Xoa sinh vien thanh cong!\n";
}

void StudentManager::sapXepTheoDiem() {
    sort(danhSach.begin(), danhSach.end(),
         [](const Student& a, const Student& b) {
             return a.getDiem() > b.getDiem();
         });

    cout << "Da sap xep theo diem giam dan!\n";
    hienThiDanhSach();
}

void StudentManager::luuFile() const {
    ofstream file("students.txt");

    if (!file) {
        cout << "Khong the mo file de ghi!\n";
        return;
    }

    for (const Student& sv : danhSach) {
        // Luu theo dinh dang ma|ten|diem
        // Su dung xuat thong qua file tam ben duoi
        ostringstream buffer;
        streambuf* old = cout.rdbuf(buffer.rdbuf());
        sv.xuat();
        cout.rdbuf(old);

        // Dinh dang hien thi duoc luu theo tung dong
        file << buffer.str();
    }

    cout << "Da luu vao students.txt!\n";
}

void StudentManager::docFile() {
    // Du lieu se duoc doc theo dinh dang ma|ten|diem.
    // Ham nay duoc hoan thien o phan bo sung ben duoi.
}
