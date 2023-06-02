#ifndef KHACHHANG_H
#define KHACHHANG_H

using namespace std;

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

#endif