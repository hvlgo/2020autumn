#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int a[3] = {1, 2, 3};
    int cc1, cc2, cc3;
    do
    {
        int A = a[0];
        int B = a[1];
        int C = a[2];
        cc1 = (B > A) + (C == A);
        cc2 = (B < A) + (C < A);
        cc3 = (C > B) + (B > A);
        if (A + cc1 == 3 && B + cc2 == 3 && C + cc3 == 3)
            {
                for (int i = 0; i < 3; i++)
                    if (a[i] == 1)  cout << char('A' + i) << " ";
                for (int i = 0; i < 3; i++)
                    if (a[i] == 2)  cout << char('A' + i) << " ";
                for (int i = 0; i < 3; i++)
                    if (a[i] == 3)  cout << char('A' + i) << " ";
            }
    } while (next_permutation(a, a + 3));
    return 0;
}