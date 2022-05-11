#include <iostream>
using namespace std;
 
struct position
{
    int x;
    int y;
    int z;
    int k;
};
position d[] = {{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 0, 0}, {1, 0, 1, 0}, {1, 0, 0, 1}};
int transfer(position s[], int choice[])
{
    int step = 1;
    s[1].x = 1;
    s[1].y = 1;
    s[1].z = 1;
    s[1].k = 1;
 
    do
    {
        int fx = 1;
        if (step % 2 == 1)
            fx = -1;
 
        int i;
 
        for (i = choice[step] + 1; i <= 4; i++)
        {
            position next_st = {s[step].x + fx * d[i].x, s[step].y + fx * d[i].y, s[step].z + fx * d[i].z, s[step].k + fx * d[i].k};
            if (next_st.x < 0 || next_st.x > 1 || next_st.y < 0 || next_st.y > 1 || next_st.z < 0 || next_st.z > 1 || next_st.k < 0 || next_st.k > 1)
                continue;
            if ((next_st.y == next_st.z && next_st.z != next_st.x) || (next_st.z == next_st.k && next_st.k != next_st.x))
                continue;
            bool CHF = false;
            for (int j = step - 1; j >= 1; j++)
            {
                if (next_st.x == s[j].x && next_st.y == s[j].y && next_st.z == s[j].z && next_st.k == s[j].k)
                    CHF = true;
                break;
            }
            if (CHF)
                continue;
 
            choice[step] = i;
 
            step++;
            s[step].x = next_st.x;
            s[step].y = next_st.y;
            s[step].z = next_st.z;
            s[step].k = next_st.k;
            break;
        }
        if (i > 4)
        {
            choice[step] = 0;
            step--;
        }
    } while (!(s[step].x == 0 && s[step].y == 0 && s[step].z == 0 && s[step].k == 0));
    return step;
}
 
int main()
{
    position s[20] = {0};
    int choice[20] = {0};
    int step = transfer(s, choice);
    for (int i = 1; i < step; i++)
    {
        if (choice[i] == 1)
            cout << 'H';
        if (choice[i] == 2)
            cout << "HW";
        if (choice[i] == 3)
            cout << "HS";
        if (choice[i] == 4)
            cout << "HV";
        cout << ' ';
    }
    return 0;
}