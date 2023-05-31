#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <fstream>
#include <ctime>
using namespace std;
int soban;
string time () 
{
    char *dt= new char[10];
    time_t now = time(0);
    dt = ctime(&now);
    string currentTime(dt);
    return currentTime;
};
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
    cout <<"========== THEM MON AN VAO MENU ==========\n";
	check.close();
	ofstream add;
	add.open("MENU.TXT", ios::app);
    while (somon > 0)
	{
        add << "\n     "<< somon +1<< " ";
        cout<<"\n \nNHAP TEN MON: ";
	    MENU::setTenmon();
	    add<<getTenmon();
	    cout<<"DA THEM MON: "<<getTenmon()<<"\n";
        cout<<"\n \nDO YOU WANT TO CONTINUE ?   (y/n)  ";
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
    savetofile << "---------- Thoi gian: "<<time();
    savetofile.close();
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"\n     NHAP SO THU TU VA SO LUONG MON AN \n\n";  
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
        cout<<"PRESS 1 TO CONTINUE --- PRESS 2 TO STOP: ";
        cin>>tap;
        if (tap == "1") 
           {
            cout<<"\n\n     NHAP SO THU TU VA SO LUONG MON AN \n";
            continue; 
            }
              else 
              {
                cout<<"STOP \n";
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
    cout<<"========== BAN: "<<soban<<" \n";
    Xuat_Order.open("XuatOrder.txt", ios::in);
    cout << "---------- Thoi gian: "<<time();
    cout<<"\n \nDANH SACH NHUNG MON AN DA CHON: \n";
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
