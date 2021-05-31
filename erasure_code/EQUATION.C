#include<stdlib.h>
#include<stdio.h>

int main()
{
    int a[21];
    int sum;
    
    for(int i=0; i<21;i++){
        a[0] = -6; 
        sum = a[i] + 3;
        printf("%d \n", i);
    }
    printf("%d", sum);
    
}