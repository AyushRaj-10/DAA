#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *f1, *f2;
    char ch;

    if(argc != 3)
    {
        printf("Usage: ./a.out source destination\n");
        return 1;
    }

    f1 = fopen(argv[1], "r");

    if(f1 == NULL)
    {
        printf("Cannot open source file\n");
        return 1;
    }

    f2 = fopen(argv[2], "w");

    while((ch = fgetc(f1)) != EOF)
    {
        fputc(ch, f2);
    }

    printf("File copied successfully\n");

    fclose(f1);
    fclose(f2);

    return 0;
}