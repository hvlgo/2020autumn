#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
 
int n, m;
struct Status {
    int wolf, sheep;
};
 
Status LR[2];
int minStep = 0;
 
int choice[2][10000];
bool isVisiting[11][11][2] = {{{0}}};
 
bool isFinalStatus() { return (LR[1].wolf == n && LR[1].sheep == n); }
 
void guoHe(int step, bool pos) {
    if (LR[0].sheep && LR[0].wolf > LR[0].sheep) return;
    if (LR[1].sheep && LR[1].wolf > LR[1].sheep) return;
    if (isVisiting[LR[0].wolf][LR[0].sheep][pos]) return;
    if (minStep && step > minStep) return;
 
    if (isFinalStatus()) {
        if (minStep == 0 || step <= minStep) {
            minStep = step - 1;
        }
        return;
    }
 
    int max_wolf_on_boat = min(m, LR[pos].wolf);
    for (int n_wolf = 0; n_wolf <= max_wolf_on_boat; n_wolf++) {
 
        int max_sheep_on_boat = min(m - n_wolf, LR[pos].sheep);
        for (int n_sheep = 0; n_sheep <= max_sheep_on_boat; n_sheep++) {
 
            if (n_wolf == 0 && n_sheep == 0) continue;
            if (n_sheep != 0 && n_sheep < n_wolf) continue;
 
 
            isVisiting[LR[0].wolf][LR[0].sheep][pos] = true;
            LR[pos].wolf -= n_wolf;
            LR[pos].sheep -= n_sheep;
            LR[!pos].wolf += n_wolf;
            LR[!pos].sheep += n_sheep;
 
            guoHe(step + 1, !pos);
 
            LR[pos].wolf += n_wolf;
            LR[pos].sheep += n_sheep;
            LR[!pos].wolf -= n_wolf;
            LR[!pos].sheep -= n_sheep;
            isVisiting[LR[0].wolf][LR[0].sheep][pos] = false;
        }
    }
}
 
int main() {
    cin >> n >> m;
    LR[0].sheep = LR[0].wolf = n;
    LR[1].sheep = LR[1].wolf = 0;
 
    minStep = 0;
    guoHe(1, 0);
    if (minStep == 0) {
        cout << -1 << endl;
        return 0;
    }
 
    cout << minStep << endl;
    return 0;
}