
/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
struct ListNode *q = p;
struct ListNode *r;

int adv = 0;
while(l1!=NULL && l2!=NULL)
{
    p->val = l1->val + l2->val-10+adv;
    adv = 0;
    if(p->val >= 0)
    {
        adv = 1;
        printf("\nadv 1\n");
        }
    
    else
    {
        p->val+=10;
        printf("\nadv 0\n");
    }
    p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    r = p;   
    printf("\n l1 is %d l2 is %d p is %d adv is %d",l1->val,l2->val,p->val,adv);
    p = p->next;
    l1 = l1->next;
    l2 = l2->next;
}
if(adv>0&&l1==NULL&&l2==NULL){
printf("\ni'm in!!!\n");
p->val = 1;
p->next = NULL;
}
if(adv==0&&l1==NULL && l2==NULL)
{
p = r;
p->next = NULL;
}
if(l1==NULL && l2!=NULL)
{

    p->val = l2->val + adv;
printf("\ni'm in\np val%d\n",p->val);
adv = 0;
    while(p->val>=10)
    {
        adv = 1;
        p->val = p->val -10;
 if(l2->next!=NULL){
        p->next = l2->next;
        p = p->next;
        l2 = l2->next;
        p->val = l2->val +adv;
       printf("\nval for p:%d\n",p->val);
        adv =  0;
 }
 printf("\ntesting adv %d\np val %d",adv,p->val);
    }
    if(l2->next==NULL&&adv>0){
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next->val = adv;
        p->next->next = NULL;
        printf("\nadd more\n");
    }
    else{
    p->next = l2->next;
    
    }
    
}
if(l2==NULL && l1!=NULL)
{
    p->val = l1->val + adv;
printf("\ni'm in\np val%d\n",p->val);
adv = 0;
    while(p->val>=10)
    {
        adv = 1;
        p->val = p->val -10;
 if(l1->next!=NULL){
        p->next = l1->next;
        p = p->next;
        l1 = l1->next;
        p->val = l1->val +adv;
       printf("\nval for p:%d\n",p->val);
        adv =  0;
 }
 printf("\ntesting adv %d\np val %d",adv,p->val);
    }
    if(l1->next==NULL&&adv>0){
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next->val = adv;
        p->next->next = NULL;
        printf("\nadd more\n");
    }
    else{
    p->next = l1->next;
    
    }
}

return q;
}