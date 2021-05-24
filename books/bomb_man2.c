//炸弹人游戏求解;

/*
test case:
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
attention:map[x][y];
*/
#include <stdio.h>
#include <stdlib.h>

int mx, my, max;
int **map;

//这里next[i][0]是x，next[i][1]是y；
//广度搜索朝四个方向扩散；
int next[4][2] = {
    {0, 1},  //向右走；
    {1, 0},  //向下走；
    {0, -1}, //向左走：
    {-1, 0}  //向上走；
};
//为了进行广度优先搜索，建立结构体；
struct note
{
    int x; //横坐标
    int y; //纵坐标
};
struct note que[401]; //因为假设了地图不会超过20*20，因此队列扩展不会超过400个；
int head, tail;

char a[20][20];         //用于储存地图
int book[20][20] = {0}; //定义一个标记数组并且全部初始化为0；

//将在一个点可以消灭的总敌人数计算封装为一个函数；
int getnum(int x, int y)
{
    //暂存当前位置；
    int tx, ty, num;
    tx = x;
    ty = y;
    //向上
    while (map[tx][y] != '#') //严格来讲这里是比较的ASCII
    {
        if (map[tx][y] == '.')
        {
            num++;
        }
        tx--;
    }
    //reset
    tx = x;
    //down
    while (map[tx][y] != '#')
    {
        if (map[tx][y] == '.')
        {
            num++;
        }
        tx++;
    }
    //left
    while (map[x][ty] != '#')
    {
        if (map[x][ty] == '.')
        {
            num++;
        }
        ty--;
    }
    //reset;
    ty = y;
    //right
    while (map[x][ty])
    {
        if (map[x][ty] == '.')
        {
            num++;
        }
        ty++;
    }
    return num;
}

int main()
{
    max = 0;
    int startx, starty, m, n;
    printf("input your startx and starty:\n");
    scanf("%d %d", &startx, &starty);
    printf("input your size x y :\n");
    scanf("%d %d", &m, &n);
    //map地图初始化；
    map = (int **)calloc(m, sizeof(int));
    for (int i = 0; i < m; i++)
    {
        map[i] = (int *)calloc(n, sizeof(int));
        printf("input the %dth line\n", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    printf("\nthe map is inited\n");

    head = 1;
    tail = 1;
    que[tail].x = startx;
    que[tail].y = starty;
    tail++;
    book[startx][starty] = 1;
    while (head < tail)
    {
        int tx, ty;
        for (int k = 0; k <= 3; k++)
        {
            //尝试走的下一个点的坐标；
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
            //判断是否越界；
            if (tx < 0 || tx > n - 1 || ty > m - 1)
            {
                continue;
            }
            //判断是否为平地或者曾经走过的；
            if (a[tx][ty] == '.' && book[tx][ty] == 0)
            {
                //每个点只入队一次，所以需要标记此点已经走过；；

                book[tx][ty] = 1;
                //插入新的扩展的点加入队列；

                que[tail].x = tx;
                que[tail].y = ty;
                tail++;
                //统计当前扩展点可以消灭的敌人总数；
                int sum = getnum(tx, ty);
                if (sum > max)
                {
                    max = sum;
                    mx = tx;
                    my = ty;
                }
            }
        }
        //对于一个head走完它的四个可能方向后，让他出队，继续对下一个查找四个方向；
        head++;
    }
    printf("the largest sum is :%d and the point is (%d,%d)\n", max, mx, my);
}