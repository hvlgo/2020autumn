#include <iostream>
using namespace std;
 
 
int main()
{
    int n, num = 0, sum = 0;
    int a[105] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == -1)
                break;
            if (a[i] < 1000 && (a[i] % 3 == 0 || a[i] % 5 == 0) && num < 10)
            {
                sum += a[i];
                num++;
            }
        }
    cout << sum << endl;
    return 0;
}