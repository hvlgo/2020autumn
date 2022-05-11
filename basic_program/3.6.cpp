#include <iostream>
#include <cmath>
using namespace std;
int getbit(int x);
int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    int a[105] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (k == 1)
            a[i] += x;
        if (k == 2)
            a[i] *= x;
        if (k == 3)
        {
            for (int j = 0; i < getbit(x); j++)
                a[i] *= 10;
            a[i] += x;
        }
        if (k == 4)
            if (i % 2)
                a[i] %= x;
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << endl;
    return 0;
}

int getbit(int x)
{
    if (x / 10 == 0) return 1;
    else if (x / 100 == 0) return 2;
    else if (x / 1000 == 0) return 3;
    else return 4;
}