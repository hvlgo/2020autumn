#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    cout << fixed << setprecision(5) <<  sin(3.14159265 / 4) * sin(3.14159265 / 4) +
        sin(3.14159265 / 4) * cos(3.14159265 / 4) -
        cos(3.14159265 / 4) * cos(3.14159265 / 4);
    return 0;
}