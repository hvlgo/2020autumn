#include <iostream>
using namespace std;

int main()
{
    int cc1, cc2, cc3, cc4, cc5, cc6;
    for (int i = 63; i >= 0; i--)
    {
        int A = (i & 32) >> 5;
        int B = (i & 16) >> 4;
        int C = (i & 8) >> 3;
        int D = (i & 4) >> 2;
        int E = (i & 2) >> 1;
        int F = (i & 1) >> 0;
        cc1 = !A;
        cc2 = A ^ C;
        cc3 = !cc1 && !cc2;
        cc6 = F;
        cc4 = !cc3 && !cc6;
        cc5 = cc1 && cc4 && !cc2 && !cc3 && !cc6;
        if (cc1 + cc2 + cc3 + cc4 + cc5 + cc6 == 3 && A + B + C + D + E + F == 1)
        {
            cout << (A == 1 ? "A\n" : "");
            cout << (B == 1 ? "B\n" : "");
            cout << (C == 1 ? "C\n" : "");
            cout << (D == 1 ? "D\n" : "");
            cout << (E == 1 ? "E\n" : "");
            cout << (F == 1 ? "F\n" : "");
        }
    }
    return 0;
}