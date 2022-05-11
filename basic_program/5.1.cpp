#include <iostream>
using namespace std;
bool checkSpecial(int i, int n);      // 未定义，需要完成
 
int main() {
    int n;
    cin >> n;
    for (int i = 10000; i < 1000000; i ++) {
        if (checkSpecial(i, n)) {
            cout << i << endl;
        }
    }
    return 0;
}
bool checkSpecial(int i, int n)
{
    int a, b, c, d, e, f;
    a = (i % 10);
    b = (i % 100) / 10;
    c = (i % 1000) / 100;
    d = (i % 10000) / 1000;
    e = (i % 100000) / 10000;
    f = (i % 1000000) / 100000;
    if (a + b + c + d + e + f != n)
        return 0;
    if (f == 0)
    {
        if ((a == e) && (b == d))
            return 1;
    }
    else
    {
        if ((a == f) && (b == e) && (c == d))
            return 1;
    }
    return 0;
}