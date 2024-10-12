#include <stdio.h>
#include "liba.h"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Not enough arguments.\n");
        return 1;
    }
    int count = fna(argv[1]);
    printf("Number of chars in %s is %d\n", argv[1], count);
    return 0;
}