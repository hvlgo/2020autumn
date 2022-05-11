#include <iostream>
using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = m; i < n; i++)
    {
        cout << char(i);
        if ((i - m + 1) % k == 0)   cout << endl;
    }
    return 0;
}