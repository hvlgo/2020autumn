#include <iostream>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    char** a = new char*[2*n+5];
    for (int i = 1; i <= 2 * n + 4; i++)
        a[i] = new char[2 * n + 5];
    for (int i = 1; i <= 2 * n - 1; i++)
        for (int j = 1; j <= 2 * n - 1; j++)
            a[i][j] = '.';
    for (int i = 1; i <= n; i++)
    {
        a[i][i] = 'A' + i - 1;
        a[i][n] = 'A' + i - 1;
        a[i][2 * n - i] = 'A' + i - 1;
        a[n][i] = 'A' + i - 1;
        a[n][2 * n - i] = 'A' + i - 1;
        a[2 * n - i][i] = 'A' + i - 1;
        a[2 * n - i][n] = 'A' + i - 1;
        a[2 * n - i][2 * n - i] = 'A' + i - 1;
    }
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        for (int j = 1; j <= 2 * n - 1; j++)
            cout << a[i][j];
        cout << endl;
    }
    return 0;
}