#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <err.h>
#include <sys/stat.h>
#include <unistd.h>


static void print_info(char type, const char *path)
{
    printf("%c %s", type, path);
    if ('l' == type)
    {
        struct stat p_statbuf;
        stat(path, &p_statbuf);
        //lstat and read link dont work
        readlink();

    }
}


static void namei(const char* path)
{
    printf("f: %s", path);

    char *curr_path = "";
    if (path[0] == '/')
    {
    
    }


}



int
main(int argc, char *argv[])
{
    DIR *d;
    struct dirent *de;
    for (int i = 1; i < argc; i++) {
        if ((d = opendir(argv[i])) == NULL) {
            warn("%s", argv[i]); continue;
        }
        while ((de = readdir(d)) != NULL)
            printf("%s %c\n", de->d_name, de->d_type);
        closedir(d);
    }
}