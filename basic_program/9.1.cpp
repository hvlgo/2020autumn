#include <iostream>
using namespace std;
 
int f(int x);
int main()
{
    int T;
    cin >> T;
    int x;
    while (T--)
    {
        cin >> x;
        cout << f(x) << endl;
    }
    return 0;
}
 
int f(int x)
{
    if (x == 1) return 1;
    if (x % 2)  return f((x - 1) / 2) + f ((x + 1) / 2);
    return f(x / 2);
}