#include <stdio.h>

int frame[3];

void display()
{
    printf("\n");

    for(int i = 0; i < 3; i++)
    {
        printf("%d ", frame[i]);
    }
}

int main()
{
    int pages[12] =
    {2,3,2,1,5,2,4,5,3,2,5,2};

    int fs[3];

    int pf = 0;

    for(int i = 0; i < 3; i++)
    {
        frame[i] = -1;
    }

    for(int j = 0; j < 12; j++)
    {
        int flag1 = 0;
        int flag2 = 0;

        // Page Hit

        for(int i = 0; i < 3; i++)
        {
            if(frame[i] == pages[j])
            {
                flag1 = 1;
                flag2 = 1;

                break;
            }
        }

        // Empty Frame

        if(flag1 == 0)
        {
            for(int i = 0; i < 3; i++)
            {
                if(frame[i] == -1)
                {
                    frame[i] = pages[j];

                    flag2 = 1;

                    break;
                }
            }
        }

        // Replace LRU Page

        if(flag2 == 0)
        {
            for(int i = 0; i < 3; i++)
            {
                fs[i] = 0;
            }

            int index;

            for(int k = j-1, l = 1;
                l <= 2;
                l++, k--)
            {
                for(int i = 0; i < 3; i++)
                {
                    if(frame[i] == pages[k])
                    {
                        fs[i] = 1;
                    }
                }
            }

            for(int i = 0; i < 3; i++)
            {
                if(fs[i] == 0)
                {
                    index = i;
                }
            }

            frame[index] = pages[j];

            pf++;
        }

        display();
    }

    printf("\nPage Faults = %d",
    pf + 3);

    return 0;
}