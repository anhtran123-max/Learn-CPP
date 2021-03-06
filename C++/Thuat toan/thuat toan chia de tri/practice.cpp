//nangg x len luy thua n
#include <iostream>
#include <iomanip>
using namespace std;
//dpt o(n)
int power(int x, unsigned int n){
    if( n == 0)
        return 1;
    else if (n%2 == 0)
        return power(x, n/2)*power(x, n/2);
    else
        return x*power(x, n/2)*power(x, n/2);
}
int main(){
    int x = 2;
    unsigned int n = 5;
    cout<<power(x, n)<<setw(3);
    return 0;
}
//dpt o(logn)
#include <iostream>
#include <iomanip>
using namespace std;
int power(int x, unsigned int n) {
    int temp;
    if( n == 0)
        return 1;
    temp = power(x, n/2);
    if (n%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}
int main(){
    int x = 2;
    unsigned int n = 5;
    cout<<power(x, n)<<setw(3);
    return 0;
}