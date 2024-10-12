#include <stdio.h>
#include "liba.h"
#include "libb.h"

int fna(const char *word)
{
    printf("calling libb\n");
    return fnb(word);
}
