#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
    char a[5050] = {0};
    int num = 0;
    while (true)
    {
        char c = cin.get();
        if (c == -1)
            break;
        if (isalpha(c))
            a[num++] = c;
        else
        {
            for (int i = num - 1; i >= 0; i--)
                cout << a[i];
            cout << c;
            num = 0;
        }
    }
    return 0;
}