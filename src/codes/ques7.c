#include <stdio.h>

int main()
{
    int b[25], f[25];

    int bf[25] = {0};

    int ff[25];

    int frag[25];

    int nb, nf;

    printf("Enter number of blocks: ");

    scanf("%d", &nb);

    printf("Enter number of files: ");

    scanf("%d", &nf);

    printf("Enter block sizes:\n");

    for(int i = 0; i < nb; i++)
    {
        scanf("%d", &b[i]);
    }

    printf("Enter file sizes:\n");

    for(int i = 0; i < nf; i++)
    {
        scanf("%d", &f[i]);
    }

    for(int i = 0; i < nf; i++)
    {
        for(int j = 0; j < nb; j++)
        {
            if(bf[j] == 0 && b[j] >= f[i])
            {
                ff[i] = j;

                frag[i] = b[j] - f[i];

                bf[j] = 1;

                break;
            }
        }
    }

    printf("\nFile\tFileSize\tBlock\tBlockSize\tFragment\n");

    for(int i = 0; i < nf; i++)
    {
        printf("%d\t%d\t\t%d\t%d\t\t%d\n",
        i+1,
        f[i],
        ff[i]+1,
        b[ff[i]],
        frag[i]);
    }

    return 0;
}