#include <iostream>
using namespace std;
 
int a[100500] = {0};
int b[100500] = {0};
void f(int start, int end);
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    f(0, n);
    return 0;
}
 
void f(int start, int end)
{
    if (start == end - 1)
        return;
    int k = (end + start) / 2;
    f(start, k);
    f(k, end);
    int m = start, n = k;
    int x = start;
    while (m < k && n < end)
    {
        if (a[m] < a[n])
            b[x++] = a[m++];
        else
            b[x++] = a[n++];
    }
    while (m < k)
        b[x++] = a[m++];
    while (n < end)
        b[x++] = a[n++];
    for (int i = start; i < end; i++)
    {
        a[i] = b[i];
        cout << b[i] << ' ';
    }
    cout << endl;
}