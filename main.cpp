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
void GhiHoaDon (KhachHang *kh, ThanhToan *tt, int &soluong) {
    ofstream file;
    file.open("HoaDon.txt", ios::trunc);
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

void DocHoaDonVaGhiDoanhThu () {
    string line;
    ifstream file;
    file.open("HoaDon.txt", ios::in);
        cout << "------ Thoi gian: "<< ThoiGian() << endl;
        while (!file.eof()) {
            getline (file, line);
            cout << line << endl;
            ofstream doanhthu;
            doanhthu.open ("doanhthu.txt", ios::app);
                doanhthu << line << endl;
            doanhthu.close ();
        }
    file.close();
}

void ThuNgan (KhachHang *kh, ThanhToan *tt) {
    int soluong;
    int n;
    int a = 1;
    while (a > 0) {
        cout << "=============== Chuc nang cua ban =============== \n\n\n               1 -> Nhap thong tin khach hang \n\n               2 -> In hoa don \n\n               3 -> Ket thuc\n\n";
        cout << "Ban muon lam gi: ";
        cin >> n;
        if (n == 1) {
            cout << "Nhap so luong khach hang: ";
            cin >> soluong;
            kh = new KhachHang [soluong];
            tt = new ThanhToan [soluong];
            NhapThongTin (kh, tt, soluong);
            XuatThongTin (kh, tt, soluong);
            GhiHoaDon (kh, tt, soluong);
        }
        else if (n == 2) {
            DocHoaDonVaGhiDoanhThu ();
        }
        else if (n == 3) {
            break;
        }
        else {
            cout << "Loi! Thu lai \n\n\n               1 -> Nhap thong tin khach hang va tinh tien \n\n               2 -> In hoa don ban hang \n\n               3 -> Ket thuc\n\n";
        }
    }
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

void PhucVu (MENU *m, Order *d) {
    int n;
    int a = 1;
    while (a > 0) {
        cout<<"=============== Chuc nang cua ban =============== \n\n\n               1 -> Xem Menu \n\n               2 -> Them mon an vao menu \n\n               3 -> Truy xuat lich su ban hang\n\n               4 -> Ket thuc\n\n";
        cout << "Ban muon lam gi: ";
        cin>>n;
	    system("cls");
	    if (n==1) {  
            m->XemMenu();
            string nhan;
            cout<<"Ban: ";cin>>soban;
            while (soban < 1 || soban > 25) {
                cout<<"\nLoi! Thu lai\n";
                cout<<"Ban: ";
                cin >> soban;
            };
            cout<<"\n\nNhan phim bat ky de order: ";
            cin>>nhan;
            d->ChonMenu();
            d->XuatOrder();
	    }
	    else if (n==2) {
            m->ThemMenu();
            
	    }
        else if(n==3) {
            LICH_SU_BAN_HANG(); 
        }
        else if (n == 4) {
            break;
        }
	    else {
            cout<<"Loi! Thu lai \n\n\n               1 -> Xem Menu \n\n               2 -> Them mon an vao menu \n\n               3 -> Truy xuat lich su ban hang\n\n               4 -> Ket thuc\n\n";
        }
    };
}

//ham main
int main () {
    int chucvu;
    KhachHang *kh;
    ThanhToan *tt;
    MENU *m;
    Order *d;
    

    cout << "=============== Chuc Vu =============== \n\n\n               1 -> Thu Ngan \n\n               2 -> Phuc Vu \n\n";
    cout << "Chuc vu cua ban la: ";
    cin >> chucvu;

    system("cls");
    if (chucvu == 1) {
        ThuNgan (kh, tt);
    }
    else if (chucvu == 2) {
        m = new MENU ();
        d = new Order ();
    
        PhucVu (m, d);
    }

	delete m;
    delete d;

    delete [] kh;
    delete [] tt;

    return 0;
}