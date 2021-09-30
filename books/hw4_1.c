
/**************
 * 第八章 数组**
 * ************
 */

// #include<stdio.h>

// int main(){
// int i,j,k;
//     //  /***
//     //  * 13题
//     //  * 我认为++i等于i+=1
//     // */
//     // int i = 1;
//     // int j = 2;
//     // int k = 0;
//     // i *= j*= k;
//     // printf("%d %d %d ",i,j,k);

//     // i = 1;
//     // // j = 1+(i+=1);
//     // printf("%d,%d,%d",i+=1,j,k);

// /**
//  * 第4题
//  *
// */
// // printf("Enter a num :");
// // scanf("%d",&i);
// // printf("in octal,you get :%o\n",i);

// // scanf("%ld%ld",&k,&j);
// // printf("%d%d",k,j);

// int n = 0;
// if(n%2 == 0){
//     printf("ok\n");
// }
// printf("n is between 1 and 10");
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// int main()
// {
//     int rand_num;
//     //{上下，左右}
//     char content[27];
//     //内容初始化
//     char a = 'A';
//     for (int i = 1; i <= 26; i++)
//     {
//         content[i] = a + i - 1;
//     }
//     int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//     printf("%d:-1,%d:1,%d:0\n", direction[0][0], direction[3][1], direction[2][0]);
//     char map[10][10] = {0};
//     for (int i = 0; i < 10; i++)
//     {
//         for (int j = 0; j < 10; j++)
//         {
//             map[i][j] = '#';
//         }
//     }

//     srand((unsigned int)time(NULL));

//     int book0[10][10] = {0};
//     int x = 0;
//     int y = 0;
//     int next;
//     int next_x;
//     int next_y;
//     int conten = 1;
//     map[y][x] = content[conten];
//     //开始移动
//     while (1)
//     {

//         //尝试4个方向
//         int book1[4] = {0};
//         int count = 0;
//         int flag = 0;
//         for (int i = 1; i <= 4; i++)
//         {

//             //找到下一个方向

//             while (1)
//             {
//                 next = rand() % 4;
//                 if (book1[next] == 0)
//                 {
//                     //标记
//                     book1[next] = 1;
//                     count++;
//                     break;
//                 }
//             }

//             //出循环意味着找到非重复的next
//             next_y = direction[next][0] + y;
//             next_x = direction[next][1] + x;
//             //接下来看next方向是否可行
//             if (map[next_y][next_x] == '#' && next_y <= 9 && next_y >= 0 && next_x <= 9 && next_x >= 0)
//             {
//                 y = next_y;
//                 x = next_x;
//                 conten++;
//                 if (conten >= 27)
//                 {
//                     conten -= 26;
//                 }
//                 map[y][x] = content[conten];

//                 flag = 1;
//                 break;
//             }
//         }

//         //      for(int i=0;i<10;i++){
//         //     for(int j=0;j<10;j++){
//         //         printf("%c",map[i][j]);
//         //     }
//         //     printf("\n");
//         // }
//         // printf("-----------------\n");

//         //判断是不是被封住了
//         if (count == 4 && flag == 0)
//         {
//             break;
//         }
//         //判断是不是到边界了
//         else if (y == 9)
//         {
//             break;
//         }
//     }
//     //打印数组检查
//     for (int i = 0; i < 10; i++)
//     {
//         for (int j = 0; j < 10; j++)
//         {
//             printf("%c", map[i][j]);
//         }
//         printf("\n");
//     }

//     // rand_num = rand() % 4;
//     // for (int i = 1; i <= 10; i++)
//     // {
//     //     printf("%d", rand() % 4);
//     // }
// }

/**
 * Hw
 * 收获：
 * 将ASCII的值减去40得到对应的数组下标
 * \n和' '是不一样的字符
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    signed int book[60] = {0};
    char *str1;
    char *str2;
    int str_len;
    printf("Input your string length: ");
    scanf("%d", &str_len);

    getchar(); //是把\n读取去掉

    str1 = (char *)malloc(sizeof(char) * str_len);
    str2 = (char *)malloc(sizeof(char) * str_len);

    printf("input your first String:");
    for (int i = 0; i < str_len; i++)
    {
        char temp;
        temp = getchar();
        //如果想提前终止，敲下回车
        //注意此时的字符终止处取0
        if (temp == '\n')
        {
            str1[i] = 0;
            break;
        }
        //对于小写字母转大写字母
        if(temp>=97){
            temp -= 32;
        }
        str1[i] = temp;
    }

    getchar();

    printf("input your second String:");
    for (int i = 0; i < str_len; i++)
    {
        char temp;
        temp = getchar();
        if (temp == '\n')
        {
            str2[i] = 0;
            break;
        }
        if(temp>=97){
            temp -= 32;
        }
        str2[i] = temp;
    }
    
    str1[str_len] = 0;
    str2[str_len] = 0;
    printf("-----%s\n%s-------\n", str1, str2);

    getchar();
    for (int i = 0; i < str_len; i++)
    {
        book[str1[i] - 65]++;
        book[str2[i] - 65]--;
    }
    char flag = 0;
    for (int i = 0; i < str_len; i++)
    {
        if (book[i] != 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag != 0)
    {
        printf("not the same chars");
    }
    else
    {
        printf("Yes,the same");
    }
}