/*本段程序尝试manarcher算法解最长回文串问题；
思路：
1（将奇数偶数的情况归一处理）、加入‘#’字符将原来的字符串扩展成奇数。
2（利用回文字符串的对称性）、为了利用之前的搜索结果，在前一个对称中心点的臂长范围的下一个点，它的对称
点（在左边，因为从左向右在记录数据），的臂长如果较小（未超出前一中心点的臂长范围），则它就从臂长加一的位置开始继续中心扩散
注意：如果该对称点没有臂长，那明显此点就不是回文中心；
而且，想想看，要是对称点的臂长没有超出前一个点的对称中心的臂长，说明该点回文臂长就是该对称点的

这种就需要一个数组记录臂长，只要值大于0，就是有臂长，那它的对称位置就可以开始中心扩散；
*/
// #include <stdio.h>
// #include <string.h>
// char p[2002];
// char re[1000];
// //这里是把寻找对称中心臂长过程包装为一个函数；
// int lengthfind(char *s, int left, int right)
// {

//     while (s[left] == s[right]&&left>=0)
//     {
//         left--;
//         right++;
//     }
//     return ((right - left) / 2) - 1;
// }

// int min(int a, int b)
// {
//     if (a > b)
//     {
//         return b;
//     }
//     else
//     {
//         return a;
//     }
// }
// char *init_char(char *s)
// {
//     int i = 0;
    
//     p[i] = '#';
//     while(s[i]!=0){
//         p[2*i+1] = s[i];
//         p[2*i+2] = '#';
//         i++;
//     }
//     return p;
// }

// char *longestPalindrome(char *s)
// {
//     int mid_save;
//     int L[100] = {0};

//     int next = 2;
//     int num = 0;
//     int mid = 1;
//     L[mid] = 1;
//     //进入循环寻找每一个(通过回文性质结合动态规划减少检查回文）对称中心
//     while (s[next] != 0)
//     {
//         //应该是在前一个点的臂长里面遍历；将该点记录为mid;
//         //int mid = 1;
//         //扔进找臂长的函数；
//         L[next] = lengthfind(s, next - min(L[2 * mid - next], L[mid] + mid - next) - 1, next + min(L[2 * mid - next], L[mid] + mid - next) + 1); //根据前一个点找到臂长；
//         // num = L[next] > num ? L[next] : num;
//         if(L[next]>num)
//         {
//             num = L[next];
//             mid_save = next;
//         }
//         //如果此时的臂长够大，移动mid；
//         mid = mid + L[mid] > next + L[next] ? mid : next;
//         //哪怕mid移到next的位置，next++后next比mid大
//         next++;
//     }
//     s[mid_save+num+1] = '\0';
//     int j = 0;
//     for(int i = mid_save-num+1;s[i]!=0;i = i+2)
//     {
//         re[j] = s[i];
//         j++;
//     }
//     return re;

// }



#include <stdio.h>
#include <string.h>
#include<stdlib.h>

//这里是把寻找对称中心臂长过程包装为一个函数；

//这里是把寻找对称中心臂长过程包装为一个函数；
int lengthfind(char *s, int left, int right)
{

    while (left>=0&&s[right]!=0&&s[left] == s[right])
    {
        left--;
        right++;
    }
    return ((right - left) / 2) - 1;
}

int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
void init_char(char *s,char *p)
{
    int i = 0;
    
    p[i] = '#';
    while(s[i]!=0){
        p[2*i+1] = s[i];
        p[2*i+2] = '#';
        i++;
    }
}

char *longestPalindrome(char *s)
{

    int mid_save;
    int L[1000] = {0};
    char p[2002];
    init_char(s,p);
    int next = 2;
    int num = 1;
    int mid = 1;
    L[mid] = 1;
    mid_save = mid;//初始化的midsave和mid重合
    
    //进入循环寻找每一个(通过回文性质结合动态规划减少检查回文）对称中心
    while (p[next] != 0)
    {
        //应该是在前一个点的臂长里面遍历；将该点记录为mid;
        //int mid = 1;
        //扔进找臂长的函数；
        L[next] = lengthfind(p, next - min(L[2 * mid - next], L[mid] + mid - next) - 1, next + min(L[2 * mid - next], L[mid] + mid - next) + 1); //根据前一个点找到臂长；
        // num = L[next] > num ? L[next] : num;
        if(L[next]>=num)
        {
            num = L[next];
            mid_save = next;
        }
        //如果此时的臂长够大，移动mid；
        mid = mid + L[mid] > next + L[next] ? mid : next;
        //哪怕mid移到next的位置，next++后next比mid大
        next++;
    }
    p[mid_save+num+1] = '\0';
    int j = 0;
    char *re = (char *)calloc(1000,sizeof(char));
    for(int i = mid_save-num+1;p[i]!=0;i = i+2)
    {
        re[j] = p[i];
        j++;
    }
    return re;

}


int main()
{
    char p[7] = "a";
    printf("start\n");
    printf("%s", longestPalindrome(p));
    return 0;
}