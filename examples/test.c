int main()
{   
    int a = 12, c = 6;
    
    if (a == 2) {
        a = 3;
    }
    else if (a == 5) {
        a = 5;
    }
     else if (a == 4) {
        printf("a = %d\n", a);
        
        a = 50;
        
        printf("a = %d\n", a);
    }
    else {
        a = 18;
        
        printf("a = %d\n", a);
    }

    c = a / c;
    printf("c = %d\n", c);

    return 0;
}