# include <stdio.h>
# include <stdlib.h>

//Create array DT
struct array
{
    /* data */
    int *A;
    int size;
    int length;
};

//Create display function
void Display(struct array arr){
    int i;
    printf("And the array is: ");
    for (size_t i = 0; i < arr.length; i++)
    {
        /* code */
        printf("%d \n", arr.A[i]);
    }
    
}

int main(){
    struct array arr;
    int i;

    printf("Enter the size of array: \n");
    scanf("%d", &arr.size);

    arr.A = (int*)malloc(arr.size*sizeof(int));

    printf("Enter the length of array: ");
    scanf("%d", &arr.length);

    printf("Enter the elements of array: \n");
    
    // Take input of array elements 
    for (size_t i = 0; i < arr.length; i++)
    {
        /* code */
        scanf("%d",&arr.A[i]);
    }   
    
    //Call display function
    Display(arr);

    return 0;
}