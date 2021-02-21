#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int answer = 0;

void BFS(vector<vector<char>> &map, vector<vector<bool>> &check, vector<vector<bool>> &waterCheck,
pair<int, int> start, pair<int, int> end, queue<pair<int, int>> &waterExpansion, int R, int C) {

    queue<tuple<int, int, int>> q;
    int startX = start.first;
    int startY = start.second;
    q.push(make_tuple(startX, startY, 0));
    check[startX][startY] = false;

    while (!q.empty()) {

        vector<int> dx = { -1, 1, 0, 0 };
        vector<int> dy = { 0, 0, -1, 1 };

        int waterExpansionSize = waterExpansion.size();
        if (waterExpansionSize > 0) {
            for (int i = 0; i < waterExpansionSize; i++) {
                int waterX = waterExpansion.front().first;
                int waterY = waterExpansion.front().second;
                waterExpansion.pop();
                for (int j = 0; j < 4; j++) {
                    int nextWaterX = waterX + dx[j];
                    int nextWaterY = waterY + dy[j];
                    if (nextWaterX > -1 && nextWaterX < R && nextWaterY > -1 && nextWaterY < C
                    && map[nextWaterX][nextWaterY] != 'X' && map[nextWaterX][nextWaterY] != 'D'
                    && waterCheck[nextWaterX][nextWaterY]) {
                        waterCheck[nextWaterX][nextWaterY] = false;
                        waterExpansion.push(make_pair(nextWaterX, nextWaterY));
                    }
                }
            }
        }

        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            tuple<int, int, int> current = q.front();
            int x = get<0>(current);
            int y = get<1>(current);
            int count = get<2>(current);
            q.pop();
            
            if (x == end.first && y == end.second) { answer = count; break; }
            
            for (int j = 0; j < 4; j++) {
                int nextX = x + dx[j];
                int nextY = y + dy[j];
                if (nextX > -1 && nextX < R && nextY > -1 && nextY < C && check[nextX][nextY] && waterCheck[nextX][nextY]) {
                    check[nextX][nextY] = false;
                    q.push(make_tuple(nextX, nextY, count + 1));
                }
            }
        }
    }
}

int main(void) {

    int R;
    scanf("%d", &R);

    int C;
    scanf("%d", &C);

    pair<int, int> start;
    pair<int, int> end;
    pair<int, int> water;

    queue<pair<int, int>> waterExpansion;
    vector<vector<bool>> check(R, vector<bool>(C, true));
    vector<vector<bool>> waterCheck(R, vector<bool>(C, true));
    vector<vector<char>> map(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char el;
            scanf(" %1c", &el);
            if (el == '*') { waterCheck[i][j] = false; waterExpansion.push(make_pair(i, j)); }
            else if (el == 'S') { start = make_pair(i, j); }
            else if (el == 'D') { end = make_pair(i, j); }
            else if (el == 'X') { check[i][j] = false; }
            map[i][j] = el;   
        }
    }

    BFS(map, check, waterCheck, start, end, waterExpansion, R, C);

    if (answer == 0) { printf("KAKTUS\n"); }
    else { printf("%d\n", answer); }

    return 0;
}