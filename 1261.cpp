#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int BFS(vector<vector<int>> &map, vector<vector<bool>> &check, int N, int M) {

    int answer = -1;

    deque<tuple<int, int, int>> dq;
    dq.push_front(make_tuple(0, 0, 0));

    while (!dq.empty()) {

        tuple<int, int, int> current = dq.front();
        int currentX = get<0>(current);
        int currentY = get<1>(current);
        int currentW = get<2>(current);
        dq.pop_front();

        if (currentX == N - 1 && currentY == M - 1) { answer = currentW; break; }

        vector<int> dx = { -1, 1, 0, 0 };
        vector<int> dy = { 0, 0, -1, 1 };

        for (int i = 0; i < 4; i++) {
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];
            if (nextX > -1 && nextX < N && nextY > -1 && nextY < M && check[nextX][nextY]) {
                check[nextX][nextY] = false;
                if (map[nextX][nextY] == 1) {
                    dq.push_back(make_tuple(nextX, nextY, currentW + 1));
                } else {
                    dq.push_front(make_tuple(nextX, nextY, currentW));
                }
            }
        }

    }

    return answer;

}

int main(void) {

    int M;
    scanf("%d", &M);

    int N;
    scanf("%d", &N);

    vector<vector<int>> map(N, vector<int>(M, 0));
    vector<vector<bool>> check(N, vector<bool>(M, true));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int el;
            scanf("%1d", &el);
            map[i][j] = el;
        }
    }

    int answer = BFS(map, check, N, M);

    printf("%d\n", answer);

    return 0;
}