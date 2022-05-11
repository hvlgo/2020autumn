#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int a[105] = {0};
    int num = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 1)
        {
            cin >> a[i];
            if (a[i] % 2 == 1)
            {
                int x = a[i];
                a[i] = x % 3;
                num += abs(x - a[i]);
            }
            cout << a[i] << " ";
        }
    }
    cout << endl << num;
    return 0;
}