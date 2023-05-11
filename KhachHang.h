#ifndef KHACHHANG_H
#define KHACHHANG_H

using namespace std;

class KhachHang {
    char* ten;
    int chieucao;
    int tuoi;
public:
    ~KhachHang ();
    void setTen ();
    void setChieuCao ();
    void setTuoi ();
    char* getTen ();
    int getChieuCao ();
    int getTuoi ();
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

#endif