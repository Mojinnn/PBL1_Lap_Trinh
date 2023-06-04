# **PBL1: DỰ ÁN QUẢN LÝ NHÀ HÀNG BUFFET**
---
## **GIỚI THIỆU** 

Trong thời đại hiện nay, việc quản lý dữ liệu bằng các phương pháp thủ công đang dần trở lên lạc hậu và khó để kiểm soát, nhất là vào những giờ cao điểm, những ngày lễ. Đặc biệt là với một nhà hàng buffet, việc quản lý khách hàng, nguyên liệu, thức ăn là một điều khó khăn. Vì vậy, dựa trên những kiến thức từ các môn học nền tảng (Đại cương Kĩ thuật máy tính, Lập trình hướng đối tượng) và ngôn ngữ lập trình C++, chúng em đã xây dựng một chương trình quản lý đơn giản để dễ dàng trong việc order món ăn, lưu trữ thông tin khách hàng và thanh toán. Qua đó mang lại trải nghiệm tốt hơn cho khách hàng.
<br>Ở đây chúng em hướng dự án này đến các nhà hàng phục vụ theo hình thức buffet nhưng diện tích mặt bằng nhỏ. Mỗi đối tượng khách hàng sẽ có một mức giá vé khác nhau (dựa vào số tuổi và chiều cao) cùng với những khoản phí và thuế phát sinh, tuy nhiên vẫn có những ưu đãi, khuyến mãi cho khách hàng. Các món ăn sẽ được khách hàng chọn trên menu, sau đó nhà hàng chế biến ở trong bếp và phục vụ cho thực khách tại bàn (trừ nước uống và đồ tráng miệng).

---
## **CÁC TÍNH NĂNG CỦA CHƯƠNG TRÌNH**

### **1. ` Quản lý các món ăn`**
  - ***Hiển thị danh sách món ăn*** 
    ```c
    Hiển thị menu cho khách hàng lựa chọn đặt món
    ```
 - ***Thêm món ăn mới (nếu có)***
    ```c
    Hỗ trợ việc cập nhật thêm món mới vào menu khi nhà hàng phát triển thêm thực đơn  
    ```
### **2. `Quản lý đặt món`**
 - ***Đặt món***
    ```c
    Hỗ trợ khách hàng đặt món ngay tại bàn như chọn món ăn và số lượng từng món
    ```
 - ***Hiển thị thông tin đặt món***
    ```c
    In ra toàn bộ danh sách món ăn và số lượng mỗi món mà khách hàng đã chọn
    ```
### **3. `Quản lý khách hàng`**
 - ***Thông tin khách hàng***
   ```c
   Nhập thông tin khách hàng bao gồm: SĐT, tuổi, chiều cao để phân ra các mức vé khác nhau
   ```
 - ***Số lượng khách hàng***
   ```c
   Nhập số lượng khách cùng một nhóm để có những ưu đãi, khuyến mãi từ nhà hàng
   ```
### **4. `Quản lý doanh thu`**
- Lưu trữ doanh thu, lịch sử bán hàng
### **5. `Thanh toán`**
 - Xuất tổng hóa đơn sau khi cộng, trừ các khoảng thuế, phí và khuyến mãi
---
## **NGÔN NGỮ LẬP TRÌNH**
- Ngôn ngữ C++
---
## **THÔNG TIN THÀNH VIÊN NHÓM**
 - Trần Anh Toàn    -   MSSV: 106220237 - Lớp: 22KTMT1
 - Lê Thị Hải Yến - MSSV: 106220278 - Lớp: 22KTMT2
 - Bảng phân công nhiệm vụ:


|Tên  |Nhiệm vụ  |
|---------|---------|
|Trần Anh Toàn    |  - Đóng góp ý tưởng để thực hiện dự án <br>- Thực hiện các class KhachHang và ThanhToan      <br>- Liên kết class KhachHang và ThanhToan lại với nhau <br>- Thực hiện các hàm chức năng của chương trình<br>- Kiểm tra lỗi và sửa chương trình |
|Lê Thị Hải Yến     |- Đóng góp ý tưởng để thực hiện dự án<br>- Thực hiện các class Menu và Order<br>- Liên kết class Menu và Order lại với nhau<br>- Thực hiện các hàm chức năng của chương trình<br>- Kiểm tra lỗi và sửa chương trình       |
---
## **KẾT QUẢ CHẠY CHƯƠNG TRÌNH**
- Đầu tiên chương trình sẽ hỏi chức vụ 

![Picture1.png](https://github.com/Mojinnn/PBL1_Lap_Trinh/blob/master/Video/Picture1.png) 
- Nếu là `Thu ngân` sẽ có 3 sự lựa chọn. Nhập khác ba số trên, chương trình hiển thị "Loi! Thu lai"

![Picture2.png](https://github.com/Mojinnn/PBL1_Lap_Trinh/blob/master/Video/Picture2.png)
- Nếu chọn "Nhập thông tin khách hàng", chương trình yêu cầu nhập số lượng khách hàng và thông tin từng khách hàng

![Picture3.png](https://github.com/Mojinnn/PBL1_Lap_Trinh/blob/master/Video/Picture3.png)
- Nếu chọn "In hóa đơn", chương trình in ra màn hình tổng hóa đơn của thông tin nhập vào gần nhất

![Picture4.png](https://github.com/Mojinnn/PBL1_Lap_Trinh/blob/master/Video/Picture4.png)
- Nếu là `Phục vụ` sẽ có 4 sự lựa chọn. Nhập khác bốn số trên, chương trình hiển thị "Loi! Thu lai"

![Picture5.png](https://github.com/Mojinnn/PBL1_Lap_Trinh/blob/master/Video/Picture5.png)
- Nếu chọn "Xem Menu", chương trình in ra màn hình toàn bộ menu

![Picture6.png](https://github.com/Mojinnn/PBL1_Lap_Trinh/blob/master/Video/Picture6.png)
- Nhập số bàn để được thực hiện thao tác order

![Picture7.png](https://github.com/Mojinnn/PBL1_Lap_Trinh/blob/master/Video/Picture7.png)
- Chọn món và số lượng món

![Picture8.png](https://github.com/Mojinnn/PBL1_Lap_Trinh/blob/master/Video/Picture8.png)
- Nhấn `2` để dừng chọn món và xem danh sách các món đã chọn

![Picture9.png](https://github.com/Mojinnn/PBL1_Lap_Trinh/blob/master/Video/Picture9.png)
- Nếu chọn "Thêm món ăn vào menu", chương trình sẽ yêu cầu nhập tên món ăn mới

![Picture10.png](https://github.com/Mojinnn/PBL1_Lap_Trinh/blob/master/Video/Picture10.png)
- Sau khi nhập, chương trình xác nhận thêm thành công

![Picture11.png](https://github.com/Mojinnn/PBL1_Lap_Trinh/blob/master/Video/Picture11.png)
- Nếu chọn "Truy xuất lịch sử bán hàng", chương trình in ra màn hình toàn bộ dữ liệu bán hàng đã có

![Picture12.png](https://github.com/Mojinnn/PBL1_Lap_Trinh/blob/master/Video/Picture12.png)
- Nếu chọn `Kết thúc` ở bất kì lúc nào, chương trình sẽ ngừng ngay lập tức


Trần Anh Toàn<br>Lê Thị Hải Yến





 
