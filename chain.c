#include<stdio.h>
#include<stdlib.h>

struct chain
{
    int data;
    struct chain *next;
};

int main(){
    struct chain *head = NULL;
    struct chain *q;
    struct chain *p;

    int n;
    printf("Input your size:\n");
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
    p = (struct chain *)malloc(sizeof(struct chain));
    if(head == NULL){
        head = p;
        printf("input your data:\n");
        scanf("%d",&p->data);
    }
    else{
        q->next = p;
        printf("input your data:\n");
        scanf("%d",&p->data);
    }
    q = p;
    }
    struct chain *copy = head;
    printf("--------------\nthis is what you put1:\n");
    for(int i = 1;i<=n;i++){
        printf("%d ",copy->data);
        copy = copy->next;
    }

    
    //下面我将加入自动排序，这里运用冒泡排序法，因为快速排序需要head和tail这里我给不了；//调试参数：4/6、5、7、4
    copy = head;
   // struct chain *copy1 = head;
    int m;
    printf("\n%d\n",copy->data);

    for(int i = 1;i<=n;i++)
    {
        copy = head;
        for(int j = 1;j<=n-i;j++)
        {
           // copy = copy1;//cooy 的赋值不是在这里
            if(copy->next->data < copy->data)
            {//检测到右边（next）小于了左边就交换顺序；
            m = copy->data;
            copy->data = copy->next->data;
            copy->next->data =  m;//这里要注意顺序，先把next的值换过去再切换copy->next的索引；而且要在copy的data变成next过后再改next的data

            /*
            copy->next = p;//记录copy next还没变的pointer
            copy->next = copy->next->next;//此时的copy next的pointer已经变了
            p->next = copy;//这样才把原来copy右边的结点的next改掉为copy
            我tm是个sb，这里换个锤子的指针啊，只用把链表上的data值交换就完了
            
            */
            }
           // else
            //{
                copy = copy->next;//只有没有发生换序时才移动一位//放屁，前面逻辑搞错了；
           // }
        }
        //copy1 = copy1->next;
    //printf("\nthis is change:%d",copy1->data);//只是把最大的放到右边，再从头遍历
    }



copy = head;


printf("\n--------------\nthis is what you put2:\n");
    for(int i = 1;i<=n;i++){
        printf("%d ",copy->data);
        copy = copy->next;
    }
    


    printf("\n-------------------------\nnow input the number you want to add:\n");
    int add;
    scanf("%d",&add);
    copy = head;
    p = (struct chain *)malloc(sizeof(struct chain));
    if(add<=head->data)
    {
        p->data = add;
        p->next = head;
        head = p;
        n++;
    }

else
{

    for(int i = 1;i<=n;i++){
        if(copy->next->data >= add){
            //struct chain *p = (struct chain *)malloc(sizeof(struct chain));      //这样做有危险，因为是局部变量，要不是地址的特性比较特殊外界是找不到的
            
            p->data = add;
            p->next = copy->next;
            copy->next = p;   //顺序很重要，一定是先让p的next指向copy的next后再把copy的next改向指p
            n++;
            break;
        }
        copy = copy->next;
    }
}

    copy = head;
    printf("--------------\nthis is what you put:\n");
    for(int i = 1;i<=n;i++){
        printf("%d ",copy->data);
        copy = copy->next;
    }
return 0;
}