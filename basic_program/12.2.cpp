#include <iostream>
using namespace std;
 
int num;
int N;
int like[10][10] = {0};
int assigned[10] = {0};
 
void Try(int reader);
 
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> like[i][j];
    for (int i = 0; i < N; i++)
        assigned[i] = -1;
    Try(0);
    return 0;
}
 
void Try(int reader)
{
    if (reader == N)
    {
        for (int i = 0; i < N; i++)
            cout << assigned[i] + 1 << ' ';
        cout << endl;
        return;
    }
    for (int book = 0; book < N; book++)
    {
        if (like[reader][book] != 1 || assigned[book] != -1)
            continue;
        assigned[book] = reader;
        Try(reader + 1);
        assigned[book] = -1;
    }
}