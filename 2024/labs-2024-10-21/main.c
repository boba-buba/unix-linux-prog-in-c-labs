#include <stdio.h>
#include <unistd.h>
#include <linux/limits.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
    printf("%d\n", PATH_MAX);
    long size = pathconf("/home/koropn" , _PC_PATH_MAX);
    printf("%ld\n", size);
    char dir_path[PATH_MAX + 1];

    for (size_t i = 0; i < PATH_MAX; ++i)
    {
        dir_path[i] = 'a';
    }
    dir_path[PATH_MAX] = '\0';

    int ret_val = mkdir(NULL, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    if (0 != ret_val)
    {
        printf("Error: %s\n", dir_path);
    }
    return 0;
}