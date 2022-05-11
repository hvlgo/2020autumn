#include <iostream>
using namespace std;

int main()
{
    int cc1, cc2, cc3, cc4;
    for (int i= 0; i < 16; i++)
    {
        int A = (i & 8) >> 3;
        int B = (i & 4) >> 2;
        int C = (i & 2) >> 1;
        int D = (i & 1);
        cc1 = !A;
        cc2 = B;
        cc3 = !B;
        cc4 = C;
        if (cc1 + cc2 + cc3 + cc4 == 3 && A + B + C + D == 1)
        {
            cout << (A ? "A" : "");
            cout << (B ? "B" : "");
            cout << (C ? "C" : "");
            cout << (D ? "D" : "");
        }
    }
    return 0;
}