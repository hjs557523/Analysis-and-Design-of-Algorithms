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
		if (Larr[Lindex] > Rarr[Rindex])
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


double optimizedStorage(int n,double *rate)
{
	double rateSum = 0;
	double track[n];

	for (int i = 0; i < n; ++i)
	{
		rateSum += rate[i];
	}

	for (int i = 0; i < n; ++i)
	{
		rate[i] = rate[i]/rateSum;
	}

	mergeSort(rate,0,n-1);

	if (n%2 == 1)//奇数个文件
	{
		int k = (n-1)/2;
		track[k] = rate[0];//概率最大的在中间磁道
		for (int i = k+1; i < n; ++i)
		{
			track[i] = rate[2*(i-k)];
		}

		for (int i = 0; i < k; ++i)
		{
			track[i] = rate[2*(k-i)-1];
		}
	}
	else if (n%2 == 0)//偶数个文件
	{
		int k = (n-1)/2;
		for (int i = k+1; i < n; ++i)
		{
			track[i] = rate[2*(i-k)-1];

		}
		for (int i = 0; i <= k; ++i)
		{
			track[i] = rate[2*(k-i)];
		}
	}

	double result = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			result += track[i]*track[j]*(j-i);
		}
	}
	return result;
}

int main()
{
	int n;
	scanf("%d",&n);
	double *rate;
	rate = malloc(sizeof(double)*n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf",&rate[i]);
	}

	double optimizedResult = optimizedStorage(n,rate);
	printf("%f\n",optimizedResult);
	
	return 0;
}