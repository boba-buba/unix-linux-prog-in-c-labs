#include <err.h>
#include <fcntl.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <utime.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        errx(1, "usage: %s <file> <position> <offset-from-position>", basename(argv[0]));
        return 1;
    }

    struct stat buffer;
    stat(argv[1], &buffer);
    printf("%ld %ld\n", buffer.st_atime, buffer.st_mtime);
    struct utimbuf times;
    times.actime = buffer.st_atime;
    times.modtime = buffer.st_mtime;
    FILE *f = fopen(argv[2], "a");
    if (NULL != f)
    {
        fclose(f);
    }
    utime(argv[2], &times);
    return 0;
}

