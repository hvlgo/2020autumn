#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
vector<int> a;
int main()
{
    for (int i = 1; i <= 6; i++)
    {
        int x;
        cin >> x;
        if (x % 3 == 0 && x % 2 == 1)
        a.push_back(x);
    }
    int sum = 0;
    if (!a.empty())
    {
        for (auto it : a)
        sum += it;
        sum /= a.size();
        cout << fixed << setprecision(4) << double(sum);
    }
    else
        cout << "0.0000";
    return 0;
}