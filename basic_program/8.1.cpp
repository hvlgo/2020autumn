#include <fstream>
#include <cstring>
using namespace std;
 
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    char a[1050] = {0};
    char b[1050] = {0};
    fin.getline(a, 1050);
    fin.getline(b, 1050);
    int lenA = strlen(a);
    int lenB = strlen(b);
    int pos = -1;
    for (int i = 0; i <= lenA - lenB; i++)
        for (int j = 0; j < lenB; j++)
        {
            if (a[i + j] != b[j])
                break;
            if (j == lenB - 1)
                {
                    pos = i;
                    fout << pos;
                    fout.close();
                    return 0;
                }
        }
    fout << pos;
    fout.close();
    return 0;
}