#include <iostream>

#include <vector>
#include <string>
#include <fstream>
using namespace std;

class KhachHang
{
protected:
    string hoten;
    string CCCD;
    string biensoxe;
    string nhucaudichvu;
    string ngaysudungdichvu;
    string giatiendichvu;
    string lichhentraxe;
    string phanhoikhachhang;

public:
    KhachHang(string hoten,
              string CCCD,
              string biensoxe,
              string nhucaudichvu,
              string ngaysudungdichvu,
              string giatiendichvu,
              string lichhentraxe,
              string phanhoikhachhang)
    {
        this->hoten = hoten;
        this->CCCD = CCCD;
        this->biensoxe = biensoxe;
        this->nhucaudichvu = nhucaudichvu;
        this->ngaysudungdichvu = ngaysudungdichvu;
        this->giatiendichvu = giatiendichvu;
        this->lichhentraxe = lichhentraxe;
        this->phanhoikhachhang = phanhoikhachhang;
    }
    //Ham khoi tao 
    KhachHang()
    {
        hoten = "0";
    }


    void nhapthongtin()
    {
        cin.ignore();
        cout << "1. Nhap ho va ten: ";
        getline(cin, hoten);
        cout << "2. Nhap CCCD: ";
        getline(cin, CCCD);
        cout << "3. Nhap bien so xe: ";
        getline(cin, biensoxe);
        cout << "4. Nhap nhu cau dich vu: ";
        getline(cin, nhucaudichvu);
        cout << "5. Nhap ngay su dung dich vu: ";
        getline(cin, ngaysudungdichvu);
        cout << "6. Nhap gia tien dich vu: ";
        getline(cin, giatiendichvu);
        cout << "7. Nhap lich hen tra xe: ";
        getline(cin, lichhentraxe);
        cout << "8. Nhap phan hoi khach hang: ";
        getline(cin, phanhoikhachhang);
        cin.ignore();
    }

    // ham hien thi thong tin
    void hienthithongtin()
    {
        cout << "Ho va ten: " << hoten << endl;
        cout << "CCCD: " << CCCD << endl;
        cout << "Bien so xe: " << biensoxe << endl;
        cout << "Nhu cau dich vu: " << nhucaudichvu << endl;
        cout << "Ngay su dung dich vu: " << ngaysudungdichvu << endl;
        cout << "Gia tien dich vu: " << giatiendichvu << endl;
        cout << "Lich hen tra xe: " << lichhentraxe << endl;
        cout << "Phan hoi khach hang: " << phanhoikhachhang << endl;
    }
    string getFullInfo()
    {
        string nl = "\n";
        return hoten + nl + CCCD + nl + biensoxe + nl + nhucaudichvu + nl + ngaysudungdichvu + nl + (giatiendichvu) + nl + lichhentraxe + nl + phanhoikhachhang;
    }
    string
    GetterHoten()
    {
        return this->hoten;
    }

    string
    GetterBienso()
    {
        return this->biensoxe;
    }
};

class TimKiemKhachHang : public KhachHang
{
public:
    static void Tim_Kiem_Thong_Tin_Danh_Sach_Theo_Ten(vector<KhachHang> &ds)
    {
        string ten;
        cin.ignore();
        cout << "\nMoi ban nhap ten can tim: ";
        getline(cin, ten);

        for (int i = 0; i < ds.size(); i++)
        {
            if (strcmp(ten.c_str(), ds[i].GetterHoten().c_str()) == 0)
            {
                ds[i].hienthithongtin();
            }
        }
        system("pause");
    }

    static void Tim_Kiem_Thong_Tin_Danh_Sach_Theo_Bienso(vector<KhachHang> &ds)
    {
        string bienso;
        cin.ignore();
        cout << "\nMoi ban nhap bien so can tim: ";
        getline(cin, bienso);

        for (int i = 0; i < ds.size(); i++)
        {
            if (strcmp(bienso.c_str(), ds[i].GetterBienso().c_str()) == 0)
            {
                ds[i].hienthithongtin();
                system("pause");
            }
        }
    }
    static void Cap_Nhat_Thong_Tin(vector<KhachHang> &ds)
    {
        string bienso;
        cout << "Nhap bien so xe de cap nhat thong tin: " << endl;
        cin.ignore();
        getline(cin, bienso);
        for (int i = 0; i < ds.size(); i++)
        {
            if (strcmp(bienso.c_str(), ds[i].GetterBienso().c_str()) == 0)
            {
                ds[i].nhapthongtin();

                system("pause");
                break;
            }
        }
        system("pause");
    }
    static void Xoa_Thong_Tin(vector<KhachHang> &ds)
    {
        string bienso;
        cout << "Nhap bien so xe de xoa thong tin: " << endl;
        cin.ignore();
        getline(cin, bienso);
        int vitrixoa = -1;
        for (int i = 0; i < ds.size(); i++)
        {
            if (strcmp(bienso.c_str(), ds[i].GetterBienso().c_str()) == 0)
            {
                vitrixoa = i;
                break;
            }
        }
        if (vitrixoa == -1)
            cout << "Khong tim duoc thong tin can xoa:" << endl;
        else
        {
            ds.erase(ds.begin() + vitrixoa);
        }
    }
};

// ham nhap thong tin cho danh sach khach hang
void Nhap_Thong_Tin_Danh_Sach(vector<KhachHang> &ds)
{
    KhachHang x;
    x.nhapthongtin();
    ds.push_back(x);
}

void Hien_Thi_Thong_Tin_Danh_Sach(vector<KhachHang> &ds)
{
    for (int i = 0; i < ds.size(); i++)
    {
        cout << "\n\tThong tin khach hang thu " << i + 1 << " : ";
        ds[i].hienthithongtin();
    }
     system("pause");
}
//Thiet lap menu
void Menu(vector<KhachHang> &ds)
{
    int luachon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t ============= QUAN LI =============";
        cout << "\n\t\t1. Nhap thong tin danh sach";
        cout << "\n\t\t2. Xuat thong tin danh sach";
        cout << "\n\t\t3. Tim kiem thong tin theo ten";
        cout << "\n\t\t4. Tim kiem thong tin theo bien so xe";
        cout << "\n\t\t5. Cap nhat thong tin";
        cout << "\n\t\t6. Xoa thong tin";
        cout << "\n\t\t7. Thoat chuong trinh va luu file";

        cout << "\nNhap lua chon:";
        cin >> luachon;

        if (luachon == 1)
        {
            Nhap_Thong_Tin_Danh_Sach(ds);
        }

        if (luachon == 2)
        {
            Hien_Thi_Thong_Tin_Danh_Sach(ds);
        }

        if (luachon == 3)
        {
            TimKiemKhachHang::Tim_Kiem_Thong_Tin_Danh_Sach_Theo_Ten(ds);
        }

        if (luachon == 4)
        {
            TimKiemKhachHang::Tim_Kiem_Thong_Tin_Danh_Sach_Theo_Bienso(ds);
        }
        if (luachon == 5)
        {
            TimKiemKhachHang::Cap_Nhat_Thong_Tin(ds);
        }
        if (luachon == 6)
        {
            TimKiemKhachHang::Xoa_Thong_Tin(ds);
        }
        if (luachon == 7)
        {
            return;
        }
    }
}
void Viet_Xuat_File(string file, vector<KhachHang> &ds)
{
    ofstream fileOutput(file);

    if (fileOutput.fail())
    {
        std::cout << " Khong the mo file  " << file << endl;
        return;
    }
    for (int i = 0; i < ds.size(); i++)
    {
        // fileOutput << "#" << i + 1 << endl;
        fileOutput << ds[i].getFullInfo();
        if (i != ds.size() - 1)
            fileOutput << "\n";
    }
}
void Doc_File(string file, vector<KhachHang> &ds)
{
    ifstream fileInput(file);

    if (fileInput.fail())
    {
        std::cout << " Khong the mo file  " << file << endl;
        return;
    }

    while (!fileInput.eof())
    {
        char hoten[255],
            CCCD[255],
            biensoxe[255],
            nhucaudichvu[255],
            ngaysudungdichvu[255],
            giatiendichvu[255],
            lichhentraxe[255],
            phanhoikhachhang[255];
        fileInput.getline(hoten, 255);
        // if (hoten[0] == '\n')
        //     break;
        fileInput.getline(CCCD, 255);
        fileInput.getline(biensoxe, 255);
        fileInput.getline(nhucaudichvu, 255);
        fileInput.getline(ngaysudungdichvu, 255);
        fileInput.getline(giatiendichvu, 255);
        fileInput.getline(lichhentraxe, 255);
        fileInput.getline(phanhoikhachhang, 255);
        string hten = hoten, cc = CCCD, bienso = biensoxe,
               nhucau = nhucaudichvu,
               ngaysudung = ngaysudungdichvu,
               lichtra = lichhentraxe,
               phanhoi = phanhoikhachhang,
               gt = giatiendichvu;
        KhachHang s(hten, cc, bienso, nhucau, ngaysudung, gt, lichtra, phanhoi);
        ds.push_back(s);
    }
}

int main()
{
// Duong xuat file o tai o dia D

	string filePath = "D:\\CheckQuanlykhachhang.txt";
    vector<KhachHang> ds;
    Doc_File(filePath, ds);
    Menu(ds);
    Viet_Xuat_File(filePath, ds);
    cout<<" Ban co the xem file code cpp o : https://github.com/ttvu77/ttv77 "<<endl;
    return 0;
}
