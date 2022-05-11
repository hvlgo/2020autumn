#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
 
const int MAX_N = 1010;
 
struct Card {
    string hua;
    string num;
};
 
Card cards[MAX_N * 2];
int bottom = MAX_N;
int top = MAX_N;
 
int f(string num) {
    if (num == "A") return 1;
    if (num == "J") return 11;
    if (num == "Q") return 12;
    if (num == "K") return 13;
    if (num == "10")
        return 10;
    else
        return num[0] - '0';
}
 
bool cmp(Card a, Card b) { return f(a.num) < f(b.num); }
 
void append(string hua, string num) {
    --bottom;
    cards[bottom].hua = hua;
    cards[bottom].num = num;
}
 
void pop() { 
    if (top > bottom)
        --top;
}
 
void revert() {
    for (int i = 0; i < (top - bottom) / 2; ++i) {
        swap(cards[bottom + i], cards[top - 1 - i]);
    }
}
 
Card extract_cards[MAX_N];
Card rest_cards[MAX_N];
 
void extract(string hua) {
    int ext_cnt = 0;
    int rest_cnt = 0;
    for (int i = top - 1; i >= bottom; i--) {
        if (cards[i].hua == hua) {
            extract_cards[ext_cnt++] = cards[i];
        } else {
            rest_cards[rest_cnt++] = cards[i];
        }
    }
    sort(extract_cards, extract_cards + ext_cnt, cmp);
 
    bottom = top = MAX_N;
    for (int i = 0; i < ext_cnt; ++i) {
        append(extract_cards[i].hua, extract_cards[i].num);
    }
    for (int i = 0; i < rest_cnt; ++i) {
        append(rest_cards[i].hua, rest_cards[i].num);
    }
}
 
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string op;
        cin >> op;
        if (op == "Append") {
            string a, b;
            cin >> a >> b;
            append(a, b);
        } else if (op == "Extract") {
            string a;
            cin >> a;
            extract(a);
        } else if (op == "Revert") {
            revert();
        } else {
            pop();
        }
    }
    if (top == bottom)
        cout << "null";
    else
        cout << cards[top - 1].hua << " " << cards[top - 1].num;
    return 0;
}