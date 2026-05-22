/* ques7.c - Longest Common Subsequence */

#include<stdio.h>
#include<string.h>

int maxVal(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int lcs(char X[], char Y[], int m, int n)
{
    if(m == 0 || n == 0)
        return 0;

    if(X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);

    return maxVal(
        lcs(X, Y, m, n - 1),
        lcs(X, Y, m - 1, n)
    );
}

int main()
{
    char X[] = "abcbdab";
    char Y[] = "bdcaba";

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS is = %d\n",
           lcs(X, Y, m, n));

    return 0;
}