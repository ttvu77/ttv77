#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
using namespace std;
class User{
protected:
    string Username;
    string Password;
    string Name;
    string Address;
    string Phone;
    string Email;
public:
    string getUsername() { return Username; }
    string getPassword() { return Password; }
    string getName() { return Name; }
    string getAddress() { return Address; }
    string getPhone() { return Phone; }
    string getEmail() { return Email; }
    void setUsername(string _Username) { Username = _Username; }
    void setPassword(string _Password) { Password = _Password; }
    void setName(string _Name) { Name = _Name; }
    void setAddress(string _Address) { Address = _Address; }
    void setPhone(string _Phone) { Name = _Phone; }
    void setEmail(string _Email) { Name = _Email; }
    User(string _Username = "", string _Password = "111111", string _Name = "", string _Address = "", string _Phone = "", string _Email = "")
    {
        Username = _Username;
        Password = _Password;
        Name = _Name;
        Address = _Address;
        Phone = _Phone;
        Email = _Email;
    }
    User(const User& u) {
        Username = u.Username;
        Password = u.Password;
        Name = u.Name;
        Address = u.Address;
        Phone = u.Phone;
        Email = u.Email;
    }
    ~User() {}
    virtual void ReadFile(ifstream& FileIn) {
        getline(FileIn, Username, ',');
        getline(FileIn, Password);
    }
    virtual void CreateFile(ofstream& FileOut, char*& FileName) {
        string str = (string)FileName;
        string strFile = "d:\\" + str + ".TXT";
        FileName = new char[strFile.length() + 1];
        strcpy(FileName, strFile.c_str());
        if (FileName != NULL)
        {
            FileOut.open(FileName, ios_base::out);
        }
        delete[] FileName;
    }
    virtual void OpenFile(ifstream& FileIn, char*& FileName) {
        string str = (string)FileName;
        string strFile = "d:\\" + str + ".TXT";
        FileName = new char[strFile.length() + 1];
        strcpy(FileName, strFile.c_str());
        if (FileName != NULL)
            FileIn.open(FileName, ios_base::in);
        delete[] FileName;
    }
    virtual void ReadInfomation(ifstream& FileIn) {
        getline(FileIn, Name);
        getline(FileIn, Address);
        getline(FileIn, Phone);
        getline(FileIn, Email);
    }
    virtual void DeleteFile(string FileName) {
        char c = 34;
        string Del = "del ";
        string FilePath1 = "d:\\";
        string FilePath2 = ".txt";
        string strDel = c + Del + FilePath1 + FileName + FilePath2 + c;
        char* ChuoiXoa = new char[strDel.length() + 1];
        strcpy(ChuoiXoa, strDel.c_str());
        system(ChuoiXoa);
    }
    virtual void Input() {
        cin.ignore(); 
        cout << " Nhap thong tin ca nhan " << endl;
        cout << " Ho ten : ";
        getline(cin, Name);
        cout << " Dia chi: ";     
        getline(cin, Address);       
        cout << " So dien thoai: ";  
        getline(cin, Phone);    
        cout << " Dia chi Email: ";    
        getline(cin, Email);
    }
};

class Administrators : public User{
public:
    void ReadFile(ifstream& FileIn) {
        User::ReadFile(FileIn);
    }
    void CreateFile(ofstream& FileOut, char* FileName) {
        User::CreateFile(FileOut, FileName);
    }
    bool operator ==(Administrators a) {
        return a.getUsername() + a.getPassword() == getUsername() + getPassword();
    }
    Administrators(string _Username = "", string _Password = "111111", string _Name = "", string _Address = "", string _Phone = "", string _Email = "")
        :User(_Username, _Password, _Name, _Address, _Phone, _Password) {}
};
class Employees : public User{
public:
    void ReadFile(ifstream& FileIn) {
        User::ReadFile(FileIn);
    }
    void Input() {
        User::Input();
    }
    void CreateFile(ofstream& FileOut, char* FileName) {
        User::CreateFile(FileOut, FileName);
    }
    bool operator ==(Employees a) {
        return a.getUsername() + a.getPassword() == getUsername() + getPassword();
    }
    Employees(string _Username = "", string _Password = "111111", string _Name = "", string _Address = "", string _Phone = "", string _Email = "")
        :User(_Username, _Password, _Name, _Address, _Phone, _Password) {}
};
void DangNhapAdmin(){
    cout << "\t****************************" << endl;
    cout << "\t*    ";  
    cout << " DANG NHAP ADMIN      ";
    cout << "*" << endl;
    cout << "\t****************************" << endl;
}
void MenuAdmin(){  
    cout << "\t************ MENU ADMIN ************" << endl;
    cout << "\t    1. Them Employee                " << endl;
    cout << "\t    2. Xoa Employee                 " << endl;
    cout << "\t    3. Tim Employee                 " << endl;
    cout << "\t    4. Cap nhat Employee            " << endl;
    cout << "\t    5. Hien thi thong tin Employee  " << endl;
    cout << "\t    6. Thoat                        " << endl;
    cout << "\t************************************" << endl;
}
std::string passwordInput(unsigned maxLength)
{
    std::string pw;
    for (char c; (c = getch()); )
    {
        if (c == '\n' || c == '\r') { 
            std::cout << "\n";
            break;
        }
        else if (c == '\b') { 
            std::cout << "\b \b";
            if (!pw.empty()) pw.erase(pw.size() - 1);
        }
        else if (c == -32) { 
            _getch(); 
        }
        else if (isprint(c) && pw.size() < maxLength) { 
            std::cout << '*';
            pw += c;
        }
    }
    return pw;
}
void Login(string& TaiKhoan,string& MatKhau){
    cout << "\tUser:     ";
    cin >> TaiKhoan;
    char x = 'l';
    int size = 0;
    cout << endl;

    cout << "\tPin:     ";
    MatKhau = passwordInput(15);
    cout << endl;
}
bool DangNhapThanhCong(User* x, char* FilePath, string& SaveUsername) {
    ifstream FileIn;
    FileIn.open(FilePath, ios_base::in);
    string TaiKhoan;
    string MatKhau;
    Login(TaiKhoan, MatKhau);
    while (!FileIn.eof())
    {
        x = new User();
        x->ReadFile(FileIn);
        if (x->getUsername() + x->getPassword() == TaiKhoan + " " + MatKhau) {
            SaveUsername = TaiKhoan;
            return true;
        }
    }
    FileIn.close();
    return false;
}
bool KiemTraUsernameEmployee(User* x, string _User){
    ifstream FileIn;
    FileIn.open("d:\\Employees.txt", ios_base::in);
    while (!FileIn.eof())
    {
        x = new Employees();
        x->ReadFile(FileIn);
        if (_User == x->getUsername())
            return false;
    }
    FileIn.close();
    return true;
}
void ThemEmployee(User* x){
    string _User, _Pass;
    cout << " Nhap Username muon them: ";
    cin >> _User;
    if (KiemTraUsernameEmployee(x, _User) == true)
    {
        char* FilePath = new char[_User.length() + 1];
        strcpy(FilePath, _User.c_str());
        ofstream FileOut;
        Employees* Emp = new Employees();
        FileOut.open("d:\\Employees.TXT", ios_base::app);
        FileOut << endl << _User << ", " << "111111";
        FileOut.close();
        Emp->CreateFile(FileOut, FilePath);
        Emp->Input();
        FileOut << Emp->getName() << endl << Emp->getAddress() << endl << Emp->getPhone() << endl << Emp->getEmail();
        FileOut.close();
        cout << " Them thanh cong !" << endl;
    }
    else
        cout << " Username da ton tai !" << "\n";
}
void XoaEmployee(User* x, string s) {
    ifstream FileIn;
    FileIn.open("d:\\Employees.txt", ios_base::in);
    ofstream FileOut;
    FileOut.open("d:\\EmployeesCopy.txt", ios_base::out);
    int count = 0;
    while (!FileIn.eof())
    {
        x = new Employees();
        x->ReadFile(FileIn);
        if (x->getUsername() != s)
            FileOut << x->getUsername() << "," << x->getPassword() << endl;
        count++;
    }
    FileIn.close();
    FileOut.close();
    system("del d:\\Employees.txt");
    char* c = (char*)"Employees";
    x->CreateFile(FileOut, c);
    FileOut.close();
    FileIn.open("d:\\EmployeesCopy.txt", ios_base::in);
    FileOut.open("d:\\Employees.txt", ios_base::out);
    while (count > 1) {
        x = new Employees();
        x->ReadFile(FileIn);
        if (count == 2)
        {
            FileOut << x->getUsername() << "," << x->getPassword();
            break;
        }
        FileOut << x->getUsername() << "," << x->getPassword() << endl;
        count--;
    }
    FileIn.close();
    FileOut.close();
    x->DeleteFile(s);
    cout << " Xoa thanh cong !" << endl;
    system("del d:\\EmployeesCopy.txt");
}
void TimEmployee(User* x, string Username){
    ifstream FileIn;
    char* FileName = new char[Username.length() + 1];
    strcpy(FileName, Username.c_str());
    x = new Employees();
    x->OpenFile(FileIn, FileName);
    x->ReadInfomation(FileIn);  
    cout << " Thong tin Employee can tim: " << endl;
    cout << " Ho ten: " << x->getName() << endl;
    cout << " Dia chi: " << x->getAddress() << endl;
    cout << " So dien thoai: " << x->getPhone() << endl;
    cout << " Dia chi Email: " << x->getEmail() << endl;
    FileIn.close();
}
void XemThongTinTaiKhoan(User* x, string Username){
    ifstream FileIn;
    char* FileName = new char[Username.length() + 1];
    strcpy(FileName, Username.c_str());
    x = new Employees();
    x->OpenFile(FileIn, FileName);
    x->ReadInfomation(FileIn);
    cout << " Thong tin tai khoan" << endl;
    cout << " Ho ten: " << x->getName() << endl;
    cout << " Dia chi: " << x->getAddress() << endl;
    cout << " So dien thoai: " << x->getPhone() << endl;
    cout << " Dia chi Email: " << x->getEmail();
    FileIn.close();
}
void CapNhatEmployee(User* x){
    ifstream FileIn;
    ofstream FileOut;
    FileIn.open("d:\\Employees.txt", ios_base::in);
    cout << " Nhap Username muon cap nhat: ";
    string strUser;
    cin >> strUser;
    bool KT = false;
    while (!FileIn.eof())
    {
        x = new User();
        x->ReadFile(FileIn);
        if (x->getUsername() == strUser) 
		{
            KT = true;
            break;
        }
    }
    FileIn.close();
    if (KT == true)
    {
        cout << " Chon muc ban muon cap nhat: " << endl;
        cout << " 1. Ho ten " << endl;
        cout << " 2. Dia chi " << endl;
        cout << " 3. So dien thoai " << endl;
        cout << " 4. Email " << endl;
        int LuaChon;
        cin >> LuaChon;
        char* FileName = new char[strUser.length() + 1];
        strcpy(FileName, strUser.c_str());
        x = new Employees();
        string Edit;
        if (LuaChon == 1)
        {
            
            cout << " Nhap ho ten thay doi: ";
            cin.ignore();           
            getline(cin, Edit);
            x->OpenFile(FileIn, FileName);
            x->ReadInfomation(FileIn);
            FileOut.open("d:\\NoName.txt", ios_base::out);
            FileOut << Edit << endl << x->getAddress() << endl << x->getPhone() << endl << x->getEmail();
            FileIn.close();
            FileOut.close();
            x->DeleteFile(strUser);
            char* fileName = new char[strUser.length() + 1];
            strcpy(fileName, strUser.c_str());
            FileIn.open("d:\\NoName.txt", ios_base::in);
            x = new Employees();
            x->ReadInfomation(FileIn);
            x->CreateFile(FileOut, fileName);
            FileOut << x->getName() << endl << x->getAddress() << endl << x->getPhone() << endl << x->getEmail();
            FileIn.close();
            FileOut.close();      
            cout << " Cap nhat ho ten Employee thanh cong !" << endl;
            x->DeleteFile("NoName");
        }
        else if (LuaChon == 2)
        {           
            cout << " Nhap dia chi thay doi: ";
            cin.ignore();           
            getline(cin, Edit);
            x->OpenFile(FileIn, FileName);
            x->ReadInfomation(FileIn);
            FileOut.open("d:\\NoName.txt", ios_base::out);
            FileOut << x->getName() << endl << Edit << endl << x->getPhone() << endl << x->getEmail();
            FileIn.close();
            FileOut.close();
            x->DeleteFile(strUser);
            char* fileName = new char[strUser.length() + 1];
            strcpy(fileName, strUser.c_str());
            FileIn.open("d:\\NoName.txt", ios_base::in);
            x = new Employees();
            x->ReadInfomation(FileIn);
            x->CreateFile(FileOut, fileName);
            FileOut << x->getName() << endl << x->getAddress() << endl << x->getPhone() << endl << x->getEmail();
            FileIn.close();
            FileOut.close();         
            cout << " Cap nhat dia chi Employee thanh cong !" << endl;
            x->DeleteFile("NoName");
        }
        else if (LuaChon == 3)
        {           
            cout << " Nhap so dien thoai thay doi: ";
            cin.ignore();           
            getline(cin, Edit);
            x->OpenFile(FileIn, FileName);
            x->ReadInfomation(FileIn);
            FileOut.open("d:\\NoName.txt", ios_base::out);
            FileOut << x->getName() << endl << x->getAddress() << endl << Edit << endl << x->getEmail();
            FileIn.close();
            FileOut.close();
            x->DeleteFile(strUser);
            char* fileName = new char[strUser.length() + 1];
            strcpy(fileName, strUser.c_str());
            FileIn.open("d:\\NoName.txt", ios_base::in);
            x = new Employees();
            x->ReadInfomation(FileIn);
            x->CreateFile(FileOut, fileName);
            FileOut << x->getName() << endl << x->getAddress() << endl << x->getPhone() << endl << x->getEmail();
            FileIn.close();
            FileOut.close();       
            cout << " Cap nhat so dien thoai Employee thanh cong !" << endl;
            x->DeleteFile("NoName");
        }
        else if (LuaChon == 4)
        {
            cout << " Nhap email thay doi: ";
            cin.ignore();
            getline(cin, Edit);
            x->OpenFile(FileIn, FileName);
            x->ReadInfomation(FileIn);
            FileOut.open("d:\\NoName.txt", ios_base::out);
            FileOut << x->getName() << endl << x->getAddress() << endl << x->getPhone() << endl << Edit;
            FileIn.close();
            FileOut.close();
            x->DeleteFile(strUser);
            char* fileName = new char[strUser.length() + 1];
            strcpy(fileName, strUser.c_str());
            FileIn.open("d:\\NoName.txt", ios_base::in);
            x = new Employees();
            x->ReadInfomation(FileIn);
            x->CreateFile(FileOut, fileName);
            FileOut << x->getName() << endl << x->getAddress() << endl << x->getPhone() << endl << x->getEmail();
            FileIn.close();
            FileOut.close();
            cout << " Cap nhat email Employee thanh cong !" << endl;
            x->DeleteFile("NoName");
        }
    }
    else  cout << " Username khong ton tai! " << endl;
}
void HienThiThongTinEmployee(User* x){
    ifstream FileIn;
    x = new Employees();
    FileIn.open("d:\\Employees.txt", ios_base::in);
    string strUser[100];
    int n = 0;
    while (!FileIn.eof())
    {
        x->ReadFile(FileIn);
        strUser[n] = x->getUsername();
        n++;
    }
    FileIn.close();
    for (int i = 0; i < n; i++) {      
        cout << " Thong tin " << strUser[i] << ": " << endl;
        string s = strUser[i];
        char* FileName = new char[s.length() + 1];
        strcpy(FileName, s.c_str());
        x->OpenFile(FileIn, FileName);
        x->ReadInfomation(FileIn);
        cout << " Ho ten: " << x->getName() << endl;
        cout << " Dia chi: " << x->getAddress() << endl;
        cout << " So dien thoai: " << x->getPhone() << endl;
        cout << " Dia chi Email: " << x->getEmail() << endl;
        cout << endl;
        FileIn.close();
    }
}
void Menu(User* ds[])
{
    while (true)
    {
        system("cls");
        cout << "          **********************************" << endl;      
        cout << "               1. Quan li nhan vien" << endl;
        cout << "               2. Khach Hang" << endl;       
        cout << "          **********************************" << endl;        
        cout << "               Nhap lua chon: ";
        int LuaChon;
        cin >> LuaChon;
        string TaiKhoan;
        string MatKhau;
        int k;
        string SaveUsername;
        if (LuaChon == 1)
        {
            int n = 0;
            bool Exit = false;
            while (true)
            {
                system("cls");
                DangNhapAdmin();
                ifstream FileIn;
                ofstream FileOut;
                User* x = NULL;
                if (DangNhapThanhCong(x, (char*)"d:\\Admin.txt", SaveUsername))
                {
                    while (true)
                    {
                        system("cls");
                        MenuAdmin();
                        cout << " Moi ban chon chuc nang: ";
                        cin >> k;
                        if (k == 1)
                        {
                            ThemEmployee(x);
                            string s;
                            getch();
                        }
                        else if (k == 2)
                        {
                            string _User;                           
                            cout << " Nhap Username muon xoa: ";                          
                            cin >> _User;
                            FileIn.open("d:\\Employees.txt", ios_base::in);
                            bool TimThay = false;
                            while (!FileIn.eof())
                            {
                                x = new Employees();
                                x->ReadFile(FileIn);
                                if (x->getUsername() == _User)
                                {
                                    TimThay = true;
                                    break;
                                }
                            }
                            FileIn.close();
                            if (TimThay == false)
                            {                               
                                cout << " Khong tim thay " << _User << " de xoa!" << endl;
                                getch();
                            }
                            else
                            {
                                XoaEmployee(x, _User);
                                getch();
                            }
                            FileOut.close();
                        }
                        else if (k == 3)
                        {
                            string _User;
                            cout << " Nhap Username muon tim: ";
                            cin >> _User;
                            FileIn.open("d:\\Employees.txt", ios_base::in);
                            bool TimThay = false;
                            while (!FileIn.eof())
                            {
                                x = new Employees();
                                x->ReadFile(FileIn);
                                if (x->getUsername() == _User)
                                {
                                    TimThay = true;
                                    break;
                                }
                            }
                            FileIn.close();
                            if (TimThay == false)
                            {                             
                                cout << " Khong tim thay Employee!" << endl;
                                getch();
                            }
                            else
                            {
                                TimEmployee(x, _User);
                                getch();
                            }
                        }
                        else if (k == 4)
                        {
                            CapNhatEmployee(x);
                            getch();
                        }
                        else if (k == 5)
                        {
                            HienThiThongTinEmployee(x);
                            getch();
                        }
                        else if (k == 6)
                        {
                            Exit = true;
                            break;
                        }
                        else
                        {                          
                            cout << " Lua chon khong hop le!" << endl;
                            getch();
                        }
                    }
                    if (Exit == true) break;
                }
                else
                {
                    n++;                 
                    cout << " Sai tai khoan hoac mat khau!" << endl;
                }
              
            }
        }
    }
}
int main() {
    User* ds[100];
    Menu(ds);
    system("pause");
}
