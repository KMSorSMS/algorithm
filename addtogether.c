/*优化先前的c代码 题目要求见“两数相加”
*/
/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start

#include<stdio.h>
#include<stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
  };
  //包装函数；
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{

//初始化返回的指针，记录其位置，因为后面它会变；(把 struct改个名字)
typedef struct ListNode Node;
Node* p = (Node *)malloc(sizeof(Node));
Node* q = p;//记录返回指针的初始位置；
Node* r;//记录上一次内存；
int adv = 0;//初始化进位；
while(l1!=NULL&&l2!=NULL)//当l1和l2都没有走完时，进行加和
{
    p->val = l1->val+l2->val+adv;//这里是加了进位项的
    adv = 0;//因为进位已经用掉了所以立刻置零；
    //判断是否进位；
    if(p->val>=10)//进位了;
    {
        adv = 1;
        p->val-=10; 
    }
    //完成当前位的数字计算；
    //给p的下一项赋地址并将p移动到它;
    p->next = (Node *)malloc(sizeof(Node));
    r = p;//记录当前的p内存位置；
    p = p->next;
    //把l1和l2向右移动；
    l1 = l1->next;
    l2 = l2->next;
}
//注意此时的p已经移动到了下一位
//下面是产生的多种情况；
//1:一样长
if(l1==NULL&&l2==NULL)
{
//判断有没有进位：
if(adv>0)//if did
{
    p->val = adv;
    p->next = NULL;
}
else
{
    r->next = NULL;//没有进位时说明此时p（已经移位）的位置应该变成null;
}
}
//2:l1长；
else if(l1!=NULL&&l2==NULL)
{
    while(l1!=NULL)
    {
    //add adv
    p->val = l1->val + adv;
    adv = 0;
    //判断有无进位，这里可能不止一次；
    if(p->val>=10)
    {
        adv = 1;
        p->val-=10;
    }
    p->next = (Node *)malloc(sizeof(Node));
    r = p;
    p = p->next;
    l1 = l1->next;
    }
    //同样可能出来后会有再进位
    if(adv>0)
    {
        p->val = adv;
        p->next = NULL;
    }
    else
    {
        r->next = NULL;
    }
}
//同样对于l2更长时
else if(l2!=NULL&&l1==NULL)
{
    while(l2!=NULL)
    {
    //add adv
    p->val = l2->val + adv;
    adv = 0;
    //判断有无进位，这里可能不止一次；
    if(p->val>=10)
    {
        adv = 1;
        p->val-=10;
    }
    p->next = (Node *)malloc(sizeof(Node));
    r = p;
    p = p->next;
    l2 = l2->next;
    }
    //同样可能出来后会有再进位
    if(adv>0)
    {
        p->val = adv;
        p->next = NULL;
    }
    else
    {
        r->next = NULL;
    }
}


return q;
}

int main()
{
    int a[3] = {2,4,3};
    int b[3] = {5,6,4};
    printf("input initiating...\n");
    struct ListNode *l1,*l2,*head1,*head2,*q;
    l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head1 = l1;
    head2 = l2;
    for(int i=1;i<=3;i++)
    {
        l1->val = a[i-1];
        l1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        q = l1;
        l1 = l1->next;
    }
    q->next = NULL;
    l1 = head1;
    for(int i=1;i<=3;i++)
    {
        l2->val = b[i-1];
        l2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        q = l2;
        l2 = l2->next;
    }
    q->next = NULL;
    l2 = head2;
    printf("done-------------------------\n");
// while(l2->next!=NULL)
//     {
//             printf("%d\n",l2->val);
//             l2 = l2->next;
//     }

head1 = addTwoNumbers(l1,l2);
while(head1!=NULL)
{
        printf("\n%d\n",head1->val);
        printf("start\n");
        head1 = head1->next;
}

    return 0;
}