#include <iostream>
using namespace std;
 
int add(int x)
{
    if (x == 10)
            x = 1;
        else
            x++;
    return x;
}
 
int main()
{
    int a[15] = {0};
    int pos = 1, m = 0, n = 0;
    while (a[pos] == 0 && n < 9)
    {
        m++;
        while (a[add(pos)] == 1)
                pos = add(pos);
        pos = add(pos);
        if (m == 5)
            {
                m = 0;
                a[pos] = 1;
                n++;
            
                while (a[add(pos)] == 1)
                    pos = add(pos);
                pos = add(pos);
            }
    }
    for (int i = 1; i <= 10; i++)
        if (!a[i])
            cout << i;
    return 0;
}