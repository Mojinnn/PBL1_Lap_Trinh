#include <iostream>
#include <fstream>
#include <ctime>
#include <string.h>
#include "KhachHang.h"
#include "ThanhToan.h"

using namespace std;

//ham hien thi thoi gian
string ThoiGian () {
    char *dt= new char[10];
    time_t now = time(0);
    dt = ctime(&now);
    string currentTime(dt);
    return currentTime;
}

//ham Nhap thong tin tung doi tuong
void NhapThongTin (KhachHang *kh, ThanhToan *tt, int &soluong) {
    for (int i = 0; i < soluong; i++) {
        cout << "-------Nhap Thong Tin Khach Hang-------" << endl;
        kh[i].setSDT ();
        kh[i].setTuoi ();
        kh[i].setChieuCao ();
        tt[i].setGiaVe (kh[i]);
        tt[i].setPhi ();
    }
}

long KhuyenMai (KhachHang *kh, ThanhToan *tt, int &soluong) {
    long khuyenmai;
    if (soluong >= 5) {
        khuyenmai = 0.05 * tt[soluong - 1].getTongTatCa ();
    }
    return khuyenmai;
}

//ham Xuat thong tin doi tuong
void XuatThongTin (KhachHang *kh, ThanhToan *tt, int &soluong) {
    for (int i = 0; i < soluong; i++) {
        cout << "--------------------------------------" << endl;
        cout << "SDT: " << kh[i].getSDT () << endl;
        cout << "Tuoi: " << kh[i].getTuoi () << endl;
        cout << "Chieu cao: " << kh[i].getChieuCao () << endl;
        cout << "Ve: " << tt[i].getGiaVe () << endl;
        cout << "Phi: " << tt[i].getPhi () << endl;
        cout << "Thue: " << tt[i].getThue () << endl;
        cout << "Thanh Tien: " << tt[i].ThanhTien () << endl;
    }
    cout << "--------------------------------------" << endl;
    cout << "Khuyen Mai: " << KhuyenMai (kh, tt, soluong) << endl;
    cout << "TONG TIEN: " << tt[soluong - 1].getTongTatCa () - KhuyenMai (kh, tt, soluong) << endl;
}

//ham ghi file
void GhiFile (KhachHang *kh, ThanhToan *tt, int &soluong) {
    ofstream file;
    file.open("HoaDon.txt", ios::app);
        for (int i = 0; i < soluong; i++) {
            file << "----------------------------------------" << endl;
            file << "------ Thoi gian: "<< ThoiGian() << endl;
            file << "SDT: " << kh[i].getSDT () << endl;
            file << "Tuoi: " << kh[i].getTuoi () << endl;
            file << "Chieu cao: " << kh[i].getChieuCao () << endl;
            file << "Ve: " << tt[i].getGiaVe () << endl;
            file << "Phi: " << tt[i].getPhi () << endl;
            file << "Thue: " << tt[i].getThue () << endl;
            file << "Thanh Tien: " << tt[i].ThanhTien () << endl;
        }
        cout << "--------------------------------------" << endl;
        file << "Khuyen Mai: " << KhuyenMai (kh, tt, soluong) << endl;
        file << "TONG TIEN: " << tt[soluong - 1].getTongTatCa () - KhuyenMai (kh, tt, soluong) << endl;
        file << "------------------------------------------------------------------" << endl;
    file.close();
}

//ham main
int main () {
    int soluong;
    KhachHang *kh;
    ThanhToan *tt;

    cout << "Nhap so luong khach hang: ";
    cin >> soluong;

    kh = new KhachHang [soluong];
    tt = new ThanhToan [soluong];

    NhapThongTin (kh, tt, soluong);

    XuatThongTin (kh, tt, soluong);

    GhiFile (kh, tt, soluong);

    delete [] kh;
    delete [] tt;

    return 0;
}