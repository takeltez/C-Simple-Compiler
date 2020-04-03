int main(int argc, char const **argv)
{
    int N = 10;
    int arr[] = {1, 2, 3, 4, 5, 32, 65, 78, 5, 0};
    int min = arr[0];

     for (int i = 1; i < N; ++i) {
         if (arr[i] < min) {
             min = arr[i]; 
         }
    }
    
    printf("min: %d\n", min);

    return 0;
}