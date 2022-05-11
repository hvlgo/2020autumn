#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;
 
struct Book {
    char type[10];
    char name[20];
    int expectation;
};
 
Book books[1005];
int book_num = 0;
 
void ENLIST() {
    book_num++;
    cin >> books[book_num].type 
        >> books[book_num].name 
        >> books[book_num].expectation;
}
 
void REMOVE(char *book_name) {
    int find = 1;
    while (strcmp(book_name, books[find].name) != 0 && find <= book_num) {
        find++;
    }
    if (find > book_num) return;
    for (int i = find; i <= book_num; ++i) {
        strcpy(books[i].type, books[i + 1].type);
        strcpy(books[i].name, books[i + 1].name);
        books[i].expectation = books[i + 1].expectation;
    }
    book_num--;
}
 
void REFINE() {
    char type[10];
    cin >> type;
 
    int maxexp = -1;
    char maxname[20];
 
    for (int i = 1; i <= book_num; ++i) {
        if (strcmp(type, books[i].type) != 0) continue;
        if (maxexp < books[i].expectation) {
            maxexp = books[i].expectation;
            strcpy(maxname, books[i].name);
        }
    }
 
    for (int i = 1; i <= book_num; ++i) {
        if (strcmp(type, books[i].type) == 0) {
            REMOVE(books[i].name);
            i--;
        }
    }
    if (maxexp == -1)
        return;
    books[book_num + 1].expectation = maxexp;
    strcpy(books[book_num + 1].type, type);
    strcpy(books[book_num + 1].name, maxname);
    book_num++;
}
 
void CLEANUP() {
    char type[10];
    cin >> type;
 
    for (int i = 1; i <= book_num; ++i) {
        if (type[0] == books[i].type[0]) {
            REMOVE(books[i].name);
            i--;
        }
    }
 
    for (int i = 1; i <= book_num; ++i) {
        for (int j = 1; j <= book_num - i; ++j) {
            if (books[j].expectation > books[j + 1].expectation) {
                int tmp = 0;
                tmp = books[j].expectation;
                books[j].expectation = books[j + 1].expectation;
                books[j + 1].expectation = tmp;
 
                char tmp1[10];
                strcpy(tmp1, books[j].type);
                strcpy(books[j].type, books[j + 1].type);
                strcpy(books[j + 1].type, tmp1);
 
                char tmp2[20];
                strcpy(tmp2, books[j].name);
                strcpy(books[j].name, books[j + 1].name);
                strcpy(books[j + 1].name, tmp2);
            }
        }
    }
}
 
void operate(char* operation) {
    if (operation[2] == 'L') { //enList
        ENLIST();
    } else if (operation[2] == 'M') { // reMove
        char book_name[10];
        cin >> book_name;
        REMOVE(book_name);
    } else if (operation[2] == 'F') { // reFine
        REFINE();
    } else if (operation[2] == 'E') { // clEanup
        CLEANUP();
    } else {
        // should never
        assert(0);
    }
}
 
int main() {
    int oper_num;
    cin >> oper_num;
    for (int i = 0; i < oper_num; ++i) {
        char oper[10];
        cin >> oper;
        operate(oper);
    }
 
    int print_booknum = min(3, book_num);
    if (print_booknum) {
        for (int i = 0; i < print_booknum; ++i) {
            cout << books[book_num - i].type << " "
                 << books[book_num - i].name << " "
                 << books[book_num - i].expectation << endl;
        }
    } else {
        cout << "NULL";
    }
    return 0;
}