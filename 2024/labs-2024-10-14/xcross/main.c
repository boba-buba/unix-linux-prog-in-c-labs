#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <err.h>
#include <fcntl.h>
#include <libgen.h>

#define ERR_ARGV "Wrong number of arguments"

static void set_crosses(int size, int fd)
{
    for (int i = 0; i < size; ++i)
    {
        int end_of_line_count = i;
        int left_index = i * size + i + end_of_line_count;
        int right_index = i * size + (size - i - 1) + end_of_line_count;

        int current = lseek(fd, 0, SEEK_CUR);
        int difference = left_index - current;
        printf("left %d, right %d\n", left_index, right_index);

        //left part
        if (lseek(fd, difference, SEEK_CUR) == -1)
		    err(1, "lseek");

        write(fd, "x", 1);

        current = lseek(fd, 0, SEEK_CUR);
        difference = right_index - current;
        printf ("right diffrence: %d\n", difference);
        //right part
        if (lseek(fd, difference, SEEK_CUR) == -1)
		    err(1, "lseek");

        write(fd, "x", 1);
    }
}

int main(int argc, char** argv)
{
    int fd;
    if (3 != argc)
    {
        printf("%s\n", ERR_ARGV);
        return -1;
    }
    FILE *f = fopen(argv[argc - 1], "a");
    fclose(f);

    fd = open(argv[argc - 1], O_WRONLY);
    int x_size = atoi(argv[1]);


    for (int i = 0; i < x_size; ++i)
    {
        for (int j = 0; j < x_size; ++j)
        {
            write(fd, ".", 1);
        }
        write(fd, "\n", 1);
    }

    set_crosses(x_size, fd);
    return 0;
}