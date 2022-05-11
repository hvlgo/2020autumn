#include <iostream>
using namespace std;
#define MAX 105000
int f[MAX];
int a[MAX], b[MAX];
int m, n;
 
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        f[a[i]] = max(b[i], f[a[i]]);
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++)
        {
            if (f[i] && f[j])
            {
                int val = f[i] + f[j];
                if (i == j)
                    val += 233;
                f[i + j] = max(val, f[i + j]);
            }
        }
    cout << f[m];
    return 0;
}