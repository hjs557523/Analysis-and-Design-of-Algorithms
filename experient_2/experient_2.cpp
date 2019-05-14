#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

#define MAX 10000 //标识最大的可能整数

int val[500][500]; //最优扩展距离矩阵 val(i,j)=min{val(i-1,j)+k, val(i,j-1)+k, val(i-1,j-1)+dist(ai,bj)}
string strA;       //字符串A
string strB;       //字符串B
int k;             //定值k

//返回字符a和b的ASCII码的差的绝对值
int dist(char a, char b)
{
    return abs(a - b);
}

int dp()
{
    int lenA, lenB;
    int tmp;
    val[0][0] = 0;   //当strA和strB是空串时,最优扩展距离为 0
    lenA = strA.length() - 1;
    lenB = strB.length() - 1;
    //cout<<lenA<<endl; cmc 4
    //cout<<lenB<<endl; snmn 5

    for (int i = 0; i <= lenA; i++)
    {
        for (int j = 0; j <= lenB; j++)
        {
            if (i + j)
            {
                val[i][j] = MAX;

                //A串最后一个字符是空格,B串最后一个字符是字母
                tmp = val[i-1][j] + k;
                if (i && (tmp < val[i][j]))
                {
                    val[i][j] = tmp;
                }

                //A串最后一个字符是字母,B串最后一个字符是空格
                tmp = val[i][j-1] + k;
                if (j && (tmp < val[i][j]))
                {
                    val[i][j] = tmp;
                }

                //A串和B串最后一个字符都是字母
                tmp = val[i-1][j-1] + dist(strA[i],strB[j]);
                if ((i*j) && (tmp < val[i][j]))
                {
                    val[i][j] = tmp;
                }
                   
            }   
        }
    }
    return val[lenA][lenB];
}

int main()
{
    cin>>strA;
    cin>>strB;
    cin>>k;
    strA = ' ' + strA;
    strB = ' ' + strB;
    cout<<dp()<<endl;

    // for (int i = 0; i < strA.length(); i++)
    // {
    //     for (int j = 0; j < strB.length(); j++)
    //     {
    //         cout<<val[i][j]<<' ';
    //     }
    //     cout<<endl;
        
    // }
    
    system("pause");
    return 0;
}