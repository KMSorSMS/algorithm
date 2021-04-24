#include<stdio.h>


int data[100] = {0,0,0,0};
int right[100] = {0,0,0,0};
//封装一个快速排序函数
//对于排序就可以在加数值的时候就排序了；这里用快速排序；
void quick_sort(int left,int right_s){
if(left>=right_s){
    return;
}
else
{
    int l_s = left;
    int r_s = right_s;
    while(l_s!=r_s)
    {
        while(r_s>l_s&&data[r_s]>=data[left])
        {
            r_s--;
        }

        while(r_s>l_s&&data[l_s]<=data[left])
        {
            l_s++;
        }
        //先后让右边哨兵与左边哨兵移位置
        //开始交换
        int m;
        m = data[l_s];
        data[l_s] = data[r_s];
        data[r_s] = m;

    }
        //当相遇时；把基准点换过去
    int m = data[l_s];
    data[l_s] = data[left];
    //data[left] = data[l_s];这个错误犯得就很不应该，换序切记一个变量记录，返回给另一个
    data[left] = m;
    quick_sort(left,l_s-1);
    quick_sort(l_s+1,right_s);
    
}
}






int main()
{
    
    int n,left,right_s,a;
    printf("input your size:\n");
    scanf("%d",&n);
    //初始化数据，输入数据；
    left = 1;
    right_s = 0;
    for(int i=1;i<=n;i++)
        {
            scanf("%d",&data[i]);
            right_s++;
        }
    quick_sort(left,right_s);
    
                                /*
                                for(int i=1;i<=n;i++)
                                {
                                    printf("%d ",data[i]);
                                }
                                */
    for(int i=1;i<=n;i++)
    {
        
        //right[i] = ++i;//这里会让i自加，和想要的结果不一样
    right[i] = i+1;    
    }


    printf("\nwhat we get:\n");
    int t = 1;
    for(int i=1;i<=n;i++)
        {
            printf("%d ",data[t]);
            //t = right[i];这里不是用i，t的作用时记录当前的node位置，这节代码是用来保持刷新的
            t = right[t];
        }
    printf("\n---------------\nwhat do you want to add:\n");
    scanf("%d",&a);
    n++;
    data[n] = a;
    if(a<=data[1]){
        data[n] = data[1];
        right[n] = right[1];
        right[1] = n;
        data[1] = a;
    }
    else
    {
    for(int i=1;i<=n-1;i++)
    {
        if(data[right[i]] >= a)
        {
            right[n] = right[i];
            right[i] = n;
            break;
            
        }
    }
    }
    t = 1;
    for(int i=1;i<=n;i++)
        {
            printf("%d ",data[t]);
            //t = right[i];这里不是用i，t的作用时记录当前的node位置，这节代码是用来保持刷新的
            t = right[t];
        }


    return 0;
}