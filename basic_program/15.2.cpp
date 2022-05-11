#include <cstring>
#include <iostream>
#include <string>
using namespace std;
 
char a[105];
int i = 0;
int k = 99;
int aa = 1;
 
bool check(char c) {
    if (c >= 'a' && c <= 'z') return true;
    if (c >= 'A' && c <= 'Z') return true;
    if (c >= '0' && c <= '9') return true;
    return false;
}
 
char down(char c) {
    if (c >= 'A' && c <= 'Z') return c + 'a' - 'A';
    return c;
}
 
int main() {
    cin.getline(a, 105);
    int aa = 1;
    int i = 0;
    int k = strlen(a) - 1;
 
    while (i < k) {
        while (!check(a[i]) && i <= k) {
            i++;
        }
 
        while (!check(a[k]) && i <= k) {
            k--;
        }
        if (down(a[i]) != down(a[k]) && i < k) {
            aa = 0;
            break;
        }
        i++;
        k--;
    }
    cout << aa;
    return 0;
}