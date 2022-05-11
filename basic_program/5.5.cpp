#include <iostream>
using namespace std;

void print(int x[105], int y)
{
    for (int i = 1; i <= y; i++)
        cout << x[i] << ' ';
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int a[105] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cout << "Insert element[" << i << "]:" << endl;
        cout << "  Init:";
        print(a, i);
        if (i == 1)
        {
            cout << "  Final:"; 
            print(a, i);
        }
        else
        {
            int k = a[i];
            for (int j = i - 1; j > 0; j--)
            {
                if (a[j] > k)
                {
                    a[j + 1] = a[j];
                    cout << "  Move back:";
                    print(a, i);
                    if (j == 1)
                    {
                        a[1] = k;
                        cout << "  Final:";
                        print(a, i);
                    }
                }
                else
                {
                    a[j + 1] = k;
                    cout << "  Final:";
                    print(a, i);
                    break;
                }
                }
            }
        }
    return 0;
}