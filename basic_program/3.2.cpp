#include <iostream>
using namespace std;

int main()
{
    int cc1, cc2, cc3, cc4;
    for (int i = 0; i < 15; i++)
    {
        int A = (i & 8) >> 3;
        int B = (i & 4) >> 2;
        int C = (i & 2) >> 1;
        int D = (i & 1) >> 0;
        cc1 = !A;
        cc2 = D;
        cc3 = B;
        cc4 = !D;
        if (cc1 + cc2 + cc3 + cc4 == 1 && A + B + C + D == 1)
        {
            cout << (A == 1 ? "A" : "");
            cout << (B == 1 ? "B" : "");
            cout << (C == 1 ? "C" : "");
            cout << (D == 1 ? "D" : "");
        }
    }
    return 0;
}