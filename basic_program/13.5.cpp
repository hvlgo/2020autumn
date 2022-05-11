#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
struct node
{
    string type;
    string num;
    int val;
    bool operator < (node r)
    {
        return val > r.val;
    }
};
 
vector<node> Data;
vector<node> Select;
vector<node> Rest;
 
int getint(string x)
{
    if (x[0] == 'A')    return 1;
    else if (x[0] == 'J')   return 11;
    else if (x[0] == 'Q')   return 12;
    else if (x[0] == 'K')   return 13;
    else if (x == "10") return 10;
    else return x[0] - '0';
}
 
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string op;
        cin >> op;
        if (op == "Append")
        {
            Data.emplace(Data.begin());
            cin >> Data.front().type >> Data.front().num;
            Data.front().val = getint(Data.front().num);
        }
        else if (op == "Extract")
        {
            Select.clear();
            Rest.clear();
            string type;
            cin >> type;
            for (auto it = Data.begin(); it < Data.end(); it++)
                if (it -> type == type)
                    Select.push_back(*it);
                else
                    Rest.push_back(*it);
            Data = Rest;
            sort(Select.begin(), Select.end());
            for (auto it = Select.begin(); it < Select.end(); it++)
                Data.push_back(*it);
        }
        else if (op == "Revert")
            reverse(Data.begin(), Data.end());
        else if (op == "Pop")
            if (!Data.empty())
                Data.pop_back();
    }
    if (Data.empty())
        cout << "null";
    else
        cout << Data.back().type << ' ' << Data.back().num << endl;
}