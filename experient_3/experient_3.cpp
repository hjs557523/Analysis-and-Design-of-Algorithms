#include <stdio.h>
#include <algorithm>
using namespace std;

//贪心算法计算最优值
//贪心策略：每次选长度最小的两个序列合并,得到最少比较次数。
int greedyAlgorithm(int* a, int size)
{
    int* b;
    int minSum = 0;
    b = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        b[i] = a[i];
    }
    while (size > 1)
    {
        sort(b, b + size);  //对数组地址从 b 到 b+m-1 的元素进行从小到大排序
        printf("{%d,%d} ",b[0],b[1]);
        b[0] = b[0] + b[1]; //选择所有序列中长度最小的两个序列，合并成一个新的序列
        minSum += b[0] - 1;  //计算比较次数
        for (int i = 1; i < size - 1; i++)
        {
            b[i] = b[i + 1];
        }
        size--;
    }
    printf("\n");
    return minSum;
}

int main()
{
    int n;
    int* a;
    int minSum;
    printf("Please enter the number of ordered sequences to be merged:\n");
    scanf("%d",&n);
    a = (int*)malloc(sizeof(int) * n);
    printf("Please enter the length of each ordered sequence in turn:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The merge order of an ordered sequence is:\n");
    minSum = greedyAlgorithm(a, n);
    printf("The minimum total number of comparisons determined by the greedy algorithm is:\n");
    printf("%d\n",minSum);
    system("pause");
    return 0;
}
