#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main(){
    srand(time(NULL));
    int i;
    int vt[N];
    int *pvt;
    pvt = vt;

    for(i = 0;i<N; i++)
    {
        *pvt = 1 + rand() % 100;
        printf("%d ", *pvt);
        pvt++;
    }
    
    return 0;
}