int main()
{   
    int c = 15;
    int b = 3;

    for (int i = 0; i > c; ++i)
    {
        b = i;
    }

    while (c >= b) 
    {
        --c;
    }

    if (c < b) {
        b = c;	
    }

    return 0;
}