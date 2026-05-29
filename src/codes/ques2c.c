#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1024

int main(int argc, char *argv[])
{
    FILE *fp;

    char line[MAX];

    int lineNo = 0;

    int found = 0;

    if(argc != 3)
    {
        printf("Usage: ./a.out filename word\n");

        return 1;
    }

    fp = fopen(argv[1], "r");

    if(fp == NULL)
    {
        printf("Cannot open file\n");

        return 1;
    }

    while(fgets(line, MAX, fp) != NULL)
    {
        lineNo++;

        if(strstr(line, argv[2]) != NULL)
        {
            printf("%d : %s", lineNo, line);

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("Word not found\n");
    }

    fclose(fp);

    return 0;
}