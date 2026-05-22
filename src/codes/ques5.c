/* ques5.c - Horspool String Matching */

#include<stdio.h>
#include<string.h>

int main()
{
    int table[126];
    char t[100], p[25];

    int n, i, k, j, m, flag = 0;

    printf("Enter text: ");
    scanf("%s", t);

    printf("Enter pattern: ");
    scanf("%s", p);

    n = strlen(t);
    m = strlen(p);

    for(i = 0; i < 126; i++)
        table[i] = m;

    for(j = 0; j < m - 1; j++)
        table[p[j]] = m - 1 - j;

    i = m - 1;

    while(i <= n - 1)
    {
        k = 0;

        while(k <= m - 1 && p[m - 1 - k] == t[i - k])
            k++;

        if(k == m)
        {
            printf("Pattern found at position %d\n", i - m + 2);
            flag = 1;
            break;
        }
        else
        {
            i = i + table[t[i]];
        }
    }

    if(!flag)
        printf("Pattern not found");

    return 0;
}