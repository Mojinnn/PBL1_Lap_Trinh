#include <iostream>
#include <string>
using namespace std;
class Order
{
 private:
    int soluong;
    static int somon;
    //friend class Kho;
public:
    void setSoluong (int);
    void setSomon(int);
    int getSomon() const;
    int getSoluong () const;
    void Menu();
    void ChonMenu ();
    int NhapSoluong();
};
void Order::setSoluong(int soluong)
    {
     this -> soluong = soluong;
    };
void Order::setSomon(int somon )
{
    this -> somon = somon;
};
int Order::getSoluong() const
{
    return soluong;
};
int Order::getSomon() const
{
    return somon; 
};
void Order::Menu()
 {
  cout<<"     MENU \n";
  cout<<"  Mon khai vi\n";
  cout<<"1. Salad Ceasar\n2. Salad Chicken\n3. Salad Napoli\n4. Salad Sorrento\n5. Khoai tay chien\n6. Ga vien chien\n7. Bap nuong bo\n8. Khoai lang nuong bo\n9. Dau hu chien gion\n10. Nam goi giay bac\n11. Rong bien nuong gion\n12. Nam dong co bo toi\n";
  cout<<"  Cac loai sot\n";
  cout<<"13. Sot King BBQ\n14. Sot cay\n15. Sot Guang Yang\n16. Sot thit Han Quoc\n17. Sot toi\n18. Sot dac biet\n19. Sot oi chuong do\n";
  cout<<"  Nuong\n";
  cout<<"20. Bap bo\n21. Ba chi bo\n22. Than vai bo\n23. Than lung bo\n24. Co bo My\n25. Gau bo My\n26. De suon bo\n27. Suon bo\n28. Ba chi bo\n29. Bo uop cay\n30. Bo cuon pho mai\n31. Bo cuon nam kim cham\n32. Bo xien rau cu\n33. Suon heo\n34. Ma heo\n35. Ba chi heo\n36. Nac dam\n37. Nam heo uop sa te\n38. Canh ga uop ngu vi\n39. Dui ga uop chao\n40. Thit dui ga cuon la dua\n41. Ma heo uop Miso\n42. Hau nuong mo hanh\n43. Tom the\n44. Bach tuoc\n45. Muc ong sot muoi ot\n46. Ca basa nuong giay bac\n47. So diep bo toi\n48. Hau nuong pho mai\n49. Ca bo da nuong muoi ot\n50. Muc la uop sa te\n51. Tom muoi ot\n52. Ca hoi giay bac\n53. Tom hum bo toi\n54. Tom hum pho mai\n";
  cout<<"  Lau\n";
  cout<<"55. Lau thai Tomyum\n56. Lau Kimchi\n57. Lau Bulgogi\n";
  cout<<"  Mon truyen thong\n";
  cout<<"58. Canh gan bo Han Quoc\n59. Canh suon bo\n60. Canh kim chi\n61. Com tron\n62. Canh rong bien\n63. Canh bo om cay\n64. Bap nuong pho mai\n";
};
void Order::ChonMenu()
{   string order, tap = " ";
    int n = 1;
    cout<<"Vui long chon mon an va so luong \n";  
   while ( n <= somon)  
    {   
        cin >> n;
        switch (n)
     {
        case 1: order = "1. Salad Ceasar ";
                break;
        case 2: order = "2. Salad Chicken ";
                break;
        case 3: order = "3. Salad Napoli ";
                break;
        case 4: order = "4. Salad Sorrento ";
                break;  
        case 5:  order = "5. Khoai tay chien ";
                break;
        case 6:  order = "6. Ga vien chien ";
                break;
        case 7:  order = "7. Bap nuong bo ";
                break;
        case 8:  order = "8. Khoai lang nuong bo ";
                break;
        case 9:  order = "9. Dau hu chien gion ";
                break;
        case 10:  order = "10. Nam goi giay bac ";
                break;
        case 11:  order = "11. Rong bien nuong gion ";
                break;
        case 12:  order = "12. Nam dong co bo toi ";
                break;
        case 13:  order = "13. Sot King BBQ ";
                break;
        case 14:  order = "14. Sot cay ";
                break;
        case 15:  order = "15. Sot Guang Yang ";
                break;
        case 16:  order = "16. Sot thit Han Quoc ";
                break;
        case 17:  order = "17. Sot toi ";
                break;
        case 18:  order = "18. Sot dac biet ";
                break;
        case 19:  order = "19. Sot oi chuong do ";
                break;
        case 20:  order = "20. Bap bo ";
                break;
        case 21:  order = "21. Ba chi bo ";
                break;
        case 22:  order = "22. Than vai bo ";
                break;
        case 23:  order = "23. Than lung bo ";
                break;
        case 24:  order = "24. Co bo My ";
                break;
        case 25:  order = "25. Gau bo My ";
                break;
        case 26:  order = "26. De suon bo ";
                break;
        case 27:  order = "27. Suon bo ";
                break;
        case 28:  order = "28. Ba chi bo ";
                break;
        case 29:  order = "29. Bo uop cay ";
                break;
        case 30:  order = "30. Bo cuon pho mai ";
                break;
        case 31:  order = "31. Bo cuon nam kim cham ";
                break;
        case 32:  order = "32. Bo xien rau cu ";
                break;
        case 33:  order = "33. Suon heo ";
                break;
        case 34:  order = "34. Ma heo ";
                break;
        case 35:  order = "35. Ba chi heo ";
                break;
        case 36:  order = "36. Nac dam ";
                break;
        case 37:  order = "37. Nam heo uop sa te ";
                break;
        case 38:  order = "38. Canh ga uop ngu vi ";
                break;
        case 39:  order = "39. Dui ga uop chao ";
                break;
        case 40:  order = "40. Thit dui ga cuon la dua ";
                break;
        case 41:  order = "41. Ma heo uop Miso ";
                break;
        case 42:  order = "42. Hau nuong mo hanh ";
                break;
        case 43:  order = "43. Tom the ";
                break;
        case 44:  order = "44. Bach tuoc ";
                break;
        case 45:  order = "45. Muc ong sot muoi ot ";
                break;
        case 46:  order = "46. Ca basa nuong giay bac ";
                break;
        case 47:  order = "47. So diep bo toi ";
                break;
        case 48:  order = "48. Hau nuong pho mai ";
                break;
        case 49:  order = "49. Ca bo da nuong muoi ot ";
                break;
        case 50:  order = "50. Muc la uop sa te ";
                break;
        case 51:  order = "51. Tom muoi ot ";
                break;
        case 52:  order = "52. Ca hoi giay bac ";
                break;
        case 53:  order = "53. Tom hum bo toi ";
                break;
        case 54:  order = "54. Tom hum pho mai ";
                break;
        case 55:  order = "55. Lau thai Tomyum ";
                break;
        case 56:  order = "56. Lau Kimchi ";
                break;
        case 57:  order = "57. Lau Bulgogi ";
                break;
        case 58:  order = "58. Canh gan bo Han Quoc ";
                break;
        case 59:  order = "59. Canh suon bo ";
                break;
        case 60:  order = "60. Canh kim chi ";
                break;
        case 61:  order = "61. Com tron ";
                break;
        case 62:  order = "62. Canh rong bien ";
                break;
        case 63:  order = "63. Canh bo om cay ";
                break;
        case 64:  order = "64. Bap nuong pho mai ";
                break;
        default: break;              
     };
        Order::NhapSoluong();
        cout<<order<<" x " << Order::soluong<<"\n";
        cout<<"Nhan y de tiep tuc \nNhan n de dung lai\n";
        cin>>tap;
        if (tap == "y") 
           {
             continue;
           }
           else {
                  break;
                };
    }
};
int Order::NhapSoluong()
  {
   cin>>soluong;
   return soluong;
  }
int Order::somon = 64;
int main()
{
//Xem xong menu, nhấn n để xóa sạch màn hình để order món ăn
    Order k1;
    k1.Menu();
    string nhan;
    cout<<"\n\nNhan n de order mon";
    cin>>nhan;
       if (nhan == "n")
           {
             system("cls");
           };
//Chon mon
    k1.ChonMenu();
    return 0;
}