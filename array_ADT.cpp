#include <iostream>

#include <stdio.h>
#include <stdlib.h>

class Array
{
    private:
        int* A;
        int size;
        int m_length;
    
    public:
        Array()
        {
            size = 10;
            m_length = 0;
            A = new int[size]{};
        }

        Array(int sz)
        {
            size = sz;
            m_length = 0;
            A = new int[size];
        }

        ~Array()
        {
            delete []A;
        }

        int get_length();

        void set_length(int m_length);
        void set_array_element(int element, int index);

        void rearrange();
        int is_array_sorted();
        void insert_sort(int x);
        void rotate_left();
        void shift_left();
        void reverse2();
        void reverse();
        float avg();
        int sum();
        int Max();
        int Min();
        void set(int index, int value);
        int get(int index);
        int BinarySearch(int key);
        int LinearSearch(int value);
        void swap (int *x, int *y);
        int Delete(int index);
        void Insert(int index, int value);
        void Append(int value);
        void Display();
        Array* merge(Array arr2);
        Array* Union(Array arr2);
        Array* Intersection(Array arr2);
        Array* Difference(Array arr2);
};


void Array::Display()
{
    int m;
    m = m_length;
    for (size_t i = 0; i < m; i++)
    {
        printf("%d \n", A[i]);
    }
    
}


void Array::Append( int value)
{
    if (m_length < size)
        A[m_length] = value;
        m_length++;    
}


void Array::Insert(int index, int value)
{
    int i;
    if(index >= 0 && index < m_length)
        for (i=m_length;i > index; i--)
            A[i] = A[i-1];
        A[index] = value;
        m_length++;
}


int Array::Delete( int index)
{
    int i, deleted_value = 0;
    if(index >= 0 && index < m_length)
        deleted_value = A[index];
        for (i=index;i < m_length-1; i++)
            A[i] = A[i+1];
        m_length--;
    return deleted_value;
}


void Array::swap (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Array::LinearSearch( int value){
    for(int i = 0; i < m_length; i++)
    {
        if (A[i] == value){
            swap(&A[i], &A[0]);
            return i;        
        }
    }
    return -1;    
}

int Array::BinarySearch( int key){
    int low = 0, mid, high;
    high = m_length-1;
    mid = (low + high)/2;

    while (low < high)
    {
        if (key == A[mid])
            return mid;
        else if (key < A[mid]){
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

int Array::get(int index){
    return A[index];
}

void Array::set( int index, int value){
    A[index] = value;
}

int Array::Min(){
    int min = A[0];
    for (size_t i = 1; i < m_length; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
        
    }
    return min;
}

int Array::Max(){
    int max = A[0];
    for (size_t i = 1; i < m_length; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

int Array::sum(){
    int sum = 0;
    for (size_t i = 0; i < m_length; i++)
    {
        sum = sum + A[i];   
    }
    return sum;
}

float Array::avg(){
    float average = 0;
    average = (float) sum() / m_length;
    return average;
}

void Array::reverse(){
    int i,j = 0;
    int* B;
    B = new int[size];
    for (i = m_length - 1, j=0; i >= 0; i--,j++)
    {
        B[j]=A[i];
    }

    for (size_t i = 0; i < m_length; i++)
    {
        A[i] = B[i];

    } 
}

void Array::reverse2(){
    int i,j, temp = 0;

    for (size_t i = 0; i <= (m_length/2) ; i++)
    {
        temp = A[i];
        A[i] = A[m_length -1 -i];
        A[m_length -1 -i] = temp;
    }
       
}

void Array::shift_left(){
    for (size_t i = 0; i < (m_length-1) ; i++)
    {
        A[i] = A[i+1];
    }
    A[m_length-1] = 0;
       
}

void Array::rotate_left(){
    
    int temp = A[0];
    for (size_t i = 0; i < (m_length-1) ; i++)
    {
        A[i] = A[i+1];
    }
    A[m_length-1] = temp;
       
}

void Array::insert_sort( int x){
    int i = m_length-1;
    while (x < A[i])
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    m_length = m_length + 1;
}

int Array::is_array_sorted(){
    for (size_t i = 0; i < (m_length-2); i++)
    {
        if (A[i] > A[i+1])
        {
            return 0;
        }
    }
    return 1;
}

void Array::rearrange()
{
    int i,j;
    i=0;
    j= m_length-1;

    while (i < j)
    {
       while(A[i] < 0){i++;}
       while(A[j] > 0){j--;}
       if (i<j)
       {
       swap(&A[i],&A[j]);
       }
    }
};

Array* Array::merge(Array arr2){
    Array* arr3 = new Array(m_length + arr2.m_length);
    arr3->m_length =  m_length + arr2.m_length;
    arr3->size =  size + arr2.size;
    int i=0;
    int j=0;
    int k=0;

    while (i < m_length && j < arr2.m_length)
    {
        if (A[i] > arr2.A[j]){
            arr3->A[k++] = arr2.A[j++];
        }
        else
        {
            arr3->A[k++] = A[i++];
        }
    }
    for(; i < m_length; i++)
    {
        arr3->A[k++] = A[i];
    }
    for(; j < m_length; j++)
    {
        arr3->A[k++] = arr2.A[j];
    }
    return arr3;
}

Array* Array::Union(Array arr2){
    Array* arr3 = new Array(m_length + arr2.m_length);
    
    int i=0;
    int j=0;
    int k=0;

    while (i < m_length && j < arr2.m_length)
    {
        if (A[i] > arr2.A[j]){
            arr3->A[k++] = arr2.A[j++];
        }
        else if(arr2.A[j] > A[i])
        {
            arr3->A[k++] = A[i++];
        }
        else
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    for(; i < m_length; i++)
    {
        arr3->A[k++] = A[i];
    }
    for(; j < m_length; j++)
    {
        arr3->A[k++] = arr2.A[j];
    }

    arr3->m_length = k;
    arr3->size = 10;

    return arr3;
}

Array* Array::Intersection(Array arr2){
    struct Array* arr3 = (struct Array*) malloc(sizeof(struct Array));
    
    int i=0;
    int j=0;
    int k=0;

    while (i < m_length && j < arr2.m_length)
    {
        if (A[i] > arr2.A[j]){
            j++;
        }
        else if(arr2.A[j] > A[i])
        {
            i++;
        }
        else
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    
    arr3->m_length = k;
    arr3->size = 10;

    return arr3;
}

Array* Array::Difference(Array arr2){
    struct Array* arr3 = (struct Array*) malloc(sizeof(struct Array));
    
    int i=0;
    int j=0;
    int k=0;

    while (i < m_length && j < arr2.m_length)
    {
        if (A[i] > arr2.A[j]){
            j++;
        }
        else if(arr2.A[j] > A[i])
        {
            arr3->A[k++] = A[i++];
        }
        else
        {
            i++;
            j++;
        }
    }
    
    for(; i < m_length; i++)
    {
        arr3->A[k++] = A[i];
    }

    arr3->m_length = k;
    arr3->size = 10;

    return arr3;
}

int Array::get_length()
{
    return m_length;
}

void Array::set_length(int length){
    m_length = length;
}

void Array::set_array_element(int array_element, int index)
{
    A[index] = array_element;
}


int main(){
    /*
    Array arr2(10); 
    Array arr3(10);
    Array* p_arr3 = &arr3; 
    Array arr_neg(10);
    int i;
    */
    Array arr;
    int length;
    printf("Enter number of input numbers");
    std::cin >> length;
    if(length)
    {
        arr.set_length(length);
    }
    std::cout << arr.get_length() << std::endl;
    int ch;
    do
    {
        printf("Welcome! \n");
        printf("1.Insert \n");
        printf("2.Delete \n");
        printf("3.Search \n");
        printf("4.Sum \n");
        printf("5.Display \n");
        printf("Enter your choice! \n");
        scanf("%d", &ch);

        int index;
        switch (ch)
        {
        case 1:
            int value;
            printf("Enter index and value \n");
            scanf("%d%d",&index, &value);
            arr.Insert( index, value);
            break;
        case 2:
            printf("Enter index to be deleted! \n");
            scanf("%d",&index);
            arr.Delete( index);
             break;
        case 3:
            int key;
            printf("Enter key to be searched! \n");
            scanf("%d",&key);
            index = arr.BinarySearch(key);
            printf("Element found at %d \n", index);
             break;
        case 4:
            int sum;
            sum = arr.sum();
            printf("The sum is %d \n", sum);
             break;
        case 5:
            arr.Display();
        default:
            break;
        }
    }while(ch<6);
    /*
    printf("Enter number of input numbers");
    int length;
    scanf("%d",length);
    arr.set_length(length);
    for (size_t i = 0; i < arr.get_length(); i++)
    {
        int array_element;
        scanf("%d", array_element);
        arr.set_array_element(array_element, i);
    }
    arr.Append( 10);
    printf("AFter appending: \n");
    arr.Insert( 2, 20);
    printf("AFter insertion: \n");
    arr.Display();
    int del_value = arr.Delete(2);
    printf("AFter deletion: \n");
    arr.Display();
    printf("Deleted value is : %d", del_value);
    printf("element found at %d \n", arr.LinearSearch( 4));
    arr.Display(); 
    printf("Element found at %d \n", arr.BinarySearch( 2));

    printf("Get element at 2 : %d \n", arr.get( 2));
    printf("Set element at 22 at 2 \n");
    arr.set( 2, 22);
    arr.Display();
    printf("Min element %d \n", arr.Min());
    printf("Max element %d \n", arr.Max());
    printf("Sum of elements is %d \n", arr.sum());
    printf("Average of elements is %f \n", arr.avg());
    arr.rotate_left();
    printf("Array left rotated: \n");
    arr.insert_sort( 3);
    printf("Array inserted: \n");
    printf("Is array sorted ? 0 means no and 1 means yes: %d \n", arr.is_array_sorted());
    arr_neg.rearrange();
    p_arr3 = arr.merge(arr2);
    arr.Display();
    p_arr3 = arr.Union(arr2);
    arr.Display();
    p_arr3 = arr.Intersection(arr2);
    arr.Display();
    p_arr3 = arr.Difference(arr2);
    arr.Display();
    */
    
    return 0;
}