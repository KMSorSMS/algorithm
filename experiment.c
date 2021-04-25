# include <stdio.h>
int main(void)
{
    char str[10];  //str是string的缩写, 即字符串
    printf("input your:\n");
    scanf("%s", str);  /*输入参数是已经定义好的“字符数组名”, 不用加&, 因为在C语言中数组名就代表该数组的起始地址*/
    printf("value is:%s\n", str);
    return 0;
}