#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
 
int main()
{
    char a[50040] = {0};
    cin.getline(a, 50040);
    int len = strlen(a);
    int sum[30] = {0};
    for (int i = 0; i < len; i++)
        for (int j = 0; j < 26; j++)
        {
            if (a[i] == 'a' + j || a[i] == 'a' + j - 32)
                {
                    sum[j]++;
                    break;
                }
        }
    int summary = 0;
    for (int i = 0; i < 26; i++)
        summary += sum[i];
    for (int i = 0; i < 26; i++)
    {
        cout << char('a' + i) << ' ' << fixed << setprecision(2) << sum[i]*100/double(summary) << '%' << endl;
    }
    return 0;
}