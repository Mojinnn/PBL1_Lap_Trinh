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

void XuatThongTin (KhachHang &kh) {
    cout << "--------------------------------------" << endl;
    cout << "Ten: " << kh.getTen () << endl;
    cout << "Tuoi: " << kh.getTuoi () << endl;
    cout << "Chieu cao: " << kh.getChieuCao () << endl;
    cout << "Gia: " << kh.getGia () << endl;
}

int main () {
    int soluong;
    KhachHang *kh;


    cout << "Nhap so luong khach hang: ";
    cin >> soluong;

    kh = new KhachHang [soluong];

    for (int i = 0; i < soluong; i++) {
        NhapThongTin (kh[i]);
    }
    
    for (int i = 0; i < soluong; i++) {
        XuatThongTin (kh[i]);
    }

    delete [] kh;


    // cout << "Quy khach can tra so tien la: " << tt1.ThanhTien () << endl;

    return 0;
}
// $ g++ KhachHang.cpp ThanhToan.cpp main.cpp -o restaurant