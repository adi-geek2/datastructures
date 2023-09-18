#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int m;
    m = arr.size;
    for (size_t i = 0; i < m; i++)
    {
        printf("%d \n", arr.A[i]);
    }
    
};



int main(){
    struct Array arr;
    int n,i;

    printf("Enter size of an array");
    scanf("%d",&arr.size);
    arr.A=(int*)malloc(sizeof(int)*arr.size);
    arr.length=0;

    printf("Enter number of input numbers");
    scanf("%d",&n);

    for (size_t i = 0; i < n; i++)
    {
        scanf("%d",&arr.A[i]);
    }

    Display(arr);

    return 0;
    
}