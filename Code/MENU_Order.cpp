#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <fstream>
#include <ctime>
using namespace std;
int soban;

//ham hien thi thoi gian
string ThoiGian () {
    time_t now = time(0);
    string currentTime = ctime(&now);
    return currentTime;
}

class MENU
{
    private:
     string tenmon ;
     static int somon;
    public:
    void setTenmon() ;
    const string getTenmon() const;
    void ThemMenu();
    void XemMenu();
};
int MENU::somon =0;
void MENU::setTenmon()
{
    cin.ignore();
    getline(cin, tenmon);
};
const string MENU::getTenmon() const
{
    return tenmon;
};
void MENU::ThemMenu()
{
    string line,tap;
	int stt = 0;
	ifstream check;
	check.open("MENU.TXT", ios::in);
	while (!check.eof())
	{
		getline(check, line);
		stt++;
	};
	somon = stt -14;
    cout <<"========== Them mon an vao Menu ==========\n";
	check.close();
	ofstream add;
	add.open("MENU.TXT", ios::app);
    while (somon > 0)
	{
        add << "\n     "<< somon +1<< " ";
        cout<<"\n \nNhap ten mon: ";
	    MENU::setTenmon();
	    add<<getTenmon();
	    cout<<"Da them mon: "<<getTenmon()<<"\n";
        cout<<"\n \nBan co muon tiep tuc ?   (y/n)  ";
        cin >> tap;
            if (tap == "y") 
               {
                 continue;
               }
               else 
               {
                cout<<"\n\n";
                break;
               };      
	    add.close();
    };
};
void MENU::XemMenu()
{   
    string line;
    fstream MenuOut;
    MenuOut.open("MENU.TXT", ios_base:: in);
    while (!MenuOut.eof())
     {
        getline (MenuOut, line) ;
        cout << line << "\n";
     };
    MenuOut.close();
    cout<<"\n============================================================================================================================================================\n";
};
class Order
{
 private:
    int soluong;
public:
    void setSoluong (int);
    int getSoluong () const;
    void ChonMenu ();
    int NhapSoluong();
    void XuatOrder();
};
void Order::setSoluong(int soluong)
{
     this -> soluong = soluong;
};
int Order::getSoluong() const
{
    return soluong;
};
int Order::NhapSoluong()
{
   cin>>soluong;
   return soluong;
};
void Order::ChonMenu()
{   
    string tenmon, sothutu, nhap, tap ;
    int n = 1;
    fstream savetofile;
    savetofile.open("LICHSUBANHANG.txt", ios::app);
    savetofile<<"========== BAN: "<<soban<<" \n";
    savetofile << "---------- Thoi gian: "<< ThoiGian();
    savetofile.close();
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"\n     Nhap so thu tu va so luong mon an \n\n";  
    while ( n > 0)
      {
        fstream Read;
        Read.open("MENU.TXT", ios_base::in);
        cout<<"\n";
        cin >> nhap;
        while (!Read.eof())
            {  
                Read >> sothutu;
               {if(sothutu == nhap)
                 {
                    getline (Read,tenmon);
                    Read.close();
                 };
               };
            };
        Order::NhapSoluong();
        cout<<"\n "<<tenmon<<" x " << getSoluong() <<"\n \n";
        fstream save;
        save.open("LICHSUBANHANG.txt", ios_base::app);
        save << tenmon << " x "<< getSoluong() << "\n";
        save.close();
        fstream Xuat_Order;
        Xuat_Order.open("XuatOrder.txt", ios::app);
        Xuat_Order << tenmon << " x "<< getSoluong() << "\n";
        Xuat_Order.close();
        cout<<"Nhan 1 de tiep tuc --- Nhan 2 de dung lai: ";
        cin>>tap;
        if (tap == "1") 
           {
            cout<<"\n\n     Nhap so thu tu va so luong mon an \n";
            continue; 
            }
              else 
              {
                cout<<"Dung \n";
                break;
              };                
 };
   fstream savetof;
   savetof.open("LICHSUBANHANG.txt", ios::app);
   savetof << "------------------------------------------------\n"; 
};
void Order::XuatOrder()
{
    string line;
    system("cls");
    fstream Xuat_Order;
    cout<<"========== Ban: "<<soban<<" \n";
    Xuat_Order.open("XuatOrder.txt", ios::in);
    cout << "---------- Thoi gian: "<< ThoiGian();
    cout<<"\n \nDanh sach mon an da chon: \n";
    while (!Xuat_Order.eof())
    {
    getline(Xuat_Order, line);
    cout << line <<"\n";
    };
    Xuat_Order.close();
    fstream Cls;
    Cls.open("XuatOrder.txt", ios::out|ios::trunc);
    Cls.close();
};
