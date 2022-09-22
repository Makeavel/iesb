#include<stdio.h>

int main(){

    int i , somatorio , somatorio2;

    for(i = 0; i<100 ; i++){
        if(i %2 == 0){
            somatorio += i;
        }
        if(i %2 != 0){
            somatorio2 += i;
        }
    }
    printf("somatorio %d \nsomatorio2 %d\n" , somatorio, somatorio2);
    return 0;
}