#include <iostream>
using namespace std;
 
char arry[25][25] = {0};
int n;
int x, y;
void w();
void s();
void a();
void d();
void print();
 
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            {
                cin >> arry[i][j];
                if (arry[i][j] == 'H')
                    x = i, y = j;
            }
    char op[1040] = {0};
    cin >> op;
    for (int i = 0; i < 1040; i++)
    {
        if (op[i] == 0) return 0;
        if (op[i] == 'w') w();
        if (op[i] == 's') s();
        if (op[i] == 'a') a();
        if (op[i] == 'd') d();
    }
    return 0;
}
 
void print()
{
    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << arry[i][j] << ' ';
            cout << endl;
        }
    cout << endl;
}
 
void w()
{
    if (x == 0)
    {
        print();
        return;
    }
    swap(arry[x][y], arry[x - 1][y]);
    x--;
    print();
    return;
}
 
void s()
{
    if (x == n - 1)
    {
        print();
        return;
    }
    swap(arry[x][y], arry[x + 1][y]);
    x++;
    print();
    return;
}
 
void a()
{
    if (y == 0)
    {
        print();
        return;
    }
    swap(arry[x][y], arry[x][y - 1]);
    y--;
    print();
    return;
}
 
void d()
{
    if (y == n - 1)
    {
        print();
        return;
    }
    swap(arry[x][y], arry[x][y + 1]);
    y++;
    print();
    return;
}