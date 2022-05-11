#include <iostream>
using namespace std;
 
struct position
{
    int x;
    int y;
};
position dxy[4] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}};
position start = {0, 0};
position goal;
int n, m;
int num;
int K;
position ban[225] = {0};
 
void jump(position pos);
bool unsafe(position p);
 
int main()
{
    num = 0;
    cin >> n >> m >> K;
    goal.x = n;
    goal.y = m;
    for (int i = 0; i < K; i++)
        cin >> ban[i].x >> ban[i].y;
    jump(start);
    cout << num;
    return 0;
}
 
void jump(position pos)
{
    if (pos.x == n && pos.y == m)
    {
        num++;
        return;
    }
 
    for (int k = 0; k < 4; k++)
    {
        position next = {pos.x + dxy[k].x, pos.y + dxy[k].y};
        if (unsafe(next))
            continue;
        jump(next);
    }
}
 
bool unsafe(position p)
{
    if (p.x < 0 || p.y < 0 || p.x > n || p.y > m)
        return true;
    for (int i = 0; i < K; i++)
    {
        if (p.x == ban[i].x && p.y == ban[i].y)
            return true;
    }
    return false;
}