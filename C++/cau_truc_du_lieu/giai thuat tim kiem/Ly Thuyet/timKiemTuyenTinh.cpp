#include<iostream>

using namespace std;

void NhapMang(int a[], int n);
void XuatMang(int a[], int n);
int Isearch(int a[], int n);

int main(){
	int n;
	int a[100];
	do{
        cout<<"\n Nhap n: ";
	    cin>>n;
		if(n<=0 || n>=100)
		    cout<<"\nNhap lai n!!";
	}while(n<=0 || n>=100);
	cout<<"Nhap mang!!!\n";
	NhapMang(a,n);
	cout<<"\nXuat mang!!!";
    XuatMang(a,n);
	int kq = Isearch(a,n);
	cout<<kq;
	return 0;
}
void NhapMang(int a[], int n){
	for(int i=0; i<n; i++){
			cout<<" a["<<i<<"]=";
			cin>>a[i];
	}
}
void XuatMang(int a[], int n){
	for(int i=0;i<n;i++){
			cout<<"\na["<<i<<"]="<<a[i];
	}
}
int Isearch(int a[], int n){
	int x;
	cout<<"\nNhap so can tim: ";
	cin>>x;
	for(int i=0;i<n;i++){
		if(a[i] == x){
            return i;
		} 
	}
	return -1;
}