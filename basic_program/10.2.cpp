#include <fstream>
#include <iomanip>
using namespace std;
 
int main()
{
    int m;
    ifstream fin("input", ios::binary);
    fin.read((char *)(&m), sizeof(m));
    double **a = new double *[m];
    double b[1050] = {0.0};
    double maxval = 0.0, minval = 10000.0, val = 0.0;
    for (int i = 0; i < m; i++)
    {
        int n;
        fin.read((char *)(&n), sizeof(n));
        a[i] = new double[n];
        for (int j = 0; j < n; j++)
            {
                fin.read((char *)(&a[i][j]), sizeof(a[i][j]));
                b[i] += a[i][j];
            }
        b[i] /= n;
        if (b[i] > maxval)
            maxval = b[i];
        if (b[i] <= minval)
            minval = b[i];
        val += b[i];
    }
    fin.close();
    val /= m;
    ofstream fout("output.txt");
    fout << fixed << setprecision(3) << minval << endl << maxval << endl << val << endl;
    fout.close();
    for (int i = 0; i < m; i++)
        delete[] a[i];
    delete a;
    return 0;
}