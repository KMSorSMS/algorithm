#include<stdio.h>

int lenth(char *s)
{
    int l = 0;
    while(s[++l]!='\0');
    //比如index为2为\0则l在2时会退出
    return l;
}


int lengthOfLongestSubstring(char * s){


//  int start = 0, end = 0, maxlen = 0;
//     char map[256] = {0};
//     map[(int)*(s+start)] = 1;
    
//     while( *(s+end) != 0 )
//     {
//         maxlen = maxlen>(end-start+1)?maxlen:(end-start+1);
//         ++end;
//         while( 0 != map[ (int)*(s+end) ] )//将要加入的新元素与map内元素冲突
//         {
//             map[ (int)*(s+start) ] = 0;
//                ++start;
//         }
//         map[(int)*(s+end)] = 1;
//     }
    
//     return maxlen;


int thissum,maxsum,i,j;
thissum = maxsum = 0;
int n = lenth(s)-1;
for(j=0;j<=n;j++)
{
    thissum = 0;
    char map[256] = {0};

    for(i=j;i<=n;i++){
    if(map[(int)s[i]]!=0){
    maxsum = thissum>maxsum?thissum:maxsum;
    break;
    }
    thissum++;
    printf("now the sum is %d\n",thissum);
    map[(int)s[i]] = 1; 
    
    }
}


return maxsum;
// n = lenth(s);

// //if(n<=1)
// findlong(s,0,n-1);
// return max;
}
int main(){
    char a[2] = "";
    lengthOfLongestSubstring(a);
    return 0;
}
