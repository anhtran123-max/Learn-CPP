#include<iostream>
using namespace std;


class Vector{
    private:
        int *array;
        int size;
        int capacity;
    public:
        Vector();
        Vector(const Vector& rhs);
        Vector(int element, int value = 0);
        Vector(const initializer_list<int>& list);

        ~Vector();

        void Push_back(int value);
        void Pop_back();

        bool Empty() const;
        int Size() const;
        int Capacity() const;

        bool operator==(const Vector& rhs) const;
        bool operator!=(const Vector& rhs) const;
       
        friend ostream& operator <<(ostream& ostr, const Vector& rhs);

};
Vector::Vector()
   : size(0),
    capacity(5),
    array(new int[capacity])
{

}
Vector::Vector(const Vector& rhs)
    : size(rhs.size),
      capacity(rhs.capacity),
      array(new int[capacity])
{
    for(int i=0;i<rhs.Size();++i){
        array[i]= rhs.array[i];
    }
}
Vector::Vector(int element, int value)
    : size(element),
       capacity(element+5),
       array(new int[capacity])
{
    for(int i=0;i<size;++i){
        array[i] = value;
    }
}
Vector::Vector(const initializer_list<int>& list)
     : size(0),
     capacity(list.size()+5),
     array(new int[capacity])
{
    for(int i: list){
        Push_back(i);
    }
}
Vector::~Vector(){
    delete [] array;
}
void Vector::Push_back(int value){
    if(size <capacity){
        array[size]=value;
            ++size;
    }
    else{
        capacity *=2;
        int *newarray = new int[capacity];
        for(int i=0;i<size;++i){
            newarray[i] = array[i];
        }
        newarray[size]=value;
        ++size;
        delete [] array;
        array = newarray;
    }
}
void Vector::Pop_back(){
    if(size==0){
        throw exception("Pop back on empty vector!");
    }
   --size; 
}
bool Vector::Empty() const{
    return size==0;
}
int Vector::Size() const{
    return size;
}
int Vector::Capacity() const{
    return capacity;
}
bool Vector::operator==(const Vector& rhs) const{
    if(Size() != rhs.Size()) return false;
    for(int i=0;i<Size();++i){
        if(array[i] != rhs.array[i]){
            return false;
        }
    }
    return true;
}
bool Vector::operator!=(const Vector& rhs) const{
   return !(*this == rhs);
}
ostream& operator <<(ostream& ostr, const Vector& rhs){
    for(int i=0;i<rhs.size;++i){
        ostr << rhs.array[i] <<" ";
    }
    ostr<< " || ";

    for(int i=rhs.size;i<rhs.capacity;++i){
        ostr <<rhs.array[i]<<" ";
    }
    ostr<<endl;
    return ostr;
}

int main(){
    Vector v;
    for(int i=1;i<=22;++i){
        v.Push_back(i);
        cout << v <<endl;
    }
    while(true){
        v.Pop_back();
        cout << v <<endl;
    }
    return 0;
}