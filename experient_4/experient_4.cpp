#include <stdio.h>
#include <stdlib.h>

//c++
//int a, int &b = a;
//声明了b是a的引用,经过这样的声明后使用a或b的作用相同，都代表同一变量,代替地址的传递，更加简单
void getMaxAndSmax(int left, int right, int *arr, int &max, int &smax)
{
    int lmax, lsmax, rmax, rsmax;
    int mid;
    if (left == right)
    {
        max = arr[left];
        smax = arr[left];
    }
    else if (left == right - 1)
    {
        if (arr[left] < arr[right])
        {
            max = arr[right];
            smax = arr[left];
        }
        else
        {
            max = arr[left];
            smax = arr[right];
        }
    }
    else
    {
        mid = (left + right) / 2;
        getMaxAndSmax(left, mid, arr, lmax, lsmax);
        getMaxAndSmax(mid + 1, right, arr, rmax, rsmax);
        if (lmax > rmax)
        {
            if (lsmax > rmax)
            {
                max = lmax;
                smax = lsmax;
            }
            else
            {
                max = lmax;
                smax = rmax;
            }
        }
        else
        {
            if (rsmax > lmax)
            {
                if (rmax == rsmax)
                {
                    max = rmax;
                    smax = lmax;
                }
                else
                {
                    max = rmax;
                    smax = rsmax;
                }
            }
            else
            {
                max = rmax;
                smax = rsmax;
            }
        }
    }
}

int main()
{
    int n;
    int *arr;
    int max;
    int smax;
    printf("Please input the length of the array\n");
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    printf("Please enter an array element\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    getMaxAndSmax(0, n - 1, arr, max, smax);
    printf("max value is: %d\n", max);
    printf("second max value is: %d\n", smax);
    return 0;
}
