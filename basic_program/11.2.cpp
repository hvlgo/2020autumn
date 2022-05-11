#include <iostream>
using namespace std;
 
int a[105] = {0};
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        int pos = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[pos])
                pos = j;
        }
        cout << "swap(a[" << i << "], a[" << pos << "]):";
        swap(a[i], a[pos]);
        for (int j = 0; j < n; j++)
            cout << a[j] << " ";
        cout << endl;
    }
    return 0;
}