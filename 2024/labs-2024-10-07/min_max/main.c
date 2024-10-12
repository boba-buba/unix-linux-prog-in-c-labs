#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libmin.h"
#include "libmax.h"

#define OPTION_MIN "min"
#define OPTION_MAX "max"


int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Not enough arguments.\n");
        return 1;
    }

    size_t len = argc - 2;
    int numbers[len];
    for (size_t i = 2; i < argc; ++i)
    {
        numbers[i-2] = atoi(argv[i]);
    }

    char* opt = argv[1];
    int result = 0;
    if (0 == strncmp(OPTION_MIN, opt, strlen(OPTION_MIN)))
    {
        result = min(numbers, len);
    }
    else if (0 == strncmp(OPTION_MAX, opt, strlen(OPTION_MAX)))
    {
        result = max(numbers, len);
    }
    else
    {
        printf("Unknown option: %s\n", opt);
        return 1;
    }

    printf("The %s is %d\n", opt, result);
    return 0;
}