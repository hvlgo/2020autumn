#include <iostream>
#include <cmath>
using namespace std;
void printPrime(int num);    // 未定义，需要完成
 
int main() {
    int n, i;
    cin >> n;
    while (n --) {
        cin >> i;
        printPrime(i);
    }
    return 0;
}
void printPrime(int num)
{
    cout << num << "=";
    for (int i = 2; i <= num; i++)
    {
        if (num % i == 0)
        {
            cout << i;
            num /= i;
            if (num != 1)
            cout << "*";
            i--;
        }
    }
    cout << endl;
}