#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
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
    
}

void Append(struct Array *arr, int value)
{
    if (arr->length < arr->size)
        arr->A[arr->length] = value;
        arr->length++;    
}

void Insert(struct Array *arr, int index, int value)
{
    int i;
    if(index >= 0 && index < arr->length)
        for (i=arr->length;i > index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = value;
        arr->length++;
}

int Delete(struct Array *arr, int index)
{
    int i, deleted_value = 0;
    if(index >= 0 && index < arr->length)
        deleted_value = arr->A[index];
        for (i=index;i < arr->length-1; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
    return deleted_value;
}

void swap (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int value){
    for(int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == value){
            swap(&arr->A[i], &arr->A[0]);
            return i;        
        }
    }
    return -1;    
}

int BinarySearch(struct Array arr, int key){
    int low = 0, mid, high;
    high = arr.length-1;
    mid = (low + high)/2;

    while (low < high)
    {
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid]){
            high = mid - 1;
            mid = (low + high)/2;
        }
        else{
            low = mid + 1;
            mid = (low + high)/2;        
        }
    }
    return -1;
}

int get(struct Array arr, int index){
    return arr.A[index];
}

void set(struct Array *arr, int index, int value){
    arr->A[index] = value;
}

int Min(struct Array arr){
    int min = arr.A[0];
    for (size_t i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
        
    }
    return min;
}

int Max(struct Array arr){
    int max = arr.A[0];
    for (size_t i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
        
    }
    return max;
}

int sum(struct Array arr){
    int sum = 0;
    for (size_t i = 0; i < arr.length; i++)
    {
        sum = sum + arr.A[i];   
    }
    return sum;
}

float avg(struct Array arr){
    float average = 0;
    average = (float) sum(arr) / arr.length;
    return average;
}

int main(){
    struct Array arr ={{2,3,4,5,6},10,5};
    /*	
    int i;
    printf("Enter size of an array");
    scanf("%d",&arr.size);
    arr.A=(int*)malloc(sizeof(int)*arr.size);
    arr.length=0;

    printf("Enter number of input numbers");
    scanf("%d",&arr.length);

    for (size_t i = 0; i < arr.length; i++)
    {
        scanf("%d",&arr.A[i]);
    }
    Append(&arr, 10);
    printf("AFter appending: \n");
    Insert(&arr, 2, 20);
    printf("AFter insertion: \n");
    Display(arr);
    int del_value = Delete(&arr, 2);
    printf("AFter deletion: \n");
    Display(arr);
    printf("Deleted value is : %d", del_value);
    printf("element found at %d \n", LinearSearch(&arr, 4));
    Display(arr);   
    printf("Element found at %d \n", BinarySearch(arr, 2));
    */
    printf("Get element at 2 : %d \n", get(arr, 2));
    printf("Set element at 22 at 2 \n");
    set(&arr, 2, 22);
    Display(arr);
    printf("Min element %d \n", Min(arr));
    printf("Max element %d \n", Max(arr));
    printf("Sum of elements is %d \n", sum(arr));
    printf("Average of elements is %f \n", avg(arr));

    return 0;
      
}