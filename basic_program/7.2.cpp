#include <iostream>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    int a[25][25] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[j][n-i-1];
    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << a[i][j] << ' ';
            cout << endl;
        }
    return 0;
}