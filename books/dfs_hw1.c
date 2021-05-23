/*find through 1~9 to satisfy [][][]+[][][] = [][][]
all num canonly be used once.
p.s. use DFS
*/
#include<stdio.h>
#include<stdlib.h>

void dfs(int step);
int a[10],book[10];

int main()
{
    printf("now the answer is:\n");
    dfs(1);
    return 0;
}
void dfs(int step)
{
    if((100*(a[1]+a[4])+10*(a[2]+a[5])+a[3]+a[6]==100*a[7]+10*a[8]+a[9])&&step==10)
    {
        for(int j=1;j<=9;j=j+3)
        {
            printf("%d%d%d ",a[j],a[j+1],a[j+2]);
        }
        printf("\n");
    }
    for(int i=1;i<=9;i++)//一张一张的找数字扑克放进去；这里
    //这里制定了一个规则。就是在没有重复的时候就由小到大放扑克号数；
    {
    if(book[i]==0)
    {
        a[step] = i;
        book[i] = 1;
        dfs(step+1);//找到了step位置的箱子放的数后去找step+1的箱子；直到把箱子找完；到n+1
        book[i] = 0;//这里是回收牌：
    }
    }
    return;//记得没有找到时也会return
}
