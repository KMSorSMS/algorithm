/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 鏃犻噸澶嶅瓧绗︾殑鏈€闀垮瓙涓�
 */

// @lc code=start
// int max,n,charac;
// int book_main[150] = {0};//瀵逛簬瀵绘壘鏈€澶х殑璧版硶鐨勮褰曢噸澶嶏紱
int lenth(char *s)
{
    int l = 0;
    while(s[l++]!='\0');
    //姣斿index涓�2涓篭0鍒檒鍦�2鏃朵細閫€鍑�
    return l-1;
}

// int findlong(char *s,int left,int right)
// {
// //base condition
// if(n<=0){

// }
// int mid = (left +right)/2;
// int leftmax = findlong(s,left,mid);
// int rightmax = findlong(s,mid+1,right);
// //杩欐槸鎶婇棶棰樺垎鎴愬彧鍦ㄥ崟鐙竴杈规湁鏈€澶у瓙闆嗘垨鑰呭湪涓棿浜ゅ弶鍦板甫鍑虹幇鏈€澶у瓙闆嗕袱涓儴鍒嗭紱
// //鐜板湪瑙ｅ喅鍙湁涓棿鏃舵渶澶х殑鎯呭喌锛�
// int book = book_main;//鍚告敹book_main閲岄潰鐨勬暟鎹紝鍦ㄦ鍩虹涓婅繘琛屾煡閲�;
// //浠庝腑闂村悜宸︼紱
// int mid_l = mid;
// int mid_r = mid;
// int midmax = 0;
// while (book[(int)s[mid_l]]!=0)
// {
//     book[(int)s[mid_l]] = 1;//鏍囪姝ょ偣宸茬粡鍑虹幇锛�
//     mid_l--;
//     midmax++;
// }
// //浠庝腑闂村線鍙筹紱
// while (book[(int)s[mid_l+1]]!=0)
// {
    
// }




// }

int lengthOfLongestSubstring(char * s){


 int start = 0, end = 0, maxlen = 0;
    char map[256] = {0};
    map[(int)*(s+start)] = 1;
    
    while( *(s+end) != 0 )
    {
        maxlen = maxlen>(end-start+1)?maxlen:(end-start+1);
        ++end;
        while( 0 != map[ (int)*(s+end) ] )
        {
            map[ (int)*(s+start) ] = 0;
               ++start;
        }
        map[(int)*(s+end)] = 1;
    }
    
    return maxlen;


int thissum,maxsum,i,j;
thissum = maxsum = 0;
int n = lenth(s)-1;
for(j=0;j<=n;j++)
{
    thissum = 0;
    int map[1000] = {0};

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
// @lc code=end

