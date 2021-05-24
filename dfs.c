/*Depth First Search p88
e.g.
扑克牌放置顺序；
void dfs()
{
    判断边界
    尝试每一种可能 for(i=1;i<=n;i++)
    {
        继续下一步 dfs(step+1);
    }
    返回
}
*/

#include<stdio.h>
#include<stdlib.h>

void dfs(int step);
int n;
int *a,*book;


int main()
{
printf("input your num:\n");
scanf("%d",&n);
a = (int *)malloc(sizeof(int)*(n+1));
book = (int *)calloc(n+1,sizeof(int));
printf("going 1\n");
dfs(1);
printf("going 2\n");
//printf("a is %d\n",a[2]);
  getchar();getchar();
return 0;
}

void dfs(int step)//step表示所处的位置
{
    //printf("going step is %d\n",step);
    if(step==n+1)//说明已经走到了尽头后的箱子（虚拟）
        {
            for(int j=1;j<=n;j++)
            {
            printf("%d",a[j]);
            }
            printf("\n");
            return;
        }
    for(int i=1;i<=n;i++)
    {
        //printf("i'm going\n");
        
        if(book[i]==0)//判断该数字i是否已经被放置
        {
            a[step] = i;
            book[i] = 1;//标记i值的数（扑克）已经放置了
            dfs(step+1);//走向下一个点（箱子）去放值；
            book[i] = 0;//开始回收牌，倒着来
        }
    }
  
return;
}