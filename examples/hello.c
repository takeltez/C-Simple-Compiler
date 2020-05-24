int main()
{   
    char s = 's';
    char q = 'q';

    int b = 3;
    int arr[] = {1, 2, 3, 4, 5, 32, 65, 78, 5, 0};

    int c = arr[3];

    arr[8] = b;

    q = s;

    for (int i = 0; i > c; ++i)
    {
        b = i;
    }

    while (c >= b) 
    {
        --c;
    }

    if (arr[b] == arr[c]) {
        b = c;
    }

    if (c != b) {
        b = c;
    }

    int w = arr[b] * arr[c];

    arr[c] = arr[b];
    arr[2] = 1;
    arr[b] = c;
      
    return 0;
}