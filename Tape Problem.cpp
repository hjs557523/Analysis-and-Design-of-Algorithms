#include <iostream>
#include <math.h>

using namspace std;
//归并排序——合并操作子操作函数
void Merge(double *arr,int p,int q,int r)
{
	int Llen = q - p + 1;
	int RLen = r - q;
	double Larr[Llen + 1];
	double RLen[RLen + 1];

	for (int i = 0; i < Llen; ++i)
	{
		Larr[i] = arr[p+i];
	}
	Larr[Llen] = INT_MAX;//哨兵

	for (int i = 0; i < RLen; ++i)
	{
		Rarr[i] = arr[q+1+i];
	}
	Rarr[RLen] = INT_MAX;//哨兵

	int Lindex = 0;
	int Rindex = 0;
	for (int i = 0; i < r-p+1; ++i)
	{
		if (Larr[Lindex] < Rarr[Rindex])
		{
			arr[p+i] = Larr[Lindex];
			Lindex++;
		}
		else
		{
			arr[p+i] = Rarr[Rindex];
			Rindex++;
		}
	}
}

//归并排序
void mergeSort(double* arr,int p,int r)
{
	if (p<r)
	{
		int q = (p + r)/2;
		mergeSort(arr,p,q);
		mergeSort(arr,q+1,r);
		Merge(arr,p,q,r);
	}
}


double optimizedStorage(int n,int *len,double *rate)
{
	double multiResult[n];

	//总读取概率
	double rateSum = 0;
	for (int i = 0; i < n; ++i)
	{
		rateSum += rate[i];
	}
	//每个程序的读取概率
	for (int i = 0; i < n; ++i)
	{
		rate[i] = rate[i]/rateSum;
	}

	//概率 长度 乘积
	for (int i = 0; i < n; ++i)
	{
		multiResult[i] = len[i]*rate[i];
	}

	//归并排序
	mergeSort(multiResult,0,n-1);

	//计算时间
	double SUM = 0;
	for (int i = 0; i < n; ++i)
	{
		SUM += multiResult[i]*(n-i);
	}

	return SUM;
}

int main()
{
	int n;
	int *len;
	double *rate;
	scanf("%d",&n);
	len = malloc(sizeof(int)*n);
	rate = malloc(sizeof(double)*n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&len[i]);
		scanf("%lf",&rate[i]);
	}

	double optimizedResult = optimizedStorage(n,len,rate);
	printf("%f\n",optimizedResult); 

}