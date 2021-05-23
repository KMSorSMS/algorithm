/*To practice what I have learned about dynamic array in multiple dimension
I am going to writing a code to enclose a function which can absorb 4 arguments
as your four dimention size and return the pointer of the 4 dimention array.
And also build a function to absorb the pointer of the 4 dimention array and 
print it's contents;*/

#include<stdio.h>
#include<stdlib.h>

int ****array(int size1,int size2,int size3,int size4)
{
    int ****array;
    //初始化
    array = (int ****)malloc(sizeof(int***)*size1);//array是四级指针；它是三级指针的地址，这里是为三级指针开辟空间；
    for(int i=0;i<size1;i++)
    {
        array[i] = (int ***)malloc(sizeof(int**)*size2);//这里是给三级指针赋值，为二级指针开辟空间；
        for(int j=0;j<size2;j++)
        {
            array[i][j] = (int **)malloc(sizeof(int)*size3);//这里是给二级指针赋值，为一级指针开辟空间；
            for(int k=0;k<size3;k++)
            {
                array[i][j][k] = (int *)malloc(sizeof(int)*size4);//这里是为一级指针赋值，为数字开辟空间；
                for(int m=0;m<size4;m++)
                {
                    // printf("\ninput your num\n");
                    // scanf("%d",&array[i][j][k][m]);//这里是为数字赋值； 
                    array[i][j][k][m] = i+j+k+m;//随便来了个初始化赋值；
                    printf("i'm in\n");
                }
            }
        }
    }
return array;
}
void print_array4(int ****array,int size1,int size2,int size3,int size4)
{
    for(int m=0;m<size4;m++)
    {
        for(int k=0;k<size3;k++)
        {
            for(int j=0;j<size2;j++)
            {
                for(int i=0;i<size1;i++)
                {
                    printf("%d ",array[i][j][k][m]);
                }
                printf("\n");
            }
            printf("\n\n");
        }
        printf("\n\n\n\n");
    }
}
int main()
{
    int ****a = array(2,2,2,2);
    print_array4(a,2,2,2,2);
    //printf("%d",a[0][0][0][1]);
    return 0;
}