// // # include <stdio.h>
// // int main()
// // {
// //             // char str[10];  //str鏄痵tring鐨勭缉鍐�, 鍗冲瓧绗︿覆
// //             // printf("input your:\n");
// //             // scanf("%s", str);  /*杈撳叆鍙傛暟鏄凡缁忓畾涔夊ソ鐨勨€滃瓧绗︽暟缁勫悕鈥�, 涓嶇敤鍔�&, 鍥犱负鍦–璇█涓暟缁勫悕灏变唬琛ㄨ鏁扮粍鐨勮捣濮嬪湴鍧€*/
// //             // printf("value is:%s\n", str);
// //             // return 0;
// //                         // char ch = '129';
// //                         // char ch2 = '23';
// //                         // char ch3 = 'FATE';
// //                         // int ch4 = 'FATE';
// //                         // char ch5 = '4';
// //                         // char ch6 = ch3 >> 8;
// //                         // int ch7 = ch4 >> 16;

// //                         // printf("%c\n",ch);
// //                         // printf("%c\n",ch2);
// //                         // printf("%d\n",ch3);
// //                         // printf("%c\n",ch4);
// //                         // printf("%c\n",ch5);
// //                         // printf("%c\n",ch6);
// //                         // printf("%c\n",ch7);
// //                         // printf("\007");
// //                         // printf("done!");
// //                         // getchar();
// //                         // return 0;
    
     
     
      

// //                 // double a = asin(1.5);
// //                 // printf("%lf", a);
// //                 // getchar();
// //                 // return 0;

// // float toobig = 9999999e100*100.0f;
// // 	float temp = 0.1234e-37 / 10;
// // 	float toosmall = 0.1234e-38/100;
// // 	printf("%e\n", toobig);
// // 	printf("%e\n", temp);
// // 	printf("%e\n", toosmall);
// // 	getchar();
// // 	return 0;





// // }




// /*
//  * @lc app=leetcode.cn id=2 lang=c
//  *
//  * [2] 涓ゆ暟鐩稿姞
//  */

// // @lc code=start
// #include<stdio.h>
// #include<stdlib.h>
//   //Definition for singly-linked list.
//   struct ListNode {
//       int val;
//       struct ListNode *next;
//   };
// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
// struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
// struct ListNode *q = p;
// struct ListNode *r;

// int adv = 0;
// while(l1!=NULL && l2!=NULL)
// {
//     p->val = l1->val + l2->val-10+adv;
//     adv = 0;
//     if(p->val >= 0)
//     {
//         adv = 1;
//         printf("\nadv 1\n");
//         }
    
//     else
//     {
//         p->val+=10;
//         printf("\nadv 0\n");
//     }
//     p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
//     r = p;   
//     printf("\n l1 is %d l2 is %d p is %d adv is %d",l1->val,l2->val,p->val,adv);
//     p = p->next;
//     l1 = l1->next;
//     l2 = l2->next;
// }
// if(adv>0&&l1==NULL&&l2==NULL){
// printf("\ni'm in!!!\n");
// p->val = 1;
// p->next = NULL;
// }
// if(adv==0&&l1==NULL && l2==NULL)
// {
// p = r;
// p->next = NULL;
// }
// if(l1==NULL && l2!=NULL)
// {
//     p->val = l2->val + adv;
//     while(p->val>=10)
//     {
//         adv = 1;
//         p->val = p->val -10;
//  if(l2->next!=NULL){
//         p->next = l2->next;
//         p = p->next;
//         l2 = l2->next;
        
//         p->val = l2->val +adv;
      
//         adv =  0;
//  }
//     }
    
//     if(l2->next==NULL){
//         p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
//         p->next->val = adv;
//         p->next->next = NULL;
//     }
//     else{
//     p->val = adv;
//     p->next = l2->next;
//     }
    
// }
// if(l2==NULL && l1!=NULL)
// {
//     p->val = l1->val + adv;
// printf("\ni'm in\np val%d\n",p->val);

//     while(p->val>=10)
//     {
//         adv = 1;
//         p->val = p->val -10;
//  if(l1->next!=NULL){
//         p->next = l1->next;
//         p = p->next;
//         l1 = l1->next;
//         p->val = l1->val +adv;
//        printf("\nval for p:%d\n",p->val);
//         adv =  0;
//  }
//  printf("\ntesting adv %d\np val %d",adv,p->val);
//     }
//     if(l1->next==NULL&&adv>0){
//         p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
//         p->next->val = adv;
//         p->next->next = NULL;
//         printf("\nadd more\n");
//     }
//     else{
//     p->next = l1->next;
    
//     }
// }

// return q;
// }


// int main()
// {
//     int a[3] = {2,4,3};
//     int b[3] = {5,6,4};
//     printf("input initiating...\n");
//     struct ListNode *l1,*l2,*head1,*head2,*q;
//     l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
//     l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
//     head1 = l1;
//     head2 = l2;
//     for(int i=1;i<=3;i++)
//     {
//         l1->val = a[i-1];
//         l1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
//         q = l1;
//         l1 = l1->next;
//     }
//     q->next = NULL;
//     l1 = head1;
//     for(int i=1;i<=3;i++)
//     {
//         l2->val = b[i-1];
//         l2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
//         q = l2;
//         l2 = l2->next;
//     }
//     q->next = NULL;
//     l2 = head2;
//     printf("done-------------------------\n");
// // while(l2->next!=NULL)
// //     {
// //             printf("%d\n",l2->val);
// //             l2 = l2->next;
// //     }

// head1 = addTwoNumbers(l1,l2);
// while(head1!=NULL)
// {
//         printf("\n%d\n",head1->val);
//         printf("start\n");
//         head1 = head1->next;
// }

//     return 0;
// }
// // @lc code=end

#include<stdio.h>
int lenth(char *s)
{
    int l = 0;
    while(s[++l]!='\0');
    //比如index为2为\0则l在2时会退出
    return l;
}

int main()
{
    char a[2] = "";
    int b = lenth(a);
    printf("%d\n",b);
    printf("---%c---\n",a[0]);
    return 0;
}