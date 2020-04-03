int main(int argc, const char **argv)
{
    printf("Start counting\n"); //Hello!

    int a = 10 / 2;

    if (a == 5) {
    	 printf("a = 5\n"); 
    	 double b = a - 2;
    }

    while (b == 3) {
        printf("b = 3\n");
    }

    for (int i = b + 1; i < 10; ++i) {
        b--;
        printf("postfix incrementation");
    }

    return 0;
}