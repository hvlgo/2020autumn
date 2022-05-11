#include <iostream>
using namespace std;
 
struct position
{
    int wolf;
    int sheep;
};
 
struct state
{
    int dir;
    position pos;
};
state start, goal;
 
int n, m;
int num = 0;
position tran[120];
state path[1000] = {0};
int minx = 10000000;
 
bool isEq(state st1, state st2);
bool isValid(state st,int step);
state getnewstate(state st, int k, int step);
bool isDone(state st);
void logStep(state st, int step);
void jump(state st, int step);
 
int main()
{
    cin >> n >> m; 
    start.dir = -1, start.pos.sheep = n, start.pos.wolf = n;
    goal.dir = 1, goal.pos.sheep = 0, goal.pos.wolf = 0;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++)
            if (((i <= j) || (j == 0)) && (i + j <= m))
                tran[num].sheep = j, tran[num++].wolf = i;
    logStep(start, 0);
    jump(start, 0);
    if (minx == 10000000)
    {
        cout << -1;
        return 0;
    }
    cout << minx;
    return 0;
}
 
bool isEq(state st1, state st2)
{
    return (st1.dir == st2.dir) && (st1.pos.wolf == st2.pos.wolf) && (st1.pos.sheep == st2.pos.sheep);
}
 
bool isVaild(state st, int step)
{
    if (st.pos.sheep < 0 || st.pos.sheep > n || st.pos.wolf < 0 || st.pos.wolf > n)
        return 0;
    if (st.pos.sheep != 0 && st.pos.sheep != n && st.pos.sheep != st.pos.wolf)
        return 0;
    for (int i = step-2; i >= 0; i -= 2)
        if (isEq(st, path[i]))
            return 0;
    return 1;
}
 
state getnewstate(state st, int k, int step)
{
    state newstate;
    newstate.dir = -st.dir;
    newstate.pos.wolf = st.pos.wolf + st.dir * tran[k].wolf;
    newstate.pos.sheep = st.pos.sheep + st.dir * tran[k].sheep;
    return newstate;
}
 
bool isDone(state st)
{
    return (isEq(st, goal));
}
 
void logStep(state st, int step)
{
    path[step] = st;
}
 
void jump(state st, int step)
{
    if (isDone(st))
        if (step < minx)
            minx = step;
    for (int k = 1; k < num; k++)
    {
        state next = getnewstate(st, k, step);
        if (!isVaild(next, step+1))
            continue;
        logStep(next, step + 1);
        jump(next, step + 1);
    }
}