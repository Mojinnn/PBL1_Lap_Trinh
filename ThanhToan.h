#ifndef THANHTOAN_H
#define THANHTOAN_H

using namespace std;

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

#endif