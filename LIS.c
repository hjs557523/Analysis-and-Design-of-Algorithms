int LIS(int A[],int L[],int N)
{
	int len = 1;
	for (int i = 0; i < N; ++i)
	{
		L[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (A[j]<=A[i] && L[j]+1>L[i])
			{
				L[i] = L[j] + 1;
			}
			if (L[i]>len)
			{
				len = L[i];
			}
		}
	}
	return len;
}

void findSequence(int A[],int L[],int N,int len)
{
	int result[len];//存放最长上升子序列
	int len2 = len;
	int i = N-1;
	//找到最大上升子序列的末尾元素
	while (i>=0){
		if (L[i]==len){
			result[--len2]=A[i];
			break;
		}
		i--;
	}

	i--;//前面由于直接break没执行到i--
	
	while(len2>0){
		if ((L[i]==len2)&&(A[i]<result[len2]))
		{
			result[--len2] == A[i];
			i--;
		}
		else 
			i--;
	}

	for (int j = 0; j < len-1; ++j)
		printf("%d,", result[j]);
	printf("%d\n",result[len-1]);
}