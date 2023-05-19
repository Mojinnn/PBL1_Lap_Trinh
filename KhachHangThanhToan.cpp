#include <iostream>
#include <string.h>
#include <fstream>
#include <ctime>

using namespace std;

//class KhachHang
class KhachHang {
    string SDT;
    int chieucao;
    int tuoi;
public:
    void setSDT ();
    void setChieuCao ();
    void setTuoi ();
    const string getSDT () const;
    const int getChieuCao () const;
    const int getTuoi () const;
    friend void setGiaVe (const KhachHang &kh);
};

void KhachHang::setSDT () {
    do {
        cout << "Nhap SDT: ";
        cin >> SDT;
    } while (SDT.length() != 10);
}

void KhachHang::setChieuCao () {
    cout << "Vui long nhap chieu cao: ";
    cin >> chieucao;
}

void KhachHang::setTuoi () {
    cout << "Vui long nhap tuoi: ";
    cin >> tuoi;
}

const string KhachHang::getSDT () const {
    return SDT;
}

const int KhachHang::getChieuCao () const {
    return chieucao;
}

const int KhachHang::getTuoi () const {
    return tuoi;
} 

//class ThanhToan
class ThanhToan {
    long giave;
    long thue;
    long phi;
public:
    void setPhi ();
    void setGiaVe (const KhachHang& kh);
    const long getGiaVe () const;
    const long getThue () const;
    const long getPhi () const;
    const long ThanhTien () const;
};

void ThanhToan::setPhi () {
    cout << "Phi (neu co): ";
    cin >> phi;
}

void ThanhToan::setGiaVe (const KhachHang &kh) {
    if (kh.getTuoi() <= 12) { // tre em duoi 12 tuoi
        if (kh.getChieuCao() <= 120) {
            giave = 0; // duoi 1m2: mien phi
        }
        else if (kh.getChieuCao() <= 150) {
            giave = 400000; // tren 1m2, duoi 1m5: 400k
        }
        else {
            giave = 450000; // tren 1m5: 450k
        }
    }
    else {
        giave = 500000; // nguoi lon: 500k
    }
}

const long ThanhToan::getGiaVe () const {
    return giave;
}

const long ThanhToan::getThue () const {
    return (getGiaVe()* 0.1);
}

const long ThanhToan::getPhi () const {
    return phi;
}


const long ThanhToan::ThanhTien () const {
    return (getGiaVe () + getThue () + getPhi ());
}

//ham Nhap thong tin tung doi tuong
void NhapThongTin (KhachHang &kh, ThanhToan &tt) {
    cout << "-------Nhap Thong Tin Khach Hang-------" << endl;
    kh.setSDT ();
    kh.setTuoi ();
    kh.setChieuCao ();
    tt.setGiaVe (kh);
    tt.setPhi ();
}

//ham Xuat thong tin doi tuong
void XuatThongTin (KhachHang &kh, ThanhToan &tt) {
    cout << "--------------------------------------" << endl;
    cout << "SDT: " << kh.getSDT () << endl;
    cout << "Tuoi: " << kh.getTuoi () << endl;
    cout << "Chieu cao: " << kh.getChieuCao () << endl;
    cout << "Ve: " << tt.getGiaVe () << endl;
    cout << "Phi: " << tt.getPhi () << endl;
    cout << "Thue: " << tt.getThue () << endl;
    cout << "Tong Tien: " << tt.ThanhTien () << endl;
}

string ThoiGian () {
    char *dt= new char[10];
    time_t now = time(0);
    dt = ctime(&now);
    string currentTime(dt);
    return currentTime;
}

//ham ghi file
void GhiFile (KhachHang &kh, ThanhToan &tt) {
    ofstream file;
    file.open("HoaDon.txt", ios::app);        
        file << "----------------------------------------" << endl;
        file << "------ Thoi gian: "<< ThoiGian() << endl;
        file << "SDT: " << kh.getSDT () << endl;
        file << "Tuoi: " << kh.getTuoi () << endl;
        file << "Chieu cao: " << kh.getChieuCao () << endl;
        file << "Ve: " << tt.getGiaVe () << endl;
        file << "Phi: " << tt.getPhi () << endl;
        file << "Thue: " << tt.getThue () << endl;
        file << "Tong Tien: " << tt.ThanhTien () << endl;
        file << endl;
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

    for (int i = 0; i < soluong; i++) {
        NhapThongTin (kh[i], tt[i]);
    }

    for (int i = 0; i < soluong; i++) {
        XuatThongTin (kh[i], tt[i]);
    }

    for (int i = 0; i < soluong; i++) {
        GhiFile (kh[i], tt[i]);
    }

    delete [] kh;
    delete [] tt;

    return 0;
}
