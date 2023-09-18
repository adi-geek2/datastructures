#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[3][4] = {{1,2,3,4}, {1,2,3,4}, {1,2,3,4}};
    printf("Printing stack array : \n");        
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            printf("%d \t", A[i][j]);
        }
        printf("\n");        
    }
    
    int*B[3];
    B[0] = (int*)malloc(4*sizeof(int));
    B[1] = (int*)malloc(4*sizeof(int));
    B[2] = (int*)malloc(4*sizeof(int));
    
    printf("Printing stack and heap array : \n");        
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            B[i][j] = A[i][j];
            printf("%d \t", B[i][j]);
        }
        printf("\n");        
    }
    int ** C;
    C = (int**)malloc(3*sizeof(int*));
    C[0] = (int*)malloc(4*sizeof(int));
    C[1] = (int*)malloc(4*sizeof(int));
    C[2] = (int*)malloc(4*sizeof(int));
    printf("Printing heap array : \n");        
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            C[i][j] = A[i][j];
            printf("%d \t", C[i][j]);
        }
        printf("\n");        
    }

 return 0;
}    