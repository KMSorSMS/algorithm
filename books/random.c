#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    printf("input your num_size:\n");
    int m;
    scanf("%d",&m);
    printf("done\n");
    int i;
    srand((int)time(0));
    int a[100];
    int w, t, n;
    n = 49;
    for (i = 0; i < n; i++)

        a[i] = i + 1;

    for (i = 0; i < m; i++)

    {
        w = rand() % (n - i) + i;

        t = a[i];

        a[i] = a[w];

        a[w] = t;
    }
     for (i = 0; i < m; i++)
{
    printf("%d\n",a[i]);
}
getchar();getchar();
return 0;

}