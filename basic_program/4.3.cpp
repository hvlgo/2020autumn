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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {   
        print1(n - i - 1);
        print2(i * 2 + 1);
        cout << endl;
    }
    for (int i = 0; i < n - 1; i++)
    {
        print1(i + 1);
        print2(2 * n - 3 - 2 * i);
        cout << endl;
    }
    return 0;
}