#include <iostream>
#define maxn 1005
using namespace std;

int a[maxn];

void qsort(int l, int r)
{
    if (l >= r)
        return;

    int x = l, y = r;

    int k = a[l];
    do
    {
        while (l < r && a[r] > k) r--;
        if (l < r) a[l++] = a[r];
        while (l < r && a[l] <= k) l++;
        if (l < r) a[r--] = a[l];
    } while (l != r);
    a[l] = k;

    qsort(x, l - 1);
    qsort(l + 1, y);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    qsort(1, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
}