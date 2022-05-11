#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> a;
int main()
{
    for (int i = 1; i <= 4; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for (auto i : a)
        cout << i << " ";
    return 0;
}