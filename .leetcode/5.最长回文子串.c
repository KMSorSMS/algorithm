/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start

int lengthfind(char *s, int left, int right)
{

//注意数组越界；
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
    int L[2010] = {0};
    char *p = (char *)calloc(2010,sizeof(char));
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
        if(L[next]>num)
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
    char *re = (char *)calloc(1005,sizeof(char));
    for(int i = mid_save-num+1;p[i]!=0;i = i+2)
    {
        re[j] = p[i];
        j++;
    }
    free(s);
    free(p);
    return re;

}

// @lc code=end
