#include <iostream>
using namespace std;

class GiaVe {
    int chieucao;
    int tuoi;
    long gia;
public:
    void setChieuCao (int chieucao);
    void setTuoi (int tuoi);
    int getChieuCao ();
    int getTuoi ();
    long gia ();
}

void GiaVe::setChieuCao (int chieucao) {
    cout << "Vui long nhap chieu cao" << endl;
    this chieucao -> chieucao;
}

void GiaVe::setTuoi (int tuoi) {
    cout << "Vui long nhap tuoi" << endl;
    this tuoi -> tuoi;
}

int GiaVe::getChieuCao () {
    return chieucao;
}

int GiaVe::getTuoi () {
    return tuoi;
}

long GiaVe::gia () {
    if (tuoi < 12) { // tre em duoi 12 tuoi
        if (chieucao < 120) {
            gia = 0; // duoi 1m2: mien phi
        }
        if (chieucao > 120 && chieucao < 150) {
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