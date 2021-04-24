/*小哼是1
小哈是2对应self_ans的liam和yzw
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

int main()
{
    struct queue q1, q2;
    struct stack s;
    int book[10];
    int i,t;

    //初始化队列
    q1.head = 1;q1.tail = 1;
    q2.head = 1;q2.tail = 1;
    //初始化栈：
    s.top = 0;
    //初始化用来标记的数组，用来标记哪些牌已经在桌上；
    for(i = 1;i<=9;i++){
        book[i] = 0;
    }
    //依次向队列中插入6个数
    //小哼手上的六张牌
    for(i = 1;i<=6;i++){
        scanf("%d",&q1.data[q1.tail]);
        q1.tail++;
    }
    //小哈手上的六张牌
    for(i =1;i<=6;i++){
        scanf("%d",&q2.data[q2.tail]);
        q2.tail++;
    }
    while(q1.head<q1.tail&&q2.head<q2.tail){
        t = q1.data[q1.head];//用于判断小哼出牌的值后续看会不会赢牌；
        //开始判断能不能赢;
        if(book[t] == 0){//表明场上没有出的这张；这里有桶的思想：将索引和值对接记录出现的次数；
        //说明小哼这里不会赢牌
        q1.head++;//出队
        s.top++;
        s.data[s.top] = t;
        book[t] = 1;//标记桌面上已经有牌面为t的牌
        }
        else{
            //小哼此轮可以赢
            q1.head++;
            q1.data[q1.tail] = t;
            q1.tail++;
            while(s.data[s.top] != t){
                book[s.data[s.top]] = 0;//取消标记
                q1.data[q1.tail] = s.data[s.top];
                q1.tail++;
                s.top--;//栈少了一张牌，所以栈顶要减一；
            }
        }
    }
    t = q2.data[q2.head];
    if(book[t]==0){
        q2.head++;
        s.top++;
        s.data[s.top] = t;
        book[t] = 1;

    }
    else{
        q2.head++;
        q2.data[q2.tail] = t;
        q2.tail++;
        while(s.data[s.top] != t){
            q2.data[q2.tail] = s.data[s.top];
            q2.tail++;
            s.top--
        } 
    }

}