#include <iostream>
using namespace std;
 
struct node
{
    int val;
    char name[25];
};
 
node a[105];
 
int num[2005];
node res[2005][200];
 
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> a[i].name;
        cin>> x >> y;
        a[i].val = x*100 + y;
    }
    for (int i = 1; i <= n; i++)
    {
        res[a[i].val][num[a[i].val]++] = a[i];
    }
    for (int i = 1; i <= 2000; i++)
    {
        if (num[i] >= 2)
        {
            cout << i / 100 << ' ' << i % 100 << ' ';
            for (int j = 0; j < num[i]; j++)
            {
                cout << res[i][j].name << ' ';
            }
            cout << endl;
        }
    }
}