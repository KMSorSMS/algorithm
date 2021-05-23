/*迷宫搜索最短路径*/
#include<stdio.h>
#include<stdlib.h>

// void dfs(int x,int y,int step);
// int min,p,q;
// int next[4][2] = {{0,1},//right
// {1,0},//down
// {0,-1},//left
// {-1,0}//up
// };//这里是一个移动方向的二维数组；
// //接下来的程序里面我们采用顺时针顺序即右下左上尝试

// int main()
// {
//     printf("the short way is :\n");
//     dfs(1,1,0);
//     return 0;
// }

// void dfs(int x,int y,int step)
// {
//     int tx,ty;
//     if(x==p && y==q)
//     {
//         if(step<min)//更新最小值
//         {
//             min = step;
//         }
//         return;//作为递归的收尾；
//     }
    
// }


//标准答案


int n,m,p,q,min=99999;//n是x的边界，m是y的边界
int a[51][51],book[51][51];
void dfs(int x,int y,int step)
{
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int tx,ty;
    //判断是否到达小哈的位置；
    if(x==p && y==q)
    {
        //更新最小值
        if(step<min)
        {
            min = step;
        }
        return;
    }
    //枚举4种走法；
    for(int k=0;k<=3;k++)
    {
        //计算下一个点的坐标；
        tx = x+next[k][0];
        ty = y+next[k][1];
        //判断是否越界
        if(tx<1 || tx>n || ty<1 || ty>m)
        {
            continue;
        }
        //判断该点是否为障碍物或者已经在路径里面；
        if(a[tx][ty]==0 && book[tx][ty]==0)
        {
            book[tx][ty] = 1;//标记这个点已经走过；
            dfs(tx,ty,step+1);//开始尝试下一个点；
            book[tx][ty] = 0;//尝试结束，取消这个点的标记；
        }

    }
    return;
}
int main()
{
    int i,j,startx,starty;
    //读入n和m，n为行，m为列；
    printf("input your maze size x*y:\n");
    scanf("%d %d",&n,&m);
    //读入迷宫
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);//这里是横着一条条输入数据；
        }
    }
    //读入起点和终点位置；
    printf("\nyour start position,your end position\n");
    scanf("%d %d %d %d",&startx,&starty,&p,&q);

    //从起点开始搜索；
    book[startx][starty] = 1;//标记起点已经在路径中，以防后面重复走；
    //
    dfs(startx,starty,0);
    printf("\n%d\n",min);
    return 0;
}