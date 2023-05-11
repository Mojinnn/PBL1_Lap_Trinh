#ifndef THANHTOAN_H
#define THANHTOAN_H

using namespace std;

class ThanhToan : public KhachHang {
    long gia;
    long thue;
    long phi;
    long tong;
public:
    void setGia();
    void setThue ();
    void setPhi ();
    void tinhTong ();
    long getGia ();
    long getThue ();
    long getPhi ();
    long ThanhTien ();
};

void ThanhToan::setGia () {
    gia = 0;
    if (KhachHang::getTuoi() <= 12) { // tre em duoi 12 tuoi
        if (KhachHang::getChieuCao() <= 120) {
            gia = 0; // duoi 1m2: mien phi
        }
        else if (KhachHang::getChieuCao() <= 150) {
            gia = 400000; // tren 1m2, duoi 1m5: 400k
        }
        else {
            gia = 450000; // tren 1m5: 450k
        }
    }
    else {
        gia = 500000; // nguoi lon: 500k
    }
}

void ThanhToan::setThue () {
    thue = (getGia()* 0.1);
}

void ThanhToan::setPhi () {
    cout << "Phi (neu co): ";
    cin >> phi;
}

void ThanhToan::tinhTong () {
    setGia ();
    setThue ();
    setPhi();
    tong = gia + thue + phi;
}

long ThanhToan::getGia () {
    return gia;
}

long ThanhToan::getPhi () {
    return phi;
}

long ThanhToan::getThue () {
    return thue;
}

long ThanhToan::ThanhTien () {
    tinhTong ();
    return tong;
}

#endif