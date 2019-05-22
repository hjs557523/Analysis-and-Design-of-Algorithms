#include <iostream>
#include <algorithm>
using namespace std;
//动态规划思路
//矩阵D(r,j)存放数字三角形,D(r,j)表示第 r 行第 j 个数字
//矩阵M(r,j)存放从 D(r,j) 到 底边 各条路径的最佳路径数字之和
/*假设D(r,j)是一个N行的矩阵，则递归公式如下:
  M(r,j) = D(r,j)                                 r = N
  M(r,j) = Max{ M(r+1,j), M(r+1,j+1)} + D(r,j)   其他情况
*/

void createDrj(int **Drj, int r)
{
    // 注:不能在调用函数里为二维数组指针申请内存空间,一旦函数退栈,其中的变量内存空间等都会被销毁
    // 函数里所有变量空间内容等都会销毁
    // Drj = (int**)malloc(sizeof(int*)*n);
    // for (int i = 0; i < n; i++)
    // {
    //     Drj[i] = (int*)malloc(sizeof(int)*n);
    // }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> Drj[i][j];
        }
    }
}

void initMrj(int **Mrj, int r)
{

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            Mrj[i][j] = -1;
        }
    }
}

void dp(int **Drj, int **Mrj, int n)
{
    for (int i = 0; i < n; i++)
    {
        Mrj[n-1][i] = Drj[n-1][i];
    }

    for (int i = n - 2; i >= 0 ; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            Mrj[i][j] = max(Mrj[i+1][j], Mrj[i+1][j+1]) + Drj[i][j];
        }
    }
    cout << "Max sum is: " << Mrj[0][0] << endl;
}

int main()
{
    int n;
    int **Drj;
    int **Mrj;
    cin >> n;

    Drj = (int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++)
    {
        Drj[i] = (int*)malloc(sizeof(int)*n);
    }
    createDrj(Drj, n);

    Mrj = (int **)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++)
    {
        Mrj[i] = (int*)malloc(sizeof(int)*n);
    }
    initMrj(Mrj, n);

    //debug
    // cout <<"debug"<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; i <= i; j++)
    //     {
    //         cout << Mrj[i][j];   
    //     }
    // }
    
    dp(Drj, Mrj, n);
    system("pause");
    return 0; 
}