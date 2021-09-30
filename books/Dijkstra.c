#include <stdio.h>

#define Inf 9999

/*
调试参数：
6 9 1
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5 
4 3 4
4 5 13
4 6 15
5 6 4
*/

int main()
{
    //存储 地图二维数组，1号相对于其他点的距离
    int e[105][105], dis[100];
    int book[100] = {0};  //标记点是否已经确定（即已经是源点到它的最小值）
    int m, n, a, b, p, s; //m，n,p变量接收点的个数，线的条数，临时点（起点和终点），临时距离,以及单源点
    scanf("%d %d %d", &m, &n, &s);
    //遍历初始化地图
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == j)
            {
                e[i][j] = 0;
            }
            else
            {
                e[i][j] = Inf;
                e[j][i] = Inf;
            }
        }
    }
    //用户输入城市数据
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d ", &a, &b);
        scanf("%d", &e[a][b]);
    }
    //开始Dijkstra
    //往dis[100]放原始数据
    for (int i = 1; i <= m; i++)
    {
        dis[i] = e[s][i];
    }

    book[s] = 1;

    int record;
    //只循环m-1次（为了保险一点，可再多循环一次）
    for (int j = 1; j < m; j++)
    {
        //找到最小dis的点，此点就有可能点变为确定点
        int min = Inf;
        for (int i = 1; i <= m; i++)
        {
            //如果此点未被标记，且距离比min小
            if (book[i] == 0 && dis[i] < min)
            {
                //记录此点的位置
                record = i;
                min = dis[i];
                // min = e[s][i];         //天大得错误啊！！！！！！！！
                // book[i] = 1;
            }
        }
        //标记此点已经变成确定点了
        printf("%d\n", record);
        book[record] = 1;
        //把此点作为中转检查是否能减小其他的距离
        for (int q = 1; q <= m; q++)
        {
            //当然不仅仅是变小，也不能被记录过(也可以不用判断book)
            //错，是一定不能判断book，因为这里是要遍历所有点
            printf("look this%d \n", book[6]);
            if (book[q] != 1 && dis[q] > dis[record] + e[record][q])
            {
                //更新值
                dis[q] = dis[record] + e[record][q];
                for (int r = 1; r <= m; r++)
                {
                    printf("%d ", dis[r]);
                }
                printf("\n");
            }
        }
        for (int i = 1; i <= m; i++)
        {
            printf("%d  ", dis[i]);
        }
        printf("\n------------------------\n");
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d  ", dis[i]);
    }
}