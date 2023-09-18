#include <stdio.h>
#include <stdlib.h>

int main(){
    int A[5]={1,2,3,4,5};
    int *p;
    int i;

    p = (int*)malloc(5*sizeof(int));
    p[0] = 2;
    p[1] = 4;
    p[2] = 6;
    p[3] = 8;
    p[4] = 10;

    for (i = 0; i < 5; i++)
    {
        printf("%d \n", A[i]);
    }
    printf("Heap array \n");
    for (i = 0; i < 5; i++)
    {
        printf("%d \n", p[i]);
    }
    
    return 0;
}