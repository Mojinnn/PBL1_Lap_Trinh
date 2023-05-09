#ifndef KHACHHANG_H
#define KHACHHANG_H

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
    char* getTen ();
    int getChieuCao ();
    int getTuoi ();
    long getGia ();
};

using namespace std;


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
    cout << "Vui long nhap chieu cao: ";
    cin >> chieucao;
}

void KhachHang::setTuoi () {
    cout << "Vui long nhap tuoi: ";
    cin >> tuoi;
}

char* KhachHang::getTen () {
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

#endif