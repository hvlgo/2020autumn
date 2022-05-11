#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
 
bool right(char s)
{
    if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9'))
        return true;
    return false;
}
int main()
{
    char a[105] = {0};
    int i = 0;
    char c;
    while ((c = getchar()) != EOF)
    {
        if (right(c))
            a[i++] = c;
    }
    int len = strlen(a);
    if (len == 0 || len == 1)
    {
        cout << 1;
        return 0;
    }
    bool found = true;
    for (int i = 0; i < len / 2; i++)
    {
        if (a[i] != a[len - i - 1] && a[i] != a[len - i - 1] + 32 && a[i] != a[len - i - 1] - 32)
           {
               found = false;
               break;
           }
    }
    if (found)
        cout << 1;
    else
        cout << 0;
    return 0;
}