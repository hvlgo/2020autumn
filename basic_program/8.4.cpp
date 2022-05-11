#include <fstream>
using namespace std;
 
int main()
{
    int len1, len2;
    int a[10050] = {0}, b[10050] = {0};
    int c[20100] = {0};
    ifstream fin("input-1.txt");
    fin >> len1;
    for (int i = 0; i < len1; i++)
        fin >> a[i];
    fin.close();
    ifstream finn("input-2.txt");
    finn >> len2;
    for (int i = 0; i < len2; i++)
        finn >> b[i];
    finn.close();
    ofstream fout ("output.txt");
    fout << len1 + len2 << endl;
    int n = 0, m = 0, k = 0;
    while ((n < len1) && (m < len2))
    {
        if (a[n] <= b[m])
            c[k++] = a[n++];
        else
            c[k++] = b[m++];
    }
    while (n < len1)
        c[k++] = a[n++];
    while (m < len2)
        c[k++] = b[m++];
    for (int i = 0; i < k; i++)
        fout << c[i] << endl;
    fout.close();
    return 0;
}