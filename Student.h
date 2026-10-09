
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    std::string maSV;
    std::string hoTen;
    double diem;

public:
    Student();
    Student(std::string ma, std::string ten, double d);

    std::string getMaSV() const;
    double getDiem() const;

    void nhap();
    void xuat() const;
};

class StudentManager {
private:
    std::vector<Student> danhSach;

public:
    void themSinhVien();
    void hienThiDanhSach() const;
    void timKiemSinhVien() const;
    void capNhatSinhVien();
    void xoaSinhVien();
    void sapXepTheoDiem();
    void luuFile() const;
    void docFile();
};

#endif
