#include <fstream>
using namespace std;
 
char a[9][5][5] = {0};
void R();
 
int main()
{
    ifstream fin ("input.txt");
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 3; j++)
            for (int k = 1; k <= 3; k++)
                fin >> a[i][j][k];
    char op;
    while (fin >> op)
        R();
    fin.close();
    ofstream fout ("output.txt");
    for (int i = 1; i <= 6; i++)
        {
            for (int j = 1; j <= 3; j++)
                for (int k = 1; k <= 3; k++)
                    fout << a[i][j][k];
            fout << endl;
        }
    fout.close();
    return 0;
}
 
void R()
{
    int tmp[5] = {0};
    for (int i = 1; i <= 3; i++)
        tmp[i] = a[1][i][3];
    for (int i = 1; i <= 3; i++)
    {
        a[1][i][3] = a[6][i][3];
        a[6][i][3] = a[2][4 - i][1];
        a[2][4 - i][1] = a[5][i][3];
        a[5][i][3] = tmp[i];
    }
    char b[5][5] = {0};
        for (int j = 1; j <= 3; j++)
            for (int k = 1; k <= 3; k++)
                b[j][k] = a[4][j][k];
        for (int j = 1; j <= 3; j++)
            for (int k = 1; k <= 3; k++)
                a[4][k][4 - j] = b[j][k];
}