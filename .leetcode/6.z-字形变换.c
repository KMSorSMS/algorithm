/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 */

// @lc code=start
char result[1000];

char * convert(char * s, int numRows){

    //建立一个二维数组进行变形
    char array_s[20][1000] = {"\0"};
    // //分配了空间过后还要初始化
    // char **array_s = (char **)calloc(numRows+1,sizeof(char *)); 
    // for(int i=0;i<numRows;i++){
    //     array_s[i] = (char *)calloc(1000,sizeof(char)); 
    // }
    
    //循环遍历字符，注意回环顺序,由j控制
    int i = 1;
    int j = 1;
    int p = 1;
    //flag是标志盒子向右走（flag=0）还是向左；
    int flag = 0;
    while (s[i - 1] != 0)
    {
        //把第i个字符放到第j个盒子里
        array_s[j][p] = s[i - 1];
        //盒子j的移动（重点）
        //在盒子到边界位置之前都是右移
        if (j < numRows && flag == 0)
        {
            j++;
        }

        else if (j > 1 && flag == 1)
        {
            j--;
        }
        //如果到了边界要反向flag
        else
        {
            if (flag == 1)
            {
                flag = 0;
                p++;
                j++;
            }
            else
            {
                flag = 1;
                p++;
                j--;
            }
        }
        //找下一个字符
        i++;
    }

    //定义盒子的位置
    int arry = 1;
    //定义盒子内部的索引
    int index = 1;
    for (int k = 0; k <= 1000; k++)
    {
        if (array_s[arry][index] != 0)
        {
            result[k] = array_s[arry][index];
            index++;
        }
        //如果是连着两个0说明到头了
        else if (array_s[arry][index + 1] == 0)
        {
            //换下一个盒子
            arry++;
            //复位index
            index = 1;
            //记得要减去k的增加
            k--;
        }
        //遇到了单个0，跳过这个往下找
        else
        {
            index++;
            k--; //因为后面的k会加但是现在的k处没有值
        }
        //如果盒子位置超过了，则结束循环
        if (arry > numRows)
        {
            break;
        }
    }
    return result;
}

// @lc code=end

