// Trần Đức Anh MSSV: 6151071034 
#include<iostream>
using namespace std;

class PS{
    private:
        float tu;
        float mau;
    public: 
        PS();
        PS(float tu, float mau);
        ~PS();
        void nhap();
        void in();
        float UCLN(float a, float b);
        void rutgon();
        PS operator+(const PS &a);
        PS operator-(const PS &a);
        PS operator*(const PS &a);
        PS operator/(const PS &a);
        void operator =(PS a);
};
PS::PS(){
    tu =0;
    mau =1;
}
PS::PS(float tu,float mau){
    this->tu =tu;
    if (mau != 0) this->mau =mau; 
    else mau=1;
}
PS::~PS(){

}
void PS::nhap(){
        cout<<"\nNhap tu so: ";cin>>tu;
        cout<<"\nNhap mau so: ";cin>>mau;
}
void PS::in(){
    cout<<"\nPhan so: "<<tu<<"/"<<mau;
}
float PS::UCLN(float a, float b) { 
    if (a==0 ||b==0) return a+b;
    while (a !=b) { 
        if(a>b) a=a-b;
        else b=b-a;
    }
    return a;
}
void PS::rutgon(){
    float iUCLN = UCLN(tu, mau);
    tu = tu / iUCLN;
    mau = mau / iUCLN;
}
PS PS::operator+(const PS &a){
    return PS((tu*a.mau) + (mau*a.tu),mau*a.mau);
}
PS PS::operator-(const PS &a){
    return PS((tu*a.mau) - (mau*a.tu),mau*a.mau);
}
PS PS::operator*(const PS &a){
    return PS(tu*a.tu,mau*a.mau);
}
PS PS::operator/(const PS &a){
    return PS(tu*a.mau,mau*a.tu);
}
void PS::operator=(PS a){
    this->tu = a.tu;
    this->mau = a.mau;
}
int main(){
    int n;
    cout<<"\nNhap so luong phan tu: ";cin>>n;
    PS a[n];
    for(int i=0;i<n;i++){
        cout<<"\nNhap phan so thu "<<i+1;
        a[i].nhap();
        a[i].rutgon();
    }
    PS sum ;
    for(int i=0;i<n;i++){
        sum=sum+a[i];
    }
    cout<<"\nTong day la: ";
    sum.rutgon();
    sum.in();
    return 0;
}
