#include <stdio.h>
 
int main(){
    int n, tmp;
    scanf("%d", &n);
    int k = 0;
    while(n>0){
        tmp = n % 10;//chia lay du
        k = k * 10 + tmp;
        n = n / 10;//chia lay nguyen
    }
    printf("%d", k);
}
//1234->4321
int sodaonguoc(int n, int sdn){
    if(n==0) return sdn;
    else{
        sdn=sdn*10+n%10;
        return sodaonguoc(n/10,sdn);
    }
}