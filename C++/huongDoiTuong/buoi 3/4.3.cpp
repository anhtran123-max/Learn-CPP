// Trần Đức Anh MSSV: 6151071034
#include <bits/stdc++.h>
using namespace std;

class Frac{
    private:
        float a, b;
    public:
        Frac();
        Frac(float a, float b);
        void input();
        void display();
        void compact();
        Frac operator+(Frac f);
        Frac operator=(Frac f);
};
Frac::Frac(){
    this->a = 0;
    this->b = 1;
}
Frac::Frac(float a, float b){
    this->a = a;
    this->b = b;
}
void Frac::input(){
    cout << "\nNhap tu: " <<endl; cin >> a;
    do{
        cout << "\nNhap mau: "<<endl; cin >> b;
        if(b == 0)
            cout<<"Mau phai khac 0!!!"<<endl;
    }while(b == 0);
}
void Frac::display(){
    compact();
    if(a == 0 || b == 1)
        cout<<a<<endl;
    else cout<<a<<"/"<<b<<endl;
}
int greatestCommonDivisor(int number1, int number2){
    if (number2 == 0) return number1;
    return greatestCommonDivisor(number2, number1 % number2);
}
void Frac::compact(){
    int greatest_common_divisor = greatestCommonDivisor(a, b);
    a = a / greatest_common_divisor;
    b = b / greatest_common_divisor; 
}
Frac Frac::operator+(Frac f){
    return Frac((this->a * f.b) + (this->b * f.a), this->b * f.b);
}
Frac Frac::operator=(Frac f){
    this->a = f.a;
    this->b = f.b;
    return *this;
}
void input2(int fl[], int &n2){
    cout<<"Enter n int number: "<<endl;
    cin>>n2;
    for(int i=0; i<n2; i++){
        cout<<"Enter elements "<<i+1<<":"<<endl;
        cin>>fl[i];
    }
}
void display2(int fl[], int n2){
    float max = sum(fl, n2);
    cout<<"Integer sum is: "<<max<<endl;
}
int sum(int fl[], int n2){
    int sum = 0;
    for(int i=0; i<n2; i++) sum += fl[i];
    return sum;
}
int main(){ 
    int n, n2;
    int fl[n2];
    input2(fl, n2);
    display2(fl, n2);
    Frac *frac = new Frac[n];
    Frac t;
    cout<<"Enter n Frac number: "<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"Enter frac "<<i+1<<endl;
        frac[i].input();
        t = t + frac[i];
    }
    cout<<"Frac sum is: "<<endl;
    t.display();
    Frac a(4,5), b(5,4);
    cout<<"Assigned: "<<endl;
    a = b;
    a.display();
    return 0;
}