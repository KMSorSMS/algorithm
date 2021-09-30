#include <stdio.h>
#define Max 99999

int m, n, u, v, w, ans = 99999; //n个点，m条线，暂存所给两点的u，v及两点之间的权值w，ans则记录最小环

int a[105][105], f[105][105]; //储存两张图

int main()
{
  int m, n, u, v, w, ans = 99999; //n个点，m条线，暂存所给两点的u，v及两点之间的权值w，ans则记录最小环

  int a[105][105], f[105][105]; //储存两张图,a是更新图，f是保存原图

  //给点、线个数
  scanf("%d %d", &n, &m);

  //初始化图
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {

      a[i][j] = Max;
      a[j][i] = Max;
      f[i][j] = Max;
      f[j][i] = Max;
    }
  }
  //输入参数
  for (int i = 1; i <= m; i++)
  {
    scanf("%d %d %d", &u, &v, &w);
    //w要够小才能更新
    if (a[u][v] >= w)
    {
      a[u][v] = w;
      a[v][u] = w;
      f[u][v] = w;
      f[v][u] = w;
    }
  }
  //开始用Floyd
  for (int k = 1; k <= n; k++)
  {
    //先用旧图对中转点进行动态得到最小环ans
    //即：
    /*
    环里面包含k，且k以后的点不在环里面的最小环
    */
    for (int q = 1; q < k; q++)
    {
      for (int p = q + 1; p < k; p++)
      {
        // if(p==k||q==k){continue;}
        if (a[p][q] + f[p][k] + f[k][q] < ans)
        {
          ans = a[p][q] + f[p][k] + f[k][q];
        }
      }
    }

    //将k处作为中转点更新值
    for (int i = 1; i <= n; i++)
    {
      for (int j = i + 1; j <= n; j++)
      {
        //当中转点够小就更新
        if (a[i][j] > a[i][k] + a[k][j])
        {
          a[i][j] = a[i][k] + a[k][j];
          a[j][i] = a[i][j];
        }
      }
    }
  }

  if (ans != Max)
  {
    printf("%d", ans);
  }
  else
  {
    printf("No solution.");
  }
  getchar();getchar();
  return 0;
}