int main()
{   
    char s = 's';
    char q = 'q';
    
    s = q;

    int b = 3;
    int arr[] = {1, 2, 3, 4, 5, 32, 65, 78, 5, 0};

    int c = arr[3];

    arr[8] = b;

    for (int i = 0; i > c; ++i)
    {
        b = i;
    }

    while (c >= b) 
    {
        --c;
    }

    if (c < b) {
        arr[b] = 2;	
    }

    if (arr[b] == arr[c]) {
        b = c;
    }

    int w = arr[c] * arr[b];

    return 0;
}