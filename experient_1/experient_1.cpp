#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

//用户输入待排序的随机数的个数
int *userInput(int n)
{
    srand(time(0));   
    int *arr = (int *)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand()%100; //为数组元素赋值0~100
    }
    return arr;
}

//随机数排序结果输出
void resOutput(int *arr, int n)
{
    int i;
    for(i = 0; i < n-1; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << arr[i];
    cout << endl;
}

//选择排序
int sort(int *arr, int length)
{
    if(length == 0)
    {
        return 0;
    }
    for(int i = 0; i < length; i++)
    {
        for(int j = i + 1; j < length; j++)
        {
            if(arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return 0;
}

//数组复制
void arrCopy(int *arrSrc, int *arrDest, int length)
{
    for(int i = 0; i < length; i++)
    {
        arrDest[i] = arrSrc[i];
    }
}

//相邻组别,两两合并
void merge(int *arr, int left1, int right1, int left2, int right2)
{
    int length1 = right1 - left1 + 1;
    int length2 = right2 - left2 + 1;

    int *arr1 = (int*)malloc(sizeof(int)*length1);
    int *arr2 = (int*)malloc(sizeof(int)*length2);
    int *arr3;

    if(left1 < left2)
    {
        arr3 = arr + left1;
    }
    else
    {
        arr3 = arr + left2;
    }

    arrCopy(arr + left1, arr1, length1);
    arrCopy(arr + left2, arr2, length2);

    int i = 0;
    int p = 0;//数组arr1的下标指针
    int q = 0;//数组arr2的下标指针
    while (p < length1 && q < length2)
    {
        if (arr1[p] < arr2[q])
        {
            arr3[i] = arr1[p];
            p++;
            i++;
        }
        else
        {
            arr3[i] = arr2[q];
            q++;
            i++;
        }
    }

    if (p == length1)
    {
        while (q < length2)
        {
            arr3[i] = arr2[q];
            q++;
            i++;
        }
    }
    else
    {
        while (p < length1)
        {
            arr3[i] = arr1[p];
            p++;
            i++;
        }
    }
    free(arr1);
    free(arr2);
}

//根号n段归并排序
void mergeSort(int *arr, int left, int right)
{
    //分解：
    int length = right - left + 1;   //待排序数组长度
    int group =  (int)sqrt(length);  //分组数量

    if (length > 3) //分组2组及以上的情况
    {   
        int groupLeft, groupRight;
        //解决：
        for (int i = 0; i < group - 1; i++)
        {
            groupLeft = left + group * i;
            groupRight = groupLeft + group - 1;
            mergeSort(arr,groupLeft,groupRight);
        }
        mergeSort(arr, groupRight + 1, right);
    }
    else //只能分成1组的情况
    {
        //解决：
        int *pleft = arr + left;
        sort(pleft,length);
    }
    
    //合并：
    int left1 = left;
    int right1 = left + group - 1;
    int left2,right2;
    for (int i = 1; i < group - 1; i++)
    {
        left2 = left + group * i;
        right2 = left2 + group - 1;
        merge(arr, left1, right1, left2, right2);
        right1 += group;
    }
    merge(arr,left1,right1,right1 + 1,right);    
}


int main()
{
    int n;
    cout <<"Please enter the number of random Numbers to be sorted" <<endl;
    cin >> n;
    int *arr = userInput(n);
    cout <<"Before sorting"<<endl;
    resOutput(arr,n);
    mergeSort(arr,0,n-1);
    cout <<"After sorting"<<endl;
    resOutput(arr,n);
    free(arr);
    system("pause");
    return 0;
}