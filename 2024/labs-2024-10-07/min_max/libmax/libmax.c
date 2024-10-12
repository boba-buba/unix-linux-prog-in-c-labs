#include <stdlib.h>
#include <stdio.h>
#include "libmax.h"


int max(int a[], ssize_t len)
{
        if (len == 0)
    {
        printf("Array is empty.\n");
        return 0;
    }
    int maximum = a[0];

    for (size_t i = 1; i < len; ++i)
    {
        if (maximum < a[i])
        {
            maximum = a[i];
        }
    }
    return maximum;
}