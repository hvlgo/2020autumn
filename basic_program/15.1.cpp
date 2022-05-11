#include <iostream>
using namespace std;
 
int x, y;
int n;
char a[25][25];
 
void show() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
 
void pw() {
    a[x - 1][y] = 'H';
    a[x--][y] = '_';
    show();
}
 
void ps() {
    a[x + 1][y] = 'H';
    a[x++][y] = '_';
    show();
}
 
void pa() {
    a[x][y - 1] = 'H';
    a[x][y--] = '_';
    show();
}
 
void pd() {
    a[x][y + 1] = 'H';
    a[x][y++] = '_';
    show();
}
 
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'H') {
                x = i;
                y = j;
            }
        }
    }
    string op;
    cin >> op;
    for (int m = 0; m < op.size(); m++) {
        if ((op[m] == 'w') && (x != 0)) {
            pw();
            }
        else if ((op[m] == 's') && (x != n - 1)) {
            ps();
        }
        else if ((op[m] == 'a') && (y != 0)) {
            pa();
        }
        else if ((op[m] == 'd') && (y != n - 1)) {
            pd();
        }
        else {
            show();
            continue;
        }
    }
    return 0;
}