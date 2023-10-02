#include <stdio.h>

int main(void)
{
    int someArray[] = {1 , 2 , 3 , 4 , 5};

    for (int i = 0; i < 5; i++) {
        printf("%i\n" , someArray[i]);
    }
    return 0;
}