#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << fixed << setprecision(4) << 1 + 1 / (1 + 1 / (1 + 1 / 5.0));
    return 0;
}