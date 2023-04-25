#include <iostream>
#include "GiaVe.cpp"
using namespace std;

class HoaDon {
    friend class GiaVe;
    long thueVAT;
    long phi;
public:
    void setThueVAT ();
    void setPhi (int phi);
    long getThueVAT ();
    long getPhi ();
    long ThanhTien ();
};

void HoaDon::setThueVAT () {
    thueVAT = (GiaVe::gia())*(10/100);
}

void HoaDon::setPhi (int phi) {
    this -> phi = phi;
}

long HoaDon::getPhi () {
    return phi;
}

long HoaDon::getThueVAT () {
    return thueVAT;
}

long HoaDon::ThanhTien () {
    return (GiaVe::gia() + phi + thueVAT);
}
