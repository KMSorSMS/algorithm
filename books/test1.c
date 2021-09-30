
// // // #include<stdio.h>
// // // #include<stdlib.h>

// // // int main()
// // // {
// // // 	int iFee[6];
// // // 	int iRoomNum = 0;
// // // 	iFee[0] = 0;
// // // 	iFee[1] = 111;
// // // 	iFee[2] = 222;
// // // 	iFee[3] = 333;
// // // 	iFee[4] = 444;
// // // 	printf("Please input");
// // // 	scanf("%d", &iRoomNum);
// // // 	printf("%d",iFee[iRoomNum]);
// // // 	system("pause");
// // // 	return 0;
// // // }
// // #include <stdio.h>

// // int main()
// // {
// //     // struct element
// //     // {
// //     //     int num;
// //     //     int flag = 1;
// //     // };
// //     int e[200][200] = {{0}};
// //     int m, n, a, b, c;
// //     printf("input your points num & edegs num：\n");
// //     scanf("%d %d ", &m, &n);
// //     // struct element que[m];
// //     int city[200][200] = {{0}};
// //     int book[200] = {0};
// //     // int count[m];
// //     for (int i = 1; i <= m; i++)
// //     {
// //         for (int j = 1; j <= m; j++)
// //         {
// //             if (i != j)
// //             {
// //                 e[i][j] = 999999;
// //             }
// //             else
// //             {
// //                 e[i][j] = 0;
// //             }
// //         }
// //     }
// //     for (int i = 1; i <= n; i++)
// //     {
// //         scanf("%d %d %d", &a, &b, &c);
// //         e[a][b] = e[b][a] = c;
// //     }
// //     for (int k = 1; k <= n; k++)
// //         for (int i = 1; i <= n; i++)
// //             for (int j = 1; j <= n; j++)
// //             {
// //                 if(k==j||k==i){
// //                     continue;
// //                 }
// //                 if (e[i][j] > e[i][k] + e[k][j])
// //                 {
// //                     e[i][j] = e[i][k] + e[k][j];
// //                     //记录作为关键中转点的城市
// //                     city[i][j] = k;

// //                     // que[k].num = e[i][k]+e[k][j];
// //                     // e[i][j] = que[k].num;
// //                 }
// //                 else if (e[i][j] == e[i][k] + e[k][j])
// //                 {
// //                     //说明这两个城市之间存在另一个关键中转点达到同一效果
// //                     /*
// //                     注意：
// //                         不得不承认，这个新产生的关键中转点的数据，可能会通过原来中转点去产生，但是，如果
// //                         是这样，那么原来的中转点在该中转点的e[i][k]或e[k][j]路径中作为关键中转点且没有
// //                         被移去，这样，我们移去它在这个路径中的重要位置仍然不会影响它是不是真的还会为某条
// //                         路径的关键中转点
// //                     */
// //                     city[i][j] = 0;
// //                     // que[k].flag = 0;
// //                 }
// //             }
// //     //去遍历city找到重要城市,用桶排序输出
// //     for (int i = 1;i<=n;i++){
// //         for(int j = 1;j<=n;j++){
// //             if(city[i][j]!=0){
// //                 book[city[i][j]] = 1;
// //             }
// //         }
// //     }
// //     //输出答案
// //     printf("答案是：\n");
// //     for (int i = 1;i<=n;i++){
// //         if(book[i]==1){
// //             printf("%d ",i);
// //         }
// //     }
// // }

// // #include<stdio.h>
// // #include<stdlib.h>

// // int main()
// // {
// // 	int iFee[6];
// // 	int iRoomNum = 0;
// // 	iFee[0] = 0;
// // 	iFee[1] = 111;
// // 	iFee[2] = 222;
// // 	iFee[3] = 333;
// // 	iFee[4] = 444;
// // 	printf("Please input");
// // 	scanf("%d", &iRoomNum);
// // 	printf("%d",iFee[iRoomNum]);
// // 	system("pause");
// // 	return 0;
// // }
// #include <stdio.h>

// int main()
// {
//     // struct element
//     // {
//     //     int num;
//     //     int flag = 1;
//     // };
//     int e[200][200] = {{0}};
//     int m, n, a, b, c;
    
//     scanf("%d %d ", &m, &n);
//     // struct element que[m];
//     int city[200][200] = {{0}};
//     int book[200] = {0};
//     // int count[m];
//     for (int i = 1; i <= m; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             if (i != j)
//             {
//                 e[i][j] = 999999;
//             }
//             else
//             {
//                 e[i][j] = 0;
//             }
//         }
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         scanf("%d %d %d", &a, &b, &c);
//         e[a][b] = e[b][a] = c;
//     }
//     for (int k = 1; k <= n; k++)
//         for (int i = 1; i <= n; i++)
//             for (int j = 1; j <= n; j++)
//             {
//                 if(k==j||k==i){
//                     continue;
//                 }
//                 if (e[i][j] > e[i][k] + e[k][j])
//                 {
//                     e[i][j] = e[i][k] + e[k][j];
//                     //记录作为关键中转点的城市
//                     city[i][j] = k;

//                     // que[k].num = e[i][k]+e[k][j];
//                     // e[i][j] = que[k].num;
//                 }
//                 else if (e[i][j] == e[i][k] + e[k][j])
//                 {
//                     //说明这两个城市之间存在另一个关键中转点达到同一效果
//                     /*
//                     注意：
//                         不得不承认，这个新产生的关键中转点的数据，可能会通过原来中转点去产生，但是，如果
//                         是这样，那么原来的中转点在该中转点的e[i][k]或e[k][j]路径中作为关键中转点且没有
//                         被移去，这样，我们移去它在这个路径中的重要位置仍然不会影响它是不是真的还会为某条
//                         路径的关键中转点
//                     */
//                     city[i][j] = 0;
//                     // que[k].flag = 0;
//                 }
//             }
//     //去遍历city找到重要城市,用桶排序输出
//     for (int i = 1;i<=n;i++){
//         for(int j = 1;j<=n;j++){
//             if(city[i][j]!=0){
//                 book[city[i][j]] = 1;
//             }
//         }
//     }
//     //输出答案
//    int flag = 0;
//     for(int i = 1;i<=n;i++){
//         if(book[i]==1){
//             flag = 1;
//             printf("%d ",i);
//         }
//     }
//     if(flag==0){
//         printf("No important cities.");
//     }
// }


// #include<stdio.h>
// #include<stdlib.h>

// void gets_s_s(char * str, int num){
//     for(int i=0;i<num;i++){
//         char middle;
//         scanf("%c",&middle);
//         if(middle=='\n'){
//             break;
//         }
//         else{
//             str[i] = middle;
//         }
//     }
//     return;
// }




// int main(){
//     // char name[99] = {0};
//     // printf("start\n");
//     // gets_s_s(name,3);
//     // puts("fuck asshole!\n");
//     // printf("%s,ok",name);
//     // system("pause");
//     int t;
//     printf("start\n");
//     scanf("%c",&t);
//     printf("-------------------------");
//     printf("%d",t);
//     printf("--------------");
//     return 0;
// }
#include<stdio.h>

int main(){
//     char a[21] = {0,105,32,108,111,118,101,32,121,111,117,44,116,111,111,95,95,95,71,89,67};
// for(int i=1;i<=21;i++){
//     printf("%c",a[i]);
// }

// /*
// ****************
// * 空格检查      *
// ****************
// */               
// char ch1;
// char ch2;
// scanf("%c",&ch1);
// scanf("%c",&ch2);
// printf("%c\n",ch1);
// printf("--------------");
// printf("%c",ch2);
// printf("%d",ch2);

/*********
 * 第四章作业
 * 二题
*/   
int inum;
float uprice; 
int month;
int day;
int year;
printf("Enter item num :");
scanf("%d",&inum);
printf("Enter unit price:");
scanf("%f",&uprice);
printf("Enter purchase date (mm/dd/yyyy):");
scanf("%d /%d /%d",&month,&day,&year);

return 0;
}