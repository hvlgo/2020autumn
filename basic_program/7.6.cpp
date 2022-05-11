#include <iostream>
using namespace std;
const int M = 5000000;
 
int* prepare() {
    // 请定义一个数组b，根据代码推理所需要包含的元素个数。
int *b = new int[15];
    b[9] = 9;
    return b;
}
bool test() {
    // 请定义一个数组a，根据代码推理所需要包含的元素个数。
int *a = new int[M + 50];
    for (int i = 0; i < M; ++ i)
        a[i] = i;
    int c = 10;
    
    bool flag = true;
    for (int i = 0; i < M; ++ i)
        if (a[i]!=i)
            flag = false;
 
    return flag;
}
 
int main() {  
    if (!test())
        cout << "Wrong Answer" <<endl;
 
    int *b = prepare();
    int c[10] = {0};
    if (b[9]!=9) 
        cout << "Wrong Answer" <<endl;
 
    return 0;
}