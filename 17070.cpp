#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int answer = 0;

void BFS(vector<vector<int>> &map, int N) {
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 1, 0));
    while (!q.empty()) {
        tuple<int, int, int> current = q.front();
        q.pop();
        int currentX = get<0>(current);
        int currentY = get<1>(current);
        int direction = get<2>(current);

        if (currentX == N - 1 && currentY == N - 1) { answer++; continue; }

        if (direction == 0) {
            vector<int> dx = { 0, 1 };
            vector<int> dy = { 1, 1 };
            for (int i = 0; i < 2; i++) {
                int nextX = currentX + dx[i];
                int nextY = currentY + dy[i];
                if (nextX < N && nextY < N && map[nextX][nextY] != 1) {
                    if (dx[i] == 0 && dy[i] == 1) {
                        q.push(make_tuple(nextX, nextY, 0));
                    } else if (dx[i] == 1 && dy[i] == 1 && map[currentX][currentY + 1] != 1 && map[currentX + 1][currentY] != 1) {
                        q.push(make_tuple(nextX, nextY, 2));
                    }
                }
            }
        } else if (direction == 1) {
            vector<int> dx = { 1, 1 };
            vector<int> dy = { 0, 1 };
            for (int i = 0; i < 2; i++) {
                int nextX = currentX + dx[i];
                int nextY = currentY + dy[i];
                if (nextX < N && nextY < N && map[nextX][nextY] != 1) {
                    if (dx[i] == 1 && dy[i] == 0) {
                        q.push(make_tuple(nextX, nextY, 1));
                    } else if (dx[i] == 1 && dy[i] == 1 && map[currentX][currentY + 1] != 1 && map[currentX + 1][currentY] != 1) {
                        q.push(make_tuple(nextX, nextY, 2));
                    }
                }
            }
        } else if (direction == 2) {
            vector<int> dx = { 0, 1, 1 };
            vector<int> dy = { 1, 0, 1 };
            for (int i = 0; i < 3; i++) {
                int nextX = currentX + dx[i];
                int nextY = currentY + dy[i];
                if (nextX < N && nextY < N && map[nextX][nextY] != 1) {
                    if (dx[i] == 0 && dy[i] == 1) {
                        q.push(make_tuple(nextX, nextY, 0));
                    } else if (dx[i] == 1 && dy[i] == 0) {
                        q.push(make_tuple(nextX, nextY, 1));
                    } else if (dx[i] == 1 && dy[i] == 1 && map[currentX][currentY + 1] != 1 && map[currentX + 1][currentY] != 1) {
                        q.push(make_tuple(nextX, nextY, 2));
                    }
                }
            }
        }  
    }
}

int main(void) {

    int N;
    scanf("%d", &N);

    vector<vector<int>> map(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int el;
            scanf("%d", &el);
            map[i][j] = el;
        }
    }

    BFS(map, N);

    printf("%d\n", answer);

    return 0;
}