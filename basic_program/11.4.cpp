#include <iostream>
using namespace std;
 
int main()
{
    int N;
    cin >> N;
    int a[30][30] = {0};
    int x = 1, y = 1;
    int dx = 1, dy = -1;
    for (int i = 1; i <= N * N; i++)
    {
        a[x][y] = i;
        x += dx;
        y += dy;
        if (y == 0 && x <= N)
        {
            dx = -1;
            dy = 1;
            y = 1;
        }
        if (x == 0 && y <= N)
        {
            dx = 1;
            dy = -1;
            x = 1;
        }
        if (x > N)
        {
            dx = -1;
            dy = 1;
            x--;
            y += 2;
        }
        if (y > N)
        {
            dx = 1;
            dy = -1;
            x += 2;
            y--;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}