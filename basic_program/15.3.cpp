#include <iostream>
using namespace std;
 
struct Position {
    int x, y;
};
 
Position dxy[4] = {{1, 2}, {1, -2}, {2, 1}, {2, -1}};
 
int total = 0, N, M, K;
bool is_not_vacant[20][20] = {0};
 
void jump(Position now_pos) {  //前面都跳好了，从now_pos开始跳下一步
    if ((now_pos.x == N) && (now_pos.y == M)) {  //现在的位置就是终点
        total++;
        return;
    }
 
    for (int j = 0; j < 4; j++) {
        Position next_pos = {now_pos.x + dxy[j].x, now_pos.y + dxy[j].y};
        if ((next_pos.x > N) || (next_pos.x < 0) || (next_pos.y < 0) ||
            (next_pos.y > M) || is_not_vacant[next_pos.x][next_pos.y])
            continue;
 
        jump(next_pos);
    }
}
 
int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        int x1, y1;
        cin >> x1 >> y1;
        is_not_vacant[x1][y1] = true;
    }
     
    jump({0, 0});
 
    cout << total << endl;
    return 0;
}