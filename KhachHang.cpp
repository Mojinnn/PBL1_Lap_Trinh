#include <iostream>
#include <string.h>

using namespace std;

class KhachHang {
    char* ten;
    int chieucao;
    int tuoi;
    long gia;
public:
    ~KhachHang ();
    void setTen ();
    void setChieuCao ();
    void setTuoi ();
    string getTen ();
    int getChieuCao ();
    int getTuoi ();
    long getGia ();
};

KhachHang::~KhachHang () {
    delete [] ten;
}

void KhachHang::setTen () {
    char* name;
    name = new char [50];
    cout << "Nhap ten: ";
    cin.ignore ();
    cin.getline (name, 50);
    ten = new char [strlen(name) + 1];
    strcpy (ten, name);
    delete [] name;
}

void KhachHang::setChieuCao () {
    int height;
    cout << "Vui long nhap chieu cao: ";
    cin >> height;
    chieucao = height;
}

void KhachHang::setTuoi () {
    int age;
    cout << "Vui long nhap tuoi: ";
    cin >> age;
    tuoi = age;
}

string KhachHang::getTen () {
    return ten;
}

int KhachHang::getChieuCao () {
    return chieucao;
}

int KhachHang::getTuoi () {
    return tuoi;
}

long KhachHang::getGia () {
    if (tuoi <= 12) { // tre em duoi 12 tuoi
        if (chieucao <= 120) {
            gia = 0; // duoi 1m2: mien phi
        }
        else if (chieucao <= 150) {
            gia = 120000; // tren 1m2, duoi 1m5: 120k
        }
        else {
            gia = 180000; // tren 1m5: 180k
        }
    }
    else {
        gia = 200000; // nguoi lon: 200k
    }
    return gia;
}

void NhapThongTin (KhachHang &kh) {
    cout << "-------Nhap Thong Tin Khach Hang-------" << endl;
    kh.setTen ();
    kh.setTuoi ();
    kh.setChieuCao ();
}

void XuatThongTin (KhachHang &kh) {
    cout << "-------Thong Tin Khach Hang-------" << endl;
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

    return 0;
}