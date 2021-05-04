#include<stdio.h>
#include<stdlib.h>

int main()
{
    //初始化总的火柴数量；
    int m,NUM,q,i1,j1;
    printf("input your matchsticks number:\n");
    scanf("%d",&m);

    int num[10] = {6,2,5,5,4,5,6,3,7,6};
    //int *p = (int *)malloc(sizeof(int)*15);

    for(int i=0;i<11111;i++)
    {        
        for(int j=0;j<11111;j++)
        {
            //不应该动i、j的值，应该把他们在当前循环的值记录下来，用副本取取余数等操作
            NUM = 0;
            q = i+j;
            i1 = i;
            j1 = j;
            //先求出各个火柴棍数
            //对于i；
            if(i1==0)
            {
                NUM +=6; //对于i为0，只有一位所以只需要加6个棍子
            }
            while(i1!=0)
            {
                NUM = NUM+num[i1%10];//取i的每一位数字；
                i1/=10;
               // printf("\nI'm in i %d\n",i1);
            }
            //对于j同样把它的每一位火柴棍加上
            if(j1==0)
            {
                NUM+=6;//对于j为0，只有一位所以只需要加6个棍子
            }
            while(j1!=0)
            {
                NUM = NUM+num[j1%10];
                j1/=10;
                //printf("\nI'm in j %d\n",j1);
            }
            while(q!=0)
            {
                NUM = NUM+num[q%10];
                q/=10;
                //printf("\nI'm in q %d\n",q);
            }
            if(NUM+4==m)
            {
            printf("\n%d+%d = %d\n",i,j,i+j);
            printf("---------\n");
            }
        }
    }
    return 0;
}