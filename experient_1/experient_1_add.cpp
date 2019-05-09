#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

void findMinMax(int *arr, int left, int right, int *min, int *max)
{
    if((right - left) == 1)
    {
        if(arr[left] < arr[right])
        {
            *min = arr[left];
            *max = arr[right];
        }
        else
        {
            *min = arr[right];
            *max = arr[left];
        }
    }
    else if((right - left) == 0)
    {
        *min = *max = arr[left];
    }
    else
    {
        int min1,min2,max1,max2;
        int mid = (right - left)/2;
        findMinMax(arr, left, mid + left, &min1, &max1);
        findMinMax(arr, mid + 1 + left, right, &min2, &max2);
        *min = min1 < min2? min1 : min2;
        *max = max1 > max2? max1 : max2;
    }
}

int main(void)
{
    int *arr;
    int n, min, max, i;
    cout <<"Please enter the length of the random array:"<< endl;
    cin >> n;
    arr = (int *)malloc(sizeof(int)*n);
    srand(time(0));
    for (i = 0; i < n; i++)
    {
        arr[i] = rand()%100;//取100以内的随机数
        cout << arr[i] << "  ";
    }
    cout << endl;
    findMinMax(arr, 0, i - 1, &min, &max);
    cout << "The minimum value is: " << min << endl ;
    cout << "The maximum value is: " << max << endl ;
    return 0;
}