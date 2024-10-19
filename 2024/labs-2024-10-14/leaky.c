#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <stdint.h>
#include <errno.h>

int main(int argc, char** argv)
{
    int count = 0;
    struct rlimit newp;

    int result = getrlimit(RLIMIT_NOFILE, &newp);
    printf("Current: %jd and Max: %jd\n", (intmax_t)newp.rlim_cur, (intmax_t)newp.rlim_max);
    while (1)
    {
        FILE* f = fopen("text.txt", "r");
        printf("Error - %s\n", errno);
        result = getrlimit(RLIMIT_NOFILE, &newp);
        printf("Current: %jd and Max: %jd\n", (intmax_t)newp.rlim_cur, (intmax_t)newp.rlim_max);
        count++;
    }

    return 0;
}