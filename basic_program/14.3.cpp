#include <iostream>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    int a[15] = {0};
    int height = 0;
    for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > height) height = a[i];
        }
    char b[15][15] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < height + 1; j++)
            if (a[i] - j > 0)
                b[i][j] = '@';
            else
                b[i][j] = '.';
    for (int j = height; j >= 0; j--)
        {
            for (int i = 0; i < n; i++)
                cout << b[i][j];
            cout << endl;
        }
    return 0;
}