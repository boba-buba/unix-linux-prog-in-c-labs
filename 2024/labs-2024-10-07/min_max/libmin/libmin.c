#include <stdio.h>
#include "libmin.h"

int min(int a[], ssize_t len)
{
    if (len == 0)
    {
        printf("Array is empty.\n");
        return 0;
    }
    int minimum = a[0];

    for (size_t i = 1; i < len; ++i)
    {
        if (minimum > a[i])
        {
            minimum = a[i];
        }
    }
    return minimum;
}