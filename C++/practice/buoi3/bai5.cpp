// Họ tên: Trần Đức Anh
// MSSV: 6151071034
// Ngày sinh: 27/07/2002
// Email: 6151071034@st.utc2.edu.vn

#include <iostream>
using namespace std;
class Book{
    private:
        string name;
        int page;
    public:
        Book();
        void input();
        void output();
        string getName(){
            return name;
        }
        int getPage(){
            return page;
        }
};
Book::Book(){
    name = " ";
    page = 0;
}
void Book::input(){
    fflush(stdin);
    cout << "Nhap Ten sach: ";
    getline(cin, name);
    cout << "Nhap so trang: " ;
    cin >> page;
}
void Book::output(){
    cout <<" Ten sach: "<<name<< ", So trang: "<<page<<endl;
}
// Họ tên: Trần Đức Anh
// MSSV: 6151071034
// Ngày sinh: 27/07/2002
// Email: 6151071034@st.utc2.edu.vn
// Sắp xếp theo tên sách
void swap(Book &a, Book &b){
    Book temp;
    temp = a;
    a = b; 
    b = temp;
}
void SortBook(Book *a, int left, int right){//quick sort
    Book x = *(a+((left + right)/2));
    int i = left, j = right;
    do{
        while((a+i)->getName() < x.getName()) 
            i++;
        while ((a+j)->getName() > x.getName())
            j--;
        if(i <= j){
            swap(*(a+i),*(a+j));
            i++;
            j--;
        }
    }while(i < j);
    if(left < j)
        SortBook(a,left,j);
    if(right > i)
        SortBook(a,i,right);
}
// Họ tên: Trần Đức Anh
// MSSV: 6151071034
// Ngày sinh: 27/07/2002
// Email: 6151071034@st.utc2.edu.vn
// sắp xếp theo số trang

void SortPage(Book *a, int left, int right){//quick sort
    Book x = *(a+((left + right)/2));
    int i = left, j = right;
    do{
        while((a+i)->getPage() > x.getPage()) 
            i++;
        while ((a+j)->getPage() < x.getPage())
            j--;
        if(i <= j){
            swap(*(a+i),*(a+j));
            i++;
            j--;
        }
    }while(i < j);
    if(left < j)
        SortPage(a,left,j);
    if(right > i)
        SortPage(a,i,right);
}
// Họ tên: Trần Đức Anh
// MSSV: 6151071034
// Ngày sinh: 27/07/2002
// Email: 6151071034@st.utc2.edu.vn
// tìm kiếm cuốn sách có tên X

Book findBook(Book *a, int n, string name){//binary search
    int left = 0, right = n-1, mid;
    while (left <= right){
        mid = (left + right)/ 2;
        if ((a+mid)->getName() == name)
            return a[mid];
        if ((a+mid)->getName() < name)
            left = mid+1;
        else
            right = mid-1;
    }
    Book notthing;
    return notthing;
}
// Họ tên: Trần Đức Anh
// MSSV: 6151071034
// Ngày sinh: 27/07/2002
// Email: 6151071034@st.utc2.edu.vn
// liệt kê các cuốn sách có số trang ít hơn p

void statistics(Book *a, int n, int p){
    int count = 0;
    for(int i=0; i < n; i++){
        if((a+i)->getPage() < p){
            (a+i)->output();
            count++;
        }
    }
    if(count == 0){
        cout<<"Khong tim thay"<<endl;
    }
}
// Họ tên: Trần Đức Anh
// MSSV: 6151071034
// Ngày sinh: 27/07/2002
// Email: 6151071034@st.utc2.edu.vn
// ham main 

int main(){
    Book *list;
    int n;
    cout<<"Nhap so quyen sach: "; cin>>n;
    list = new Book[n];
    cout <<"\nThong tin sach"<<endl;
    for (int i=0; i < n; i++){
        cout <<"Quyen sach thu "<<i+1<<endl;
        (list+i)->input();
    }
    for (int i=0; i < n; i++){
        cout <<"Quyen sach thu "<<i+1<<":";
        (list+i)->output();
    }
    SortBook(list, 0, n-1);
    cout <<"\nSap xep theo ten sach"<<endl;
    for (int i=0; i < n; i++){
        cout <<"Quyen sach thu "<<i+1<<":";
        (list+i)->output();
    }
    SortPage(list, 0, n-1);
    cout <<"\nSap xep theo so trang sach"<<endl;
    for (int i=0; i < n; i++){
        cout <<"Quyen sach thu "<<i+1<<":";
        (list+i)->output();
    }
    string name;
    cout<<"Nhap ten cuon sach can tim: ";
    fflush(stdin);
    getline(cin, name);
    if(findBook(list, n, name).getName() == " "){
        cout<<"khong tim thay"<<endl;
    }else findBook(list, n, name).output();
    int p;
    cout<<"Nhap so trang: "; cin>>p;
    cout<<"\nCac cuon sach co so trang it hon "<<p<<endl;
    statistics(list, n, p);
    delete [] list;
    return 0;
}