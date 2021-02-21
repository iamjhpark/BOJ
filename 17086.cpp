#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> safetyDistance;
vector<int> dx = { 0, 0, -1, 1, -1, -1, 1, 1 };
vector<int> dy = { -1, 1, 0, 0, -1, 1, -1, 1  };

void BFS(vector<vector<int>> &map, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            vector<vector<int>> check(N, vector<int>(M, true));
            queue<tuple<int, int, int>> q;
            if (map[i][j] == 1) { continue; }
            q.push(make_tuple(i, j, 0));
            check[i][j] = false;
            while (!q.empty()) {
                tuple<int, int, int> current = q.front();
                q.pop();
                int currentX = get<0>(current);
                int currentY = get<1>(current);
                int distance = get<2>(current);
                if (map[currentX][currentY] == 1) { safetyDistance.push_back(distance); break; }
                for (int k = 0; k < 8; k++) {
                    int nextX = currentX + dx[k];
                    int nextY = currentY + dy[k];
                    if (nextX > -1 && nextX < N && nextY > -1 && nextY < M && check[nextX][nextY]) {
                        check[nextX][nextY] = false;
                        q.push(make_tuple(nextX, nextY, distance + 1));
                    }
                }
            }
        }
    }
}

int main(void) {

    int N;
    scanf("%d\n", &N);

    int M;
    scanf("%d\n", &M);

    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int el;
            scanf("%d", &el);
            map[i][j] = el;
        }
    }

    BFS(map, N, M);
    
    int answer = * max_element(safetyDistance.begin(), safetyDistance.end());

    printf("%d\n", answer);

}