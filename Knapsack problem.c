#include <stdio.h>
#include <memory.h>
void DP(int n,int W,int c[][18],int *v,int *wei){
	
	//当i=0或W=0时,c[i,W]=0                               
	memset(*c,0,(W+1)*sizeof(int));//第0行,i=0
	for (int i = 1; i <= n; ++i){
		c[i][0] = 0;//第0列,w=0
		for (int w = 1; w <= W; ++w){
			//当wi>w时,c[i,W]=c[i-1,W]
			if (wei[i-1] > W){
				c[i][w] = c[i-1][w];
			}
			//当i>0且wi≤W,c[i,W]=max{c[i-1,W-wi]+vi,c[i-1,W]}    
			else{
				int temp = c[i-1][w-wei[i-1]] + v[i-1];
				if (c[i-1][w] > temp){
					c[i][w] = c[i-1][w];
				}else{
					c[i][w] = temp;
				}
			}
		}
	}
}

void findPath(int c[][18],int *bag,int *wei,int n,int W)
{
	int w = W;
	for (int i = n; i >= 1; i--)
	{
		//说明物品i对总价值的最优解没有帮助,不能放或不必放
		if (c[i][w] == c[i-1][w])
		{
			bag[i-1] = 0;
		}
		//说明物品i对总价值的最优解有帮助,需要放进背包
		else{
			bag[i-1] = 1;
			w = w - wei[i-1];
		}
	}
}

int main()
{
	int n = 5;
	int W = 17;
	int w[] = {3,4,7,8,9};
	int v[] = {4,5,10,11,13};
	int c[6][18] = {0};
	DP(n,W,c,v,w);
	printf("%d\n",c[5][17]);
	int x[5];//物品是否放入背包,0不放,1放入
	findPath(c,x,w,n,W);
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n",x[i]);
	}
	return 0;
}