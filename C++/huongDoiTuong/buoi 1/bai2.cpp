// Trần Đức Anh MSSV: 6151071034 
#include<iostream>
using namespace std;
 
class Complex{
    private:
        float a,b;//a thực b ảo
    public:
        Complex();
        Complex(float a,float b);
        ~Complex();
        void nhap();
        void in();
        friend Complex operator +(Complex &a,Complex &b);
        void operator =(Complex a);
};
Complex::Complex(){
    this->a=0;
    this->b=0;
}
Complex::Complex(float a,float b){
    this->a=a;
    this->b=b;
}
Complex::~Complex(){
 
}
void Complex::nhap(){
    cout<<"\nNhap phan thuc: ";cin>>a;
    cout<<"\nNhap phan ao: ";
    cin>>b;
}
void Complex::in(){
    cout<<a<<"+"<<b<<"i"<<endl;
}
Complex operator+(Complex &a,Complex &b){
    Complex c;
    c.a=a.a+b.a;
    c.b=a.b+b.b;
    return c;
}
void Complex::operator=(Complex a){
    this->a = a.a;
    this->b = a.b;
}
int main(){
    int n;
    cout<<"\nNhap so luong phan tu: ";cin>>n;
    Complex a[n];
    for(int i=0;i<n;i++){
        cout<<"\nNhap phan tu thu "<<i+1<<endl;
        a[i].nhap();
    }
    Complex sum;
    for(int i=0;i<n;i++){
        sum = sum + a[i];
    }
    cout<<"\nTong day so phuc la: ";
    sum.in();
    return 0;
}