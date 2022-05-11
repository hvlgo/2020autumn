#include <iostream>
using namespace std;
 
int num;
int water[15] = {0};
int water_n;
 
void Try(int h);
bool unsafe(int n);
 
int main()
{
    int height;
    cin >> height >> water_n;
    for (int i = 0; i < water_n; i++)
        cin >> water[i];
    num = 0;
    Try(height);
    cout << num;
    return 0;
}
 
void Try(int h)
{
    if (h == 0)
    {
        num++;
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        int newh = h - i;
        if (unsafe(newh))
            continue;
        Try(newh);
    }
}
 
bool unsafe(int n)
{
    if (n < 0)
        return true;
    for (int i = 0; i < water_n; i++)
    {
        if (n == water[i])
            return true;
    }
    return false;
}