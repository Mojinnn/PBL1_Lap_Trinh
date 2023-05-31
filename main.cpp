#include <iostream>
#include <fstream>
#include <ctime>
#include <string.h>
#include "KhachHang.h"
#include "ThanhToan.h"
#include "MENU_Order.cpp"

using namespace std;

//ham hien thi thoi gian
string ThoiGian () {
    time_t now = time(0);
    string currentTime = ctime(&now);
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

//khuyenmai
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
        file << "------ Thoi gian: "<< ThoiGian() << endl;
        for (int i = 0; i < soluong; i++) {
            file << "----------------------------------------" << endl;
            file << "SDT: " << kh[i].getSDT () << endl;
            file << "Tuoi: " << kh[i].getTuoi () << endl;
            file << "Chieu cao: " << kh[i].getChieuCao () << endl;
            file << "Ve: " << tt[i].getGiaVe () << endl;
            file << "Phi: " << tt[i].getPhi () << endl;
            file << "Thue: " << tt[i].getThue () << endl;
        }
        file << "--------------------------------------" << endl;
        file << "Khuyen Mai: " << KhuyenMai (kh, tt, soluong) << endl;
        file << "TONG TIEN: " << tt[soluong - 1].getTongTatCa () - KhuyenMai (kh, tt, soluong) << endl;
        file << "------------------------------------------------------------------" << endl;
    file.close();
}

void LICH_SU_BAN_HANG()
{
    string line;
    fstream Read;
    Read.open("LICHSUBANHANG.txt", ios::in);
    while (!Read.eof())
    {
        getline(Read, line);
        cout<<line<<"\n";
    }
    Read.close();
};

void MenuOrder (MENU *m, Order *d, int n, int a = 1) {
    while (a > 0) {
        cin>>n;
	    system("cls");
	    if (n==1) {  
            m->XemMenu();
            string nhan;
            cout<<"BAN: ";cin>>soban;
            while (soban < 1 || soban > 25) {
                cout<<"\nERROR! TRY AGAIN\n";
                cout<<"BAN: ";
                cin >> soban;
            };
            cout<<"\n\nPRESS ANY KEY TO ORDER ";
            cin>>nhan;
            d->ChonMenu();
            d->XuatOrder();
            break;
	    }
	    else if (n==2) {
            m->ThemMenu();
            break;
	    }
        else if(n==3) {
            LICH_SU_BAN_HANG(); 
        }
	    else {
            cout<<"ERROR! TRY AGAIN \n\n\n               1 -> XEM MENU \n\n               2 -> THEM MON AN VAO MENU \n\n               3 -> TRUY XUAT LICH SU BAN HANG\n\n";
        }
    };
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

    MENU *m = new MENU();
    Order *d = new Order();
	cout<<"=============== PRESS THE CORRECT NUMBER =============== \n\n\n               1 -> XEM MENU \n\n               2 -> THEM MON AN VAO MENU \n\n               3 -> TRUY XUAT LICH SU BAN HANG\n\n";
	
    int n;
    int a = 1;

    MenuOrder (m, d, n, a);

	delete m;
    delete d;

    delete [] kh;
    delete [] tt;

    return 0;
}