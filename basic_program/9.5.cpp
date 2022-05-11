#include <fstream>
using namespace std;
 
struct info
{
    char name[1050] = {0};
    int score = 0;
};
int main()
{
    info student[205];
    int a[15] = {0};
    ifstream fin ("input.txt");
    int i = 0;
    while (fin >> student[i].name)
    {
        fin >> student[i].score;
        int k = student[i].score / 10;
        if (k == 10)
            k = 9;
        a[k]++;
    }
    fin.close();
    for (int i = 0; i < 10; i++)
        if (a[i] > 10)
            a[i] = 10;
    ofstream fout ("output.txt");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < a[i]; j++)
            fout << '@';
        for (int j = a[i]; j < 10; j++)
            fout << '.';
        fout << endl;
    }
    fout.close();
    return 0;
}