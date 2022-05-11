#include <iostream>
using namespace std;
 
struct position
{
    int x;
    int y;
    int z;
    int k;
    int p;
};
position d[] = {{0, 0, 0, 0,0}, {1, 0, 0, 0,0}, {0, 1, 0, 0,0}, {0, 0, 1, 0,0}, {0, 0, 0, 1,0},{0,0,0,0,1},
                {1,1,0,0,0},{1,0,1,0,0},{1,0,0,1,0},{1,0,0,0,1},
                {0,1,1,0,0},{0,1,0,1,0},{0,1,0,0,1},{0,0,1,1,0},
                {0,0,1,0,1},{0,0,0,1,1}};
int transfer(position s[], int choice[])
{
    int step = 1;
    s[1].x = 1;
    s[1].y = 1;
    s[1].z = 1;
    s[1].k = 1;
    s[1].p = 1;
    int num = 0;
    int n[20000];
    do
    {
        int fx = 1;
        if (step % 2 == 1)
            fx = -1;
 
        int i;
        
        for (i = choice[step] + 1; i <= 15; i++)
        {
            position next_st = {s[step].x + fx * d[i].x, s[step].y + fx * d[i].y, s[step].z + fx * d[i].z, s[step].k + fx * d[i].k,s[step].p + fx * d[i].p};
            if (next_st.x < 0 || next_st.x > 1 || next_st.y < 0 || next_st.y > 1 || next_st.z < 0 || next_st.z > 1 || next_st.k < 0 || next_st.k > 1|| next_st.p < 0 || next_st.p > 1)
                continue;
            
            if(d[i].p == 1) n[step] = 12;
            else if(d[i].k == 1)    n[step]=8;
            else if(d[i].z == 1)    n[step]=6;
            else if(d[i].y == 1)    n[step]=3;
            else if(d[i].x == 1)    n[step]=1; 
            num += n[step];
            if (num > 30)
            {
                num -= n[step];
                continue;
            }
            bool CHF = false;
            for (int j = step - 1; j >= 1; j-=2)
            {
                if (next_st.x == s[j].x && next_st.y == s[j].y && next_st.z == s[j].z && next_st.k == s[j].k && next_st.p == s[j].p)
                    CHF = true;
                break;
            }
            if (CHF)
            {
                num -= n[step];
                continue;
            }
            choice[step] = i;
 
            step++;
            s[step].x = next_st.x;
            s[step].y = next_st.y;
            s[step].z = next_st.z;
            s[step].k = next_st.k;
            s[step].p = next_st.p;
            break;
        }
        if (i > 15)
        {
            choice[step] = 0;
            step--;
            num -= n[step];
        }
    } while (!(s[step].x == 0 && s[step].y == 0 && s[step].z == 0 && s[step].k == 0 && s[step].p == 0));
    return step;
}
 
int main()
{
    position s[20000] = {0};
    int choice[20000] = {0};
    int step = transfer(s, choice);
    for (int i = 1; i < step; i++)
    {
        if (choice[i] == 1)
            cout << 'A';
        if (choice[i] == 2)
            cout << 'B';
        if (choice[i] == 3)
            cout << 'C';
        if (choice[i] == 4)
            cout << 'D';
        if (choice[i] == 5)
            cout << 'E';
        if (choice[i] == 6)
            cout << "AB";
            if (choice[i] == 7)
            cout << "AC";
            if (choice[i] == 8)
            cout << "AD";
            if (choice[i] == 9)
            cout << "AE";
            if (choice[i] == 10)
            cout << "BC";
            if (choice[i] == 11)
            cout << "BD";
            if (choice[i] == 12)
            cout << "BE";
            if (choice[i] == 13)
            cout << "CD";
            if (choice[i] == 14)
            cout << "CE";
            if (choice[i] == 15)
            cout << "DE";
        cout << ' ';
    }
    return 0;
}