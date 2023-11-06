{
        arr->A[i+1] = arr->A[i];
        if (arr->A[i] < x)
        {
            arr->A[i+1] = x;
        }
        i--;
    }