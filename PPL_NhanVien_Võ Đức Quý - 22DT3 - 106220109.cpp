#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class NhanVien
{
private:
    string maSo;
    string hoTen;
    string chucVu;
    float heSoLuong;
    string sdt;

public:
    NhanVien() {}

    NhanVien(string maSo, string hoTen, string chucVu, float heSoLuong, string sdt)
    {
        this->maSo = maSo;
        this->hoTen = hoTen;
        this->chucVu = chucVu;
        this->heSoLuong = heSoLuong;
        this->sdt = sdt;
    }

    string getMaSo() const
    {
        return maSo;
    }

    string getHoTen() const
    {
        return hoTen;
    }

    string getChucVu() const
    {
        return chucVu;
    }

    float getHeSoLuong() const
    {
        return heSoLuong;
    }

    string getSDT() const
    {
        return sdt;
    }

    void nhapThongTin()
    {
        cout << "Nhap ma so: ";
        cin >> maSo;
        cin.ignore();

        cout << "Nhap ho ten: ";
        getline(cin, hoTen);

        cout << "Nhap chuc vu: ";
        getline(cin, chucVu);

        cout << "Nhap he so luong: ";
        cin >> heSoLuong;

        cout << "Nhap so dien thoai: ";
        cin.ignore();
        getline(cin, sdt);
    }

    void hienThiThongTin() const
    {
        cout << "Ma so: " << maSo << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Chuc vu: " << chucVu << endl;
        cout << "He so luong: " << heSoLuong << endl;
        cout << "So dien thoai: " << sdt << endl;
    }
};

void themNhanVien(vector<NhanVien> &danhSach)
{
    NhanVien nv;
    nv.nhapThongTin();
    danhSach.push_back(nv);
    cout << "Da them nhan vien!" << endl;
}

void capNhatNhanVien(vector<NhanVien> &danhSach)
{
    string maSo;
    cout << "Nhap ma so nhan vien can cap nhat: ";
    cin >> maSo;

    bool found = false;
    for (int i = 0; i < danhSach.size(); i++)
    {
        if (danhSach[i].getMaSo() == maSo)
        {
            danhSach[i].nhapThongTin();
            cout << "Da cap nhat thong tin nhan vien!" << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Khong tim thay nhan vien co ma so " << maSo << endl;
    }
}

void xoaNhanVien(vector<NhanVien> &danhSach)
{
    string maSo;
    cout << "Nhap ma so nhan vien can xoa: ";
    cin >> maSo;

    for (int i = 0; i < danhSach.size(); i++)
    {
        if (danhSach[i].getMaSo() == maSo)
        {
            danhSach.erase(danhSach.begin() + i);
            cout << "Da xoa nhan vien!" << endl;
            return;
        }
    }

    cout << "Khong tim thay nhan vien co ma so " << maSo << endl;
}

void timKiemNhanVien(vector<NhanVien> &danhSach)
{
    string maSo;
    cout << "Nhap ma so nhan vien can tim kiem: ";
    cin >> maSo;

    bool found = false;
    for (int i = 0; i < danhSach.size(); i++)
    {
        if (danhSach[i].getMaSo() == maSo)
        {
            danhSach[i].hienThiThongTin();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Khong tim thay nhan vien co ma so " << maSo << endl;
    }
}

void xuatDanhSachNhanVien(const vector<NhanVien> &danhSach)
{
    for (int i = 0; i < danhSach.size(); i++)
    {
        danhSach[i].hienThiThongTin();
        cout << "-----------------------" << endl;
    }
    system("pause");
}

void ghiDanhSachNhanVien(const vector<NhanVien> &danhSach, const string &tenFile)
{
    ofstream file(tenFile);

    if (file.is_open())
    {
        for (int i = 0; i < danhSach.size(); i++)
        {
            file << danhSach[i].getMaSo() << endl;
            file << danhSach[i].getHoTen() << endl;
            file << danhSach[i].getChucVu() << endl;
            file << danhSach[i].getHeSoLuong() << endl;
            file << danhSach[i].getSDT() << endl;
        }
        file.close();
        cout << "Da ghi danh sach nhan vien vao file " << tenFile << endl;
    }
    else
    {
        cout << "Khong the mo file " << tenFile << " de ghi!" << endl;
    }
    system("pause");
}

void docDanhSachNhanVien(vector<NhanVien> &danhSach, const string &tenFile)
{
    ifstream file(tenFile);

    if (file.is_open())
    {
        danhSach.clear();
        string maSo, hoTen, chucVu, sdt;
        float heSoLuong;

        while (getline(file, maSo))
        {
            getline(file, hoTen);
            getline(file, chucVu);
            file >> heSoLuong;
            file.ignore();
            getline(file, sdt);

            NhanVien nv(maSo, hoTen, chucVu, heSoLuong, sdt);
            danhSach.push_back(nv);
        }

        file.close();
        cout << "Da doc danh sach nhan vien tu file " << tenFile << endl;
    }
    else
    {
        cout << "Khong the mo file " << tenFile << " de doc!" << endl;
    }
}

int main()
{
    vector<NhanVien> danhSachNhanVien;
    string tenFile = "D:\\danhsachnhanvien.txt";

    docDanhSachNhanVien(danhSachNhanVien, tenFile);

    int choice;
    do
    {system("cls");
        cout << "----- QUAN LY NHAN VIEN -----" << endl;
        cout << "1. Them nhan vien" << endl;
        cout << "2. Cap nhat thong tin nhan vien" << endl;
        cout << "3. Xoa nhan vien" << endl;
        cout << "4. Tim kiem nhan vien" << endl;
        cout << "5. Xuat danh sach nhan vien" << endl;
        cout << "6. Ghi danh sach nhan vien vao file" << endl;
        cout << "0. Thoat" << endl;
        cout << "-----------------------------" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Cam on ban! Hen gap lai!" << endl;
            break;
        case 1:
            themNhanVien(danhSachNhanVien);
            break;
        case 2:
            capNhatNhanVien(danhSachNhanVien);
            break;
        case 3:
            xoaNhanVien(danhSachNhanVien);
            break;
        case 4:
            timKiemNhanVien(danhSachNhanVien);
            break;
        case 5:
            xuatDanhSachNhanVien(danhSachNhanVien);
            break;
        case 6:
            ghiDanhSachNhanVien(danhSachNhanVien, tenFile);
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}
