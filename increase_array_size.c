#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    int *p, *q;
    p = (int *)malloc(5*sizeof(int));

    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    for (i = 0; i < 5; i++)
    {
        printf("%d \n", p[i]);
    }

    q = (int *)malloc(10*sizeof(int));
    printf("Start copying \n");
    for (i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }
    free(p);
    p = q;
    q = NULL;

    printf("Complete copying \n");
    for (i = 0; i < 5; i++)
    {
        printf("%d \n", p[i]);
    }


    return 0;
}