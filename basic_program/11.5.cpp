#include <bits/stdc++.h>
using namespace std;
 
struct node
{
    int flag;
    int val;
    string name;
    bool operator < (node r)
    {
        if (val != r.val)
            return val < r.val;
        else
            return name < r.name;
    }
};
vector<node> Data;
vector<node> tmp;
 
int findflag()
{
    for (int i = 0; i < Data.size(); i++)
        if (Data[i].flag == 1)
            return i;
}
 
int succ_k(int x, int k)
{
    return (x + k) % Data.size();
}
 
int prev_k(int x, int k)
{
    int tmp = Data.size();
    return ((x - k) % tmp + tmp) % tmp; 
}
 
void print()
{
    for (auto it = Data.begin(); it < Data.end(); it++)
        printf("(%d,%s,%d)", it -> val, it -> name.c_str(), it -> flag);
    printf("\n");
}
 
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string op;
        cin >> op;
        if (op == "Append")
        {
            node x;
            cin >> x.val >> x.name;
            x.flag = 0;
            if (!Data.empty())
                Data.insert(Data.begin() + findflag(), x);
            else
            {
                x.flag = 1;
                Data.push_back(x);
            }
        }
        else if (op == "Eliminate")
        {
            int pos = findflag();
            int m, n;
            cin >> m >> n;
            for (int i = 1; i <= n; i++)
            {
                pos = succ_k(pos, m - 1);
                if (Data[pos].flag == 1)
                    Data[succ_k(pos, 1)].flag = 1;
                Data.erase(Data.begin() + pos);
            }
        }
        else if (op == "Move")
        {
            int p, r;
            cin >> p >> r;
            int pos = findflag();
            Data[pos].flag = 0;
            if (p == 0)
                Data[succ_k(pos, r)].flag = 1;
            else
                Data[prev_k(pos, r)].flag = 1;
        }
        else if (op == "Sort")
        {
            sort(Data.begin(), Data.end());
        }
        else if (op == "Delete")
        {
            string name;
            cin >> name;
            for (auto it = Data.begin(); it < Data.end(); it++)
            {
                if (it -> name == name)
                {
                    if (Data.size() == 1)
                    {
                        Data.clear();
                        break;
                    }
                    if (it -> flag == 1)
                        Data[succ_k(distance(Data.begin(), it), 1)].flag = 1;
                    Data.erase(it);
                    break;
                }
            }
        }
        //print();
    }
 
    string name;
    cin >> name;
    if (Data.empty())
    {
        cout << -1;
        return 0;
    }
    int pos = findflag();
    int flag = 0, ans = 0;
    for (auto it = Data.begin(); it < Data.end(); it++)
        if (it -> name == name)
        {
            flag = 1;
            break;
        }
    if (!flag)
        cout << -1;
    else if (Data[pos].name == name)
        cout << 0;
    else
    {
        while (Data[pos].name != name)
        {
            cout << Data[pos].name << endl;
            ans += Data[pos].val;
            pos = succ_k(pos, 1);
        }
        cout << ans << endl;
    }
}