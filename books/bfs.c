/*广度优先搜索
思路：有一个起始位置，有一个终点位置，用step记录步数，用结构体“组”来存储位置坐标和此位置的对应步数。
用一个标准来遍历当前位置的下一个位置，用队列的方法建立head和tail，向tail追加结构体
再tail++，通过for循环来走完一次流程（广度优先），通过while循环来遍历下一个‘当前点’

*/



#include<stdio.h>
#include<stdlib.h>

//定义基本结构体；
struct position{
int x;//定义具有的位置
int y;
int step;

};
//基本的方向单元数组；这里用（x，y）坐标
int directon[4][2] = {{1,0},//右
{0,1},//下
{-1,0},//左
{0,-1}//上
};
//初始化地图数组；这里采用动态数组的方式建立地图
//int **array;
int book[51][51];//用于记录已经走过的点
int array[6][5] = {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1};


void bfs(int x,int y,int startx,int starty)
{
int size_x,size_y,tx,ty,flag;
typedef struct position di;
di p[2501];
size_x = 4;
size_y = 5;
// printf("input your maze size---x,y:\n");
// scanf("%d%d",size_x,size_y);
//动态数组的初始化
//注意本二维数组是从1开始，到size_x,size_y结束
// array = (int **)calloc(size_x+1,sizeof(int));
// for(int i=1;i<size_y+1;i++)
// {
//     array[i] = (int *)calloc(size_y+1,sizeof(int));
// }



//队列的初始化；
int head = 1;
int tail = 1;
p[tail].x = startx;
p[tail].y = starty;
p[tail].step = 0;//初始位置一步也没走，step为0；
tail++;//完整的入队操作；

//开始bfs的主题部分，两层循环（点的推进，方向的遍历）
while (head<tail)
{
//开始方向遍历；
for(int i=0;i<3;i++)
{
tx = p[head].x+directon[i][0];
ty = p[head].y+directon[i][1];

//先保证坐标不会越界；不然会产生不可预知的错误；
if(tx<1 || tx>size_x || ty<1 || ty>size_y)
{
continue;
}

//确定下一个位置没有障碍物；且此点之前没有走过；
else if(array[ty][tx]==0&&book[ty][tx]==0)
{
    
book[ty][tx] = 1;//标记此点已经走过了，先到先标，保证step是此点最小；
p[tail].x = tx;
p[tail].y = ty;
p[tail].step = p[head].step+1;
if(tx==x&&ty==y)
    {
        flag = 1;
        break;//可以就从这里退出了，因为已经找到了一条最短路径；
    }
tail++;
//完整的入队操作； 
}
}
//当完成三个方向的检索后；
if(flag==1)
{
    printf("the shortest way step is :%d\n",p[tail].step);
    break;
}
head++;    
}


}





int main()
{
    bfs(3,4,1,1);
    return 0;
}