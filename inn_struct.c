 #include<stdio.h>

struct queue
{
    int data[100];
    int head;
    int tail;
};

 int main(){
printf("Start!\n");
struct queue q;
q.head = 1;
q.tail = 10;
int n;

printf("Please input your target size:\n");
scanf("%d",&n);
printf("Now set your encoded number:\n");
for(int i = 1;i<=n;i++){
scanf("%d",&q.data[i]);
printf("%d \n",q.data[i]);
}
printf("-----------\n");

for(int i = 1;i<=n;i++){
printf("%d ",q.data[i]);
}
printf("-----------\n");
while(q.head<q.tail){
    printf("%d ",q.data[q.head]);
    q.head++;
    q.data[q.tail] = q.data[q.head];
    q.tail++;
    q.head++;  
}
 return 0;
 }
