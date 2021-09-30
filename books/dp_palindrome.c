//法一运用动态规划有以下要点
/*
1、两次遍历的循环顺序很重要，仔细品味；
2、理解动态规划的过程实际是填写一个二维表格，表格填写顺序是由状态转移方程决定的；
*/

#include <stdio.h>

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
                    book[end][start] = 1;
                    if (num < (end - start + 1))
                    {
                        //记录起始位置；
                        start_p = start;
                        end_p = end;
                    }
                }
            }
            start++;
        }
        end++;
    }
    s[end_p+1] = '\0';
    return &s[start_p];
}



int main()
{
    char p[7] = "a";
    printf("start\n");
    printf("%s", longestPalindrome(p));
    return 0;
}