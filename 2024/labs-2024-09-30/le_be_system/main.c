#include <stdio.h>

int main(int argc, char **argv)
{
    int n = 1;
    if(*(char *)&n == 1)
    {
        printf("le");
    }

    return 0;
}