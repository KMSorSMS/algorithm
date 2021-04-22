#include<stdio.h>
#include<string.h>


//First version done by myself;
/*
int main(){
    char a[101];
    int len,top;
    int mid;
    char p[101];
    top = 0;
    printf("input your checking words:\n");
    gets(a);
    len = strlen(a);

    if(len%2==0){
    mid = len/2 -1;
    
    for(int i = 0;i<=mid;i++){
        top++;
        p[top] = a[i];
    }
    for(int i = mid+1; i <= len-1; i++)
    {
       if(p[top] != a[i]){
       break; 
    }
    top--;
    }
    }
else{
    mid = (len+1)/2 - 1; 
    for(int i=0;i<=mid;i++){
        top++;
        p[top] = a[i]; 
    }
    top--;
    for(int i = mid+1;i<=len-1;i++){
        if(p[top]!=a[i]){
            break;
        }
        top--;
    }
    }

   if(top==0){
       printf("yes");
   } 
   else{
       printf("NO");
   } 
   return 0;
    
}



*/

//Compare with what the Author gives;
int main(){
    char a[101],s[101];
    int i,len,mid,next,top;         //初始化a：接收用户传入。s：形成栈堆数据。

    gets(a);
    len = strlen(a);
    mid = len/2 - 1;               //注意因为默认不是四舍五入所以奇数是往小了取，偶数就是中间处的索引值；

    top = 0;                       //栈的初始化；
    //将mid前面的字符依次入栈；
    for(i = 0;i <= mid;i++){
        s[++top] = a[i];          //把前半截存入s的1~...索引里面；ps：奇数就不会到中间处
    }

    //根据字符串的长度是奇数还是偶数从而找出另一半段的索引位置
    if(len%2 == 0){
        next = mid + 1;
    }
    else{
        next = mid + 2;//要跳过中间的位置（并不是直系的下一个）
    }
    //Start match
    for(i = next; i <= len-1;i++){
        if(a[i] != s[top]){
            break;
        }
        top--;
    }
    if(top==0){
        printf("yes!");
    }
    else{
        printf("No!");
    }
    return 0;
}