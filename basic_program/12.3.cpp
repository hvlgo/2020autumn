#include <iostream>
using namespace std;
 
int N;
int num = 0;
int Q[11] = {0};
bool S[11] = {0};
bool L[21] = {0};
bool R[21] = {0};
int offset;
 
void Try(int col);
 
int main()
{
    cin >> N;
    offset = N - 1;
    for (int i = 0; i < N; i++)
        S[i] = true;
    for (int i = 0; i < 2 * N + 1; i++)
        L[i] = R[i] = true;
    Try(1);
    cout << num;
    return 0;
}
 
void Try(int col)
{
    if (col == N + 1)
    {
        num++;
        return;
    }
    for (int row = 0; row < N; row++)
    {
        if (!S[row] || !R[row + col] || !L[col - row + offset])
            continue;
        Q[col] = row;
 
        S[row] = false;
        R[col + row] = false;
        L[col - row + offset] = false;
        
        Try(col + 1);
        S[row] = true;
        R[col + row] = true;
        L[col - row + offset] = true;
    }
}