#include<stdio.h>



int main(){
   int q[101] = {0,6,3,1,7,5,8,9,2,4};
   int f[10];
   int head = 1;int tail = 10;
   for(int i=1;head<tail;i++){
       f[i] = q[head];
       head++;
       q[tail] = q[head];
       tail++;
       head++;
   }
   for(int i=1;i<=9;i++){
       printf("%d ",f[i]);
   }
    return 0;
}