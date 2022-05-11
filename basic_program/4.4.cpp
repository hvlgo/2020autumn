#include <iostream>
using namespace std;
 
void print1(int n)
{
    for (int i = 0; i < n; i++)
        cout << " ";
}
 
void print2(int n)
{
    for (int i = 0; i < n; i++)
        cout << "*";
}
 
int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; i++)
    {
        if (i == 0 || i == a - 1)
            print2(b);
        else
        {
            cout << "*";
            print1(b - 2);
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}