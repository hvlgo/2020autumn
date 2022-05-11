#include <fstream>
#include <iomanip>
using namespace std;
 
struct info
{
    char name[15] = {0};
    float Cvalue = 0.0;
    float Mvalue = 0.0;
    float Evalue = 0.0;
    float Pvalue = 0.0;
    float value = 0.0;
};
struct grade
{
    float maxValue = 0.0;
    float minValue = 1000.0;
    float average = 0.0;
};
int main()
{
    int n;
    info student[1050];
    ifstream fin ("input.txt");
    fin >> n;
    for (int i = 0; i < n; i++)
        {
            fin >> student[i].name >> student[i].Cvalue >> student[i].Mvalue >> student[i].Evalue >> student[i].Pvalue;
            student[i].value = student[i].Cvalue + student[i].Mvalue + student[i].Evalue + student[i].Pvalue;
        }
    fin.close();
    ofstream fout ("output.txt");
    grade subject[6];
    for (int i = 0; i < n; i++)
    {
        if (student[i].Cvalue > subject[0].maxValue)
            subject[0].maxValue = student[i].Cvalue;
        if (student[i].Cvalue <= subject[0].minValue)
            subject[0].minValue = student[i].Cvalue;
        subject[0].average += student[i].Cvalue;
 
        if (student[i].Mvalue > subject[1].maxValue)
            subject[1].maxValue = student[i].Mvalue;
        if (student[i].Mvalue <= subject[1].minValue)
            subject[1].minValue = student[i].Mvalue;
        subject[1].average += student[i].Mvalue;
 
        if (student[i].Evalue > subject[2].maxValue)
            subject[2].maxValue = student[i].Evalue;
        if (student[i].Evalue <= subject[2].minValue)
            subject[2].minValue = student[i].Evalue;
        subject[2].average += student[i].Evalue;
 
        if (student[i].Pvalue > subject[3].maxValue)
            subject[3].maxValue = student[i].Pvalue;
        if (student[i].Pvalue <= subject[3].minValue)
            subject[3].minValue = student[i].Pvalue;
        subject[3].average += student[i].Pvalue;
 
        if (student[i].value > subject[4].maxValue)
            subject[4].maxValue = student[i].value;
        if (student[i].value <= subject[4].minValue)
            subject[4].minValue = student[i].value;
        subject[4].average += student[i].value;
    }
    for (int i = 0; i < 5; i++)
        {
            subject[i].average /= n;
            fout << fixed << setprecision(3) << subject[i].maxValue << ' ' << subject[i].minValue << ' ' << subject[i].average << endl;
        }
    fout.close();
    return 0;
}