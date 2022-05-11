#include <iostream>
#include <cstring>
using namespace std;
 
int main()
{
    char a[105] = {0};
    cin >> a;
    int len = strlen(a);
    for (int i = len - 1; i >= 0; i--)
        cout << a[i];
    return 0;
}