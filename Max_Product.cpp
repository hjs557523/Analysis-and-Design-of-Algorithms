#include <cstdio.h>
#include <math.h>
long long a[11][11],f[11][11];
long long s;
int n,i,k,k1,j;
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	scanf("%d%d",&n,&k1);
	scanf("%l64d",&s);
	//初始化a[i][j]矩阵
	for (i = n; i >= 1; --i)
	{
		a[i][i]=s%10;
		s/=10;
	}

	for (i = 1; i < n; ++i)
	{
		for (j = i+1; j <= n; ++j)
		{
			a[i][j]=a[i][j-1]*10+a[j][j];
		}
	}

	//初始化f[i][k]矩阵
	for (i = 1; i <= n; ++i)
		f[i][0]=a[1][i];
	for (k = 1; k <= k1; ++k)
		for (i = k+1; i <= n; ++i)
			for (j = k; j < i; ++j)
				f[i][k] = max(f[i][k],f[j][k-1]*a[j+1][i]);
			printf("%l64d\n", f[n][k1]);
	return 0;

}