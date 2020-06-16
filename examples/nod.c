int main ()
{
    int a = 24, b = 12  ;
    int min = (a < b) ? a : b;
    int nod = min;

    for (int i = min; i > 0; i--) { 
        if (a % i == 0 && b % i == 0) { 
            nod = i;
            break;  
       }
   }

    printf("nod: %d\n", nod); 

    return 0;
}