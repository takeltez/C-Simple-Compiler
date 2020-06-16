int main()
{
    int N = 22, token_size = 4;
    char s_str[] = {'A', 'l', 'e', 'x', 'e', 'y', 'G', 'e', 'n', 'a', 'E', 'u', 'g', 'e', 'n', 'e', 'A', 'l', 'e', 'x', 'e', 'y'};
    char token[] = {'G', 'e', 'n', 'a'};
    int j = 0, pos;

    for (int i = 0; i < N; ++i) {
         if (s_str[i] == token[j]) {
            j++;
         }
         if (j == token_size) {
            pos = i - token_size + 1;
            break;
        }
    }

     printf("substr start pos: %d\n", pos);

     return 0;
}
