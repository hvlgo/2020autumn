#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    a /= 10;
    a %= 10;
    if (a == b)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}