#include <iostream>
#include <ctime>
using namespace std;
int main ()
{
    char *dt= new char[10];
    time_t now = time(0);
    dt = ctime(&now);
    cout<<"Thoi diem hien tai la: "<<dt;
    return 0;

}