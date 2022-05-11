#include <iostream>
#include <cmath>
using namespace std;
 
bool checkprime(int x);
int main()
{
    int m, n;
    cin >> m >> n;
    int num = 0;
    for (int i = m; i <= n - 2; i++)
        if (checkprime(i + 2) && checkprime(i))
            num++;
    cout << num;
    return 0;
}
bool checkprime(int x)
{
    if (x == 1) return false;
    int k = sqrt(x);
    for (int i = 2; i <= k; i++)
        if (x % i == 0)
            return false;
    return true;
}