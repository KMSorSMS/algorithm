#include<stdio.h>

struct queue
{
    int data[100];
    int head;
    int tail;
};

int main(){
    printf("Start!");
struct queue q;
q.head = 1;
q.tail = 10;
int n;
printf("Please input your target size:\n");
scanf("%d",n);
printf("Now set your encoded number:");
for(int i = 1;i<=n;i++){
scanf("%d",q.data[i]);
}
while(q.head<q.tail){
    printf("%d",&q.data[q.head]);
    q.head++;
    q.data[q.tail] = q.data[q.head];
    q.tail++;
    q.head++; 
}
return 0;
}