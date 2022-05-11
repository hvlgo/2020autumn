#include <bits/stdc++.h>
using namespace std;
 
struct node
{
    string name;
    string type;
    int val;
    bool operator < (node r)
    {
        return val < r.val;
    }
};
 
vector<node> Data;
vector<node> tmp;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string op;
        cin >> op;
        if (op == "ENLIST")
        {
            Data.emplace_back();
            cin >> Data.back().type >> Data.back().name >> Data.back().val;
        }
        else if (op == "REMOVE")
        {
            string name;
            cin >> name;
            for (auto it = Data.begin(); it < Data.end(); it++)
            {
                if (it-> name == name)
                {
                    Data.erase(it);
                    break;
                }
            }
        }
        else if (op == "REFINE")
        {
            string type;
            cin >> type;
            tmp.clear();
            node x;
            x.val = -1;
            for (auto it = Data.begin(); it < Data.end(); it++)
            {
                if (it -> type == type)
                {
                    if (it -> val > x.val)
                        x = *it;
                }
                else
                    tmp.push_back(*it);
            }
            if (x.val != -1)
                tmp.push_back(x);
            Data = tmp;
        }
        else if (op == "CLEANUP")
        {
            tmp.clear();
            string type;
            cin >> type;
            for (auto it = Data.begin(); it < Data.end(); it++)
                if (it -> type != type)
                    tmp.push_back(*it);
            sort(tmp.begin(), tmp.end());
            Data = tmp;
        }
    }
 
    if (Data.empty())
        cout << "NULL";
    else
    {
        for (auto it = Data.rbegin(); it <= Data.rbegin() + min(3, (int)Data.size()) - 1; it++)
            printf("%s %s %d \n", it -> type.c_str(), it -> name.c_str(), it -> val);
    }
    return 0;
}