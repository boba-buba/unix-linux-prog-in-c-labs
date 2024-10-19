#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERR_ARGV "Wrong number of arguments"
#define FILE_ARROW '>'


static int print_file(const char* name, FILE* output_buffer)
{
    int c;

    FILE *input_f = fopen(name, "r");
    if (NULL == input_f)
    {
        return -1;
    }

    while((c = fgetc(input_f)) != EOF)
    {
        fprintf(output_buffer, "%c", c);
    }

    fclose(input_f);
    return 0;
}

int main(int argc, char** argv)
{
    // int argc = 2;
    // char* argv[2] = {"cat", "hey.txt"};
    if (1 == argc)
    {
        printf("%s\n", ERR_ARGV);
        return -1;
    }

    FILE *output_buffer = stdout;
    int start_idx = 1;
    int end_idx = argc - 1;
    bool output_file = false;

    if (FILE_ARROW == argv[argc - 2][0] && 1 == strlen(argv[argc - 2]))
    {
        output_buffer = fopen(argv[argc-1], "a");
        output_file = true;
    }

    for (int i = start_idx; i <= end_idx; ++i)
    {
        if (-1 == print_file(argv[i], output_buffer))
        {
            printf("Error with file: %s\n", argv[i]);
            if (output_file)
            {
                fclose(output_buffer);
            }
            return 1;
        }
    }

    if (output_file)
    {
        fclose(output_buffer);
    }
    return 0;
}
