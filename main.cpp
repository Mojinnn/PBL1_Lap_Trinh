#include <iostream>
#include <string.h>
#include "KhachHang.h"
#include "ThanhToan.h"

using namespace std;

void NhapThongTin (KhachHang &kh) {
    cout << "-------Nhap Thong Tin Khach Hang-------" << endl;
    kh.setTen ();
    kh.setTuoi ();
    kh.setChieuCao ();
}

void XuatThongTin (KhachHang &kh, ThanhToan &tt) {
    cout << "--------------------------------------" << endl;
    cout << "Ten: " << kh.getTen () << endl;
    cout << "Tuoi: " << kh.getTuoi () << endl;
    cout << "Chieu cao: " << kh.getChieuCao () << endl;
    cout << "Tong Tien: " << tt.ThanhTien () << endl;
}

int main () {
    int soluong;
    KhachHang *kh;
    ThanhToan *tt;

    cout << "Nhap so luong khach hang: ";
    cin >> soluong;

    kh = new KhachHang [soluong];
    tt = new ThanhToan [soluong];

    for (int i = 0; i < soluong; i++) {
        NhapThongTin (kh[i]);
        // tinhTien (tt[i]);
        XuatThongTin (kh[i], tt[i]);
    }

    delete [] kh;
    delete [] tt;

    return 0;
}