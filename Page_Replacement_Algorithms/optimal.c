#include <stdio.h>

int main()
{
    int pages[50], frames[10];
    int n, f;
    int i, j, k, pos;
    int fault = 0;
    int found;

    printf("Enter Number of Pages: ");
    scanf("%d", &n);

    printf("Enter Reference String:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter Number of Frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            pos = -1;
            int farthest = -1;

            /* Check for an empty frame */
            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            /* Find page used farthest in future */
            if(pos == -1)
            {
                for(j = 0; j < f; j++)
                {
                    int future = 999;

                    for(k = i + 1; k < n; k++)
                    {
                        if(frames[j] == pages[k])
                        {
                            future = k;
                            break;
                        }
                    }

                    if(future > farthest)
                    {
                        farthest = future;
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            fault++;
        }
    }

    printf("Total Page Faults = %d\n", fault);

    return 0;
}
