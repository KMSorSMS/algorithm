/*
本项目是完成判断一个棋牌游戏
liam（1）和yzw（2）是两玩家，最开始会发给两人6张牌；
每人依次出牌，直到有相同的牌出现在桌面后将相同的牌以及两者之间的所有牌
给出牌玩家加入到他的最后手牌上，直到有一方手牌为零则
对方获胜



本次需要有两个队列来储存两玩家的手牌
需要一个栈来作为桌面储存打出的牌并且还能返回到玩家的手牌队列里面
*/



#include<stdio.h>

struct queue
{
    int data[1000];
    int head;
    int tail;
};

struct stack
{
    int data[10];
    int top;
};

int main(){

   struct queue q1,q2;
   struct stack s;

   q1.head = 1;      //初始化队列；对头
   q1.tail = 1;      //初始化队尾；
   q2.head = 1;
   q2.tail = 1;
   s.top = 0;     //初始化栈堆顶部，初始时因为没有牌则为0；（我这里的top与数量时一致的）
   //初始化liam和yzw的手牌
   printf("now for liam input your target cards:\n");
    for(int i = 1;i<=6;i++){
        scanf("%d",&q1.data[q1.tail]);
        q1.tail++;
    }
    printf("now for yzw input your target cards:\n");
    for(int i = 1;i<=6;i++){
        scanf("%d",&q2.data[q2.tail]);
        q2.tail++;
    }
    printf("----------------------------\n");
    printf("%d%d\n",q1.tail,q1.head);
    printf("%d%d\n",q2.tail,q2.head);
    printf("----------------------------\n");
    
    //发完手牌后开始依次出牌。每次出牌要检查一下桌面；
    //while用于重复回合，
    while(q1.head<q1.tail&&q2.head<q2.tail){
        s.data[++s.top] = q1.data[q1.head];  // 把队头交给桌面（出队）；
        q1.head++;
        //开始判断桌面有没有相同的牌
        for(int i=1;i<s.top;i++){
            //如果有相同的话就回归手牌(往后追加)
            if(s.data[i] == s.data[s.top]){           //Attention: 这下面的for循环中int j不能改成s.top来省事，因为时局部变量所以不能简单在这上面改动；
                for(int j = s.top;j>=i;j--){       //从栈堆顶部开始向手牌队列加元素直到把相同的i也加入队列；此时top指向i-1；
                    q1.data[q1.tail] = s.data[j];
                    q1.tail++;  //入队
                    s.top--;
                    printf("%dq1\n\n",s.top);
                }
                printf("----------\n");
                printf("%d\n",s.top);
                printf("----------\n");
            }
            
        }
        
        //liam完毕后开始yzw的回合，逻辑一致
        s.data[++s.top] = q2.data[q2.head];  // 把队头交给桌面（出队）；
        q2.head++;
        //开始判断卓面有没有相同的牌
        for(int i=1;i<s.top;i++){
            if(s.data[i] == s.data[s.top]){
           for(int j = s.top;j>=i;j--){       //从栈堆顶部开始向手牌队列加元素直到把相同的i也加入队列；此时top指向i-1；
                    q2.data[q2.tail] = s.data[j];
                    q2.tail++;  //入队
                    s.top--;
                    printf("%dq2\n\n",s.top);
                }
                printf("----------\n");
                printf("%d\n",s.top);
                printf("----------\n");
            }
        }
    }
//开始打印结果判断
if(q1.head == q1.tail){
    printf("yzw win\n");
    printf("and the cards left in yzw is :\n");
    int t = q2.head;
    for(t;t<q2.tail;t++){
        printf("%d ",q2.data[t]);

    }
    printf("-----\n");
    printf("the cards left in desk:\n");
    for(int i = s.top;i>=1;i--){
        printf("%d ",s.data[i]);
    }
}
else{
    printf("liam win\n");
    printf("and the cards left in liam is :\n");
    int t = q1.head;
    for(t;t<q1.tail;t++){
        printf("%d ",q1.data[t]);
        
    }
    printf("-----\n");
    printf("the cards left in desk:\n");
    for(int i = s.top;i>=1;i--){
        printf("%d ",s.data[i]);
}
return 0;
}
}



