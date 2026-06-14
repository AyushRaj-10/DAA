#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Exch(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void QuickSort(int a[], int low, int high)
{
    int i, j, pivot;

    if(low >= high)
        return;

    pivot = a[low];
    i = low + 1;
    j = high;

    while(i <= j)
    {
        while(i <= high && a[i] <= pivot)
            i++;

        while(a[j] > pivot)
            j--;

        if(i < j)
            Exch(&a[i], &a[j]);
    }

    Exch(&a[low], &a[j]);

    QuickSort(a, low, j - 1);
    QuickSort(a, j + 1, high);
}

int main()
{
    int n, a[1000], k;
    clock_t st, et;
    double ts;

    printf("Enter How many Numbers: ");
    scanf("%d", &n);

    printf("The Random Numbers are:\n");

    for(k = 0; k < n; k++)
    {
        a[k] = rand() % 1000;
        printf("%d\t", a[k]);
    }

    st = clock();

    QuickSort(a, 0, n - 1);

    et = clock();

    ts = (double)(et - st) / CLOCKS_PER_SEC;

    printf("\nSorted Numbers are:\n");

    for(k = 0; k < n; k++)
        printf("%d\t", a[k]);

    printf("\nThe time taken is %e", ts);

    return 0;
}