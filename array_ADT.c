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
    m = arr.length;
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

void reverse(struct Array *arr){
    int i,j = 0;
    int* B;
    B = malloc(arr->length * sizeof(int));
    for (i = arr->length - 1, j=0; i >= 0; i--,j++)
    {
        B[j]=arr->A[i];
    }

    for (size_t i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];

    } 
}

void reverse2(struct Array *arr){
    int i,j, temp = 0;

    for (size_t i = 0; i <= (arr->length/2) ; i++)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[arr->length -1 -i];
        arr->A[arr->length -1 -i] = temp;
    }
       
}

void shift_left(struct Array *arr){
    

    for (size_t i = 0; i < (arr->length-1) ; i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = 0;
       
}

void rotate_left(struct Array *arr){
    
    int temp = arr->A[0];
    for (size_t i = 0; i < (arr->length-1) ; i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = temp;
       
}

void insert_sort(struct Array *arr, int x){
    int i = arr->length-1;
    while (x < arr->A[i])
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length = arr->length + 1;
}

int is_array_sorted(struct Array arr){
    for (size_t i = 0; i < (arr.length-2); i++)
    {
        if (arr.A[i] > arr.A[i+1])
        {
            return 0;
        }
    }
    return 1;
}

void rearrange(struct Array *arr)
{
    int i,j;
    i=0;
    j= arr->length-1;

    while (i < j)
    {
       while(arr->A[i] < 0){i++;}
       while(arr->A[j] > 0){j--;}
       if (i<j)
       {
       swap(&arr->A[i],&arr->A[j]);
       }
    }
};

struct Array* merge(struct Array *arr1, struct Array *arr2){
    struct Array* arr3 = (struct Array*) malloc(sizeof(struct Array));
    arr3->length =  arr1->length + arr2->length;
    arr3->size =  arr1->size + arr2->size;
    int i=0;
    int j=0;
    int k=0;

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] > arr2->A[j]){
            arr3->A[k++] = arr2->A[j++];
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
        }
    }
    for(; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for(; j < arr1->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    return arr3;
}

int main(){
    struct Array arr1 ={{2,3,4,12,15},10,5};
    struct Array arr2 = {{1,5,6,7,8},10,5};

    /*	
    struct Array arr_neg ={{2,-3,4,-12,15,16},10,6};
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

    printf("Get element at 2 : %d \n", get(arr, 2));
    printf("Set element at 22 at 2 \n");
    set(&arr, 2, 22);
    Display(arr);
    printf("Min element %d \n", Min(arr));
    printf("Max element %d \n", Max(arr));
    printf("Sum of elements is %d \n", sum(arr));
    printf("Average of elements is %f \n", avg(arr));
    rotate_left(&arr);
    printf("Array left rotated: \n");
    insert_sort(&arr, 3);
    printf("Array inserted: \n");
    printf("Is array sorted ? 0 means no and 1 means yes: %d \n", is_array_sorted(arr));
    rearrange(&arr_neg);
    */
    Display(*merge(&arr1,&arr2));
    return 0;
}