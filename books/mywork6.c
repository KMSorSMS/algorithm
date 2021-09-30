#include <stdio.h>
#include <stdlib.h>

// int findrec(char *p, int start, int end,int num,int end_save)
// {
//     //base case;
//     if (p[end] == 0)
//     {
//         return num;
//     }

//     //save the end of last one;

//     while (p[end] != 0)
//     {
//         //when need to check;
//         if (p[start] == p[end])
//         {
//             //signal temp;
//             int start1, end1;
//             start1 = start;
//             end1 = end;

//             while (p[start1] == p[end1]&&end1 >= start1)
//             {
//                 start1++;
//                 end1--;
//             }
//             if (end1 <= start1)
//             {
//                 num = num > (end - start + 1) ? num : (end - start + 1);
//                 end_save = end;
//             }
//         }
//         end++;
//     }
//     num = findrec(p, start++, ++end_save,num,end_save);
//     return num;
// }

// void check_num(int start, int end, char *s, int map[100][100])
// {
//     int start_tem, end_tem;
//     start_tem = start;
//     end_tem = end;
//     //这里我用一个map来记录比较过是否时回文字符串的数据
//     while (s[start] == s[end] && start <= end)
//     {
//         start++;
//         end--;
//         if (map[start][end])
//         {
//             map[start_tem][end_tem] = 1;
//             return;
//         }
//     }
//     if (start >= end)
//     {
//         map[start_tem][end_tem] = 1;
//         return;
//     }
// }

// char *longestPalindrome(char *s)
// {
//     int start, end, end_save, num, end_p, start_p;
//     int map[100][100] = {0};
//     // int **map = calloc();
//     start = end = end_save = start_p = end_p = num = 0;
//     while (s[start] != 0)
//     {
//         if (s[end_save] == 0)
//         {
//             break;
//         }
//         end = end_save;
//         while (s[end] != 0)
//         {
//             end++;
//             if (s[end] == s[start])
//             {
//                 check_num(start, end, s, map);
//                 if (map[start][end])
//                 {
//                     end_save = end;
//                     if (num < (end - start + 1))
//                     {
//                         num = end - start + 1;
//                         end_p = end;
//                         start_p = start;
//                     }
//                 }
//             }
//         }
//         start++;
//     }
//     s[end_p + 1] = '\0';
//     return &s[start_p];
// }

// char * longestPalindrome(char * s){
//     int left = 0;
//     int right = 0;
//     int maxLength = 0;      //回文子串最大长度
//     int startIndex = 0;     //最长回文子串开始位置
//     int index = 0;

//     while(s[index]){
//         right=index;
//         left=index-1;

//         //从当前字符开始往右读取连续重复字符(连续重复字符必定能构成回文子串，也必定是回文子串的一部分)
//         //如"abcccd" 中从索引1开始的连续重复字符是"b"，从索引2开始连续重复字符是'ccc'
//         while(s[right]==s[index]){
//             right++;
//         }

//         //定位下一个子串的中心
//         index = right;

//         //以连续重复字符为中心，往左右延展,判断当前子串是否为回文子串
//         while(left >= 0 && s[right] && s[left]==s[right]){
//             left--;
//             right++;
//         }

//         //记录回文子串的最大长度和起始索引
//         if(right-left-1>maxLength){
//             startIndex = left+1;
//             maxLength = right-left-1;
//         }

//     }

//     //返回回文子串
//     char* returnStr = (char*)malloc(maxLength+1);
//     returnStr[maxLength]='\0';
//     for(int i=0;i<maxLength;i++){
//         returnStr[i]=s[startIndex+i];
//     }
//     return returnStr;

// }

//法一运用动态规划有以下要点
/*
1、两次遍历的循环顺序很重要，仔细品味；
2、理解动态规划的过程实际是填写一个二维表格，表格填写顺序是由状态转移方程决定的；
*/

char *longestPalindrome(char *s)
{
    //variable init
    int end, start;
    end = start = 0;
    int book[100][100] = {0};
    int num = 0;
    int end_p, start_p;
    //start loop
    //顺序是固定end走start;
    //因为填状态表时，是参考左下的数据；而且只要是长度大于3的序列，一定是去先前的book里找值（如果当前两头相等）
    while (s[end] != 0)
    {
        //当左边标记（start）小于右边标记（end）时开始循环
        while (s[start] != 0 && start < end)
        {
            //对于长度小于3的序列不用状态转移；
            if (end - start + 1 <= 3)
            {
                //直接判断回文序列；
                if (s[end] == s[start])
                {
                    //将此情况做出标记
                    book[start][end] = 1;
                    //判断回文长度；
                    if (num < (end - start + 1))
                    {
                        //记录起始位置；
                        num = end - start + 1;
                        start_p = start;
                        end_p = end;
                    }
                }
            }
            //用状态转移
            else
            {
                //判断成立否，若端头相等，看book有没有标记；
                if (s[end] == s[start] && book[start + 1][end - 1] == 1)
                {
                    book[start][end] = 1;
                    if (num < (end - start + 1))
                    {
                        num = end - start + 1;
                        //记录起始位置；
                        start_p = start;
                        end_p = end;
                    }
                }
            }
            start++;
        }
        //reset start;
        start = 0;
        end++;
    }
    s[end_p + 1] = '\0';
    return &s[start_p];
}

int main()
{
    char p[100] = "adsfasdababaaddd";
    printf("%s", longestPalindrome(p));
    return 0;
}