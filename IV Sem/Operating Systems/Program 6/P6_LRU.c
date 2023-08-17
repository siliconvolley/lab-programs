#include <stdio.h>
int fr[3];
void main()
{
    void display();
    int p[12] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2}, i, j, fs[3];
    int index, k, l, flag1 = 0, flag2 = 0, pf = 0, frsize = 3;
    for (i = 0; i < 3; i++)
    {
        fr[i] = -1;
    }
    for (j = 0; j < 12; j++)
    {
        flag1 = 0, flag2 = 0;
        for (i = 0; i < 3; i++)
        {
            if (fr[i] == p[j])
            {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }
        if (flag1 == 0)
        {
            for (i = 0; i < 3; i++)
            {
                if (fr[i] ==
                    -1)
                {
                    fr[i] = p[j];
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0)
        {
            for (i = 0; i < 3; i++)
                fs[i] = 0;
            for (k = j - 1, l = 1; l <= frsize - 1; l++, k--)
            {
                for (i = 0; i < 3; i++)
                {
                    if (fr[i] == p[k])
                        fs[i] = 1;
                }
            }
            for (i = 0; i < 3; i++)
            {
                if (fs[i] == 0)
                    index = i;
            }
            fr[index] = p[j];
            pf++;
        }
        display();
    }
    printf("\n No of page faults :%d\n", pf + frsize);
}
void display()
{
    int i;
    printf("\n");
    for (i = 0; i < 3; i++)
        printf("%d ", fr[i]);
}