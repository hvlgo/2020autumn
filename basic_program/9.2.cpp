#include <iostream>
using namespace std;
 
int f(int a, int b);
 
int main()
{
    int a, b;
    cin >> a >> b;
    if (a > b)
        cout << f(a, b);
    else
        cout << f(b, a);
    return 0;
}
int f(int a, int b)
{
    if (a % b == 0)
        return b;
    return f(b, a % b);
}