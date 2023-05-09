#ifndef KHACHHANG_H
#define KHACHHANG_H

class ThanhToan : public KhachHang {
    long thueVAT;
    long phi;
public:
    void setThueVAT ();
    void setPhi ();
    long getThueVAT ();
    long getPhi ();
    long ThanhTien ();
};

using namespace std;

void ThanhToan::setThueVAT () {
    thueVAT = (KhachHang::getGia())*(10/100);
}

void ThanhToan::setPhi () {
    cout << "Phi (neu co): ";
    cin >> phi;
}

long ThanhToan::getPhi () {
    return phi;
}

long ThanhToan::getThueVAT () {
    return thueVAT;
}

long ThanhToan::ThanhTien () {
    return (KhachHang::getGia() + phi + thueVAT);
}

#endif