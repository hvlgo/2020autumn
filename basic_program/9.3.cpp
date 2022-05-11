#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
 
float f();
int main()
{
    cout << fixed << setprecision(2) << f();
    return 0;
}
 
float f()
{
    char op[15] = {0};
    cin >> op;
    if (op[0] == '*')
        return f() * f();
    else if (op[0] == '+')
        return f() + f();
    else if (op[0] == '-')
        return f() - f();
    else if (op[0] == '/')
        return f() / f();
    else
    {
        float ans;
        sscanf(op, "%f", &ans);
        return ans;
    }
}