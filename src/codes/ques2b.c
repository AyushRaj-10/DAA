#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp;

    struct dirent *dir;

    if(argc != 2)
    {
        printf("Usage: ./a.out directory\n");
        return 1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Cannot open directory\n");
        return 1;
    }

    printf("Directory Contents:\n");

    while((dir = readdir(dp)) != NULL)
    {
        printf("%s\n", dir->d_name);
    }

    closedir(dp);

    return 0;
}