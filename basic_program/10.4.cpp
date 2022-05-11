#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#pragma pack(1)
struct info
{
    char name[8] = {0};
    char sex = {0};
    unsigned char age = {0};
    float weight = 0;
    float height = 0;
};
#pragma pack()
 
int main()
{
    info student[1040];
    int n;
    ifstream fin("input", ios::binary);
    fin.read((char *)(&n), sizeof(n));
 
    int numm = 0, numf = 0;
    float agem = 0, agef = 0, heightm = 0, heightf = 0;
    int a[3][10] = {0};
    char namem[10] = {0}, namef[10] = {0};
    float bmimax = 0, bmimin = 100;
    for (int i = 0; i < n; i++)
    {
        fin.read((char *)(&student[i]), sizeof(student[i]));
        if (student[i].sex == 'm')
        {
            numm++;
            agem += student[i].age;
            heightm += student[i].height;
            float bmi = student[i].weight / (student[i].height * student[i].height);
            if (bmi > bmimax)
                {
                    strcpy(namem, student[i].name);
                    bmimax =bmi;
                }
            if (bmi < 18.5)
                a[1][1]++;
            else if (bmi < 24)
                a[1][2]++;
            else if (bmi < 28)
                a[1][3]++;
            else
                a[1][4]++;
        }
 
        if (student[i].sex == 'f')
        {
            numf++;
            agef += student[i].age;
            heightf += student[i].height;
            float bmi = student[i].weight / (student[i].height * student[i].height);
            if (bmi < bmimin)
                {
                    strcpy(namef, student[i].name);
                    bmimin = bmi;
                }
            if (bmi < 18.5)
                a[2][1]++;
            else if (bmi < 24)
                a[2][2]++;
            else if (bmi < 28)
                a[2][3]++;
            else
                a[2][4]++;
        }
    }
    agem /= numm;
    heightm /= numm;
    agef /= numf;
    heightf /= numf;
    fin.close();
    ofstream fout("output.txt");
    fout << numm << ' ' << numf << endl;
    fout << fixed << setprecision(3) << agem << ' ' << agef << endl
        << heightm << ' ' << heightf << endl;
    for (int i = 1; i < 3; i++)
    {
        for (int j = 1; j < 5; j++)
            fout << a[i][j] << ' ';
        fout << endl;
    }
    fout << namem << endl << namef << endl;
    fout.close();
    return 0;
}