//Trần Đức Anh MSSV: 6151071034
#include<bits/stdc++.h>
using namespace std;
class MatHang{
    private:
        string tmh;
        int sl;
        float dg;
    public:
        void nhap();
        void xuat();
        float tien();
        int getSL();
        float getDg();
};
class HoaDon:public MatHang{
    private:
        string thd;
        MatHang *dsmh;
        int slmh;
    public:
        void nhap();
        void In();
        float tongt();
        string getTHD();
};
void MatHang::nhap(){
    cout<<"Ten mat hang: "; 
    fflush(stdin);
    getline(cin, tmh);
    cout<<"So luong: "; 
    fflush(stdin);
    cin>>sl;
    cout<<"Don gia: "; 
    cin>>dg;
}
void MatHang::xuat(){
    cout<<"Ten mat hang: "<<tmh<<", so luong"<<sl<<", don gia: "<<dg<<endl;
}
int MatHang::getSL(){
    return sl;
}
float MatHang::getDg(){
    return dg;
}
string HoaDon::getTHD(){
    return thd;
}
void HoaDon::nhap(){
    cout<<endl<<"Ten hoa don: ";
    fflush(stdin);
    getline(cin, thd);
    cout<<endl<<"So luong mat hang: "; 
    cin>>slmh;
    cout<<endl<<"Danh sach mat hang: "<<endl;
    fflush(stdin);
    dsmh = new MatHang[slmh];
    for(int i=0; i<slmh;i++){
        cout<<"==>Mat hang "<<i+1<<endl;
        dsmh[i].nhap();
    }
}
void HoaDon::In(){
    cout<<"Ten hoa don: "<<thd<<endl;
    cout<<"So luong mat hang: "<<slmh<<endl;
    cout<<"Danh sach mat hang: "<<endl;
    for(int i=0; i<slmh;i++){
        cout<<"==>Mat hang "<<i+1<<endl;
        dsmh[i].xuat();
    }
    cout<<"Tong tien: "<<tongt()<< endl;
}
float MatHang::tien(){
    return (float)(sl*dg);
}
float HoaDon::tongt(){
    float sum = 0;
    for(int i=0; i<slmh;i++){
        sum += dsmh[i].tien();
    }
    return sum;
}

int main(){
    HoaDon *a;
    int n;
    cout<<"Nhap so luong hoa don: ";    cin>>n;
    a = new HoaDon[n];
    for(int i=0; i<n;i++){
        cout<<"!!!Hoa don "<<i+1;
        a[i].nhap();
    }
    cout<<"Xuat cac hoa don: "<<endl;
    for(int i=0; i<n;i++){
        cout<<"!!!Hoa don "<<i+1<<endl;
        a[i].In();
    }
    cout<<"\nHoa don co tong tien lon nhat"<<endl;
    int max=a[0].tongt();
    for(int i=0;i<n;i++){
        if(max<a[i].tongt()) max=a[i].tongt();
    }
    for(int i=0;i<n;i++){
        if(a[i].tongt()==max) a[i].In();
    }
    cout<<"\nHoa don co tong tien nho nhat"<<endl;
    int min=a[0].tongt();
    for(int i=0;i<n;i++){
        if(min>a[i].tongt()) min=a[i].tongt();
    }
    for(int i=0;i<n;i++){
        if(a[i].tongt()==min) a[i].In();
    }
    string name;
    cout<<"\nNhap ten hoa don can tim";
    fflush(stdin);
    getline(cin, name);
    for(int i=0;i<n;i++){
        if(a[i].getTHD()==name) a[i].In();
    }
    return 0;
}