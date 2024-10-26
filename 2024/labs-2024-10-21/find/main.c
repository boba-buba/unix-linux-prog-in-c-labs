/**
 * Finds if substring, more complex regex oatterns id not implemented. Only short
 * variants of options -name and -type are expected as there is some problem
 * with getopt_long
 */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <err.h>
#include <sys/stat.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <linux/limits.h>
#include <stdlib.h>

static char get_type(const char* path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    if (S_ISDIR(path_stat.st_mode) == 1)
    {
        return 'd';
    }
    else if (S_ISREG(path_stat.st_mode) == 1)
    {
        return 'f';
    }
    else
    {
        return 'n';
    }
}


static void find(const char* path, char type, const char* name)
{
    DIR *d;
    struct dirent *de;

    if ((d = opendir(path)) == NULL) {
        return;
    }
    while ((de = readdir(d)) != NULL)
    {
        chdir(path);

        //char* res = realpath(de->d_name, 0);
        char* res = (char*)calloc(PATH_MAX, 1);
        snprintf(res, PATH_MAX, "%s/%s", path, de->d_name);
        //printf("de_name: %s, path: %s\n", de->d_name, res);
        if (type == get_type(res) && NULL != strstr(de->d_name, name))
        {
            printf("%s\n",res);
        }
        if ('.' != de->d_name[0] && 'd' == get_type(de->d_name))
        {
            find(res, type, name);
            chdir(path);
        }
        free(res);
    }
    closedir(d);

}

static void
usage(void)
{
	errx(1, "find: find [path] -t [f/d] -n [name] "
	    "[...]");
}


int
main(int argc, char* argv[])
{
    if (argc != 6)
    {
        errx(1, "Wrong number of params");
        //return 1;
    }
    //int argc = 6;
    char type = 0;
    const char* name = "";
    //char* argv[] = {"find", "/home/koropn", "-t", "f", "-n", "helen"};
    int ch = -1;
    /* options descriptor */
	struct option longopts[] = {
		{ "type",	required_argument,	  NULL,		0 },
		{ "name",	required_argument, NULL,	0 },
		{ NULL,		0,		  NULL,		0 }
	};
    const char* path = argv[1];


    while ((ch = getopt_long(argc, argv, "t:n:", longopts, NULL)) != -1) {
		switch (ch) {
		case 't':
            //printf("type: %s\n", optarg);
			type = optarg[0];
			break;
        case 'n':
            name = optarg;
            break;
		default:
			usage();
		}
	}

    find(path, type, name);
    return 0;
}