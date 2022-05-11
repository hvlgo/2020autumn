#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1000050
 
int a[MAX];
int num[25] = {0};
int getbit(int x)
{
    int len = 0;
    while (x)
    {
        len++;
        x /= 10;
    }
    return len;
}
int main()
{
    int n;
    cin >> n;
    int step = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        step = max(step, getbit(a[i]));
    }
    
    for (int i = 1; i <= step; i++)
    {
        int **arry = new int*[10];
        for (int j = 1; j <= n; j++)
        {
            int x = a[j] / pow(10, i - 1);
            x %= 10;
            x++;
            num[x]++;
        }
        for (int ii = 1; ii <= 10; ii++)
            arry[ii] = new int [num[ii] + 5];
        for (int ii = 1; ii <= 10; ii++)
        {
            num[ii] = 0;
        }
        for (int ii = 1; ii <= n; ii++)
        {
            int x = a[ii] / pow(10, i - 1);
            x %= 10;
            x++;
            arry[x][++num[x]] = a[ii];
        }
        int pos = 1;
        for (int j = 1; j <= 10; j++)
            for (int k = 1; k <= num[j]; k++)
            {
                a[pos++] = arry[j][k];
            }
        for (int j = 1; j <= n; j++)
            cout << a[j] << ' ';
        cout << endl;
        for (int j = 0; j < 10; j++)
            delete[] arry[j];
        delete arry;
    }
}