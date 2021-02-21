#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int answer = 0;

int BFS(vector<vector<int>> v, vector<vector<bool>> &check, int x, int y, int N, int M) {
    queue<tuple<int, int, int>> q;
    check[x][y] = false;
    q.push(make_tuple(x, y, 1));
    vector<int> dx = { -1, 1, 0, 0 };
    vector<int> dy = { 0, 0, -1, 1 };
    tuple<int, int, int> currentLoc;
    while (!q.empty()) {
        currentLoc = q.front();
        q.pop();
        int currentX = get<0>(currentLoc);
        int currentY = get<1>(currentLoc);
        int count = get<2>(currentLoc);
        if (currentX == N - 1 && currentY == M - 1) { break; }
        for (int i = 0; i < 4; i++) {
            tuple<int, int, int> nextLoc = make_tuple(currentX + dx[i], currentY + dy[i], count + 1);
            int nextX = get<0>(nextLoc);
            int nextY = get<1>(nextLoc);
            if (nextX > -1 && nextX < N && nextY > -1 && nextY < M && check[nextX][nextY] && v[nextX][nextY] == 1) {
                check[nextX][nextY] = false;
                q.push(nextLoc);
            }
        }
    }
    return get<2>(currentLoc);
}

int main(void) {

    int N;
    cin >> N;

    int M;
    cin >> M;

    vector<vector<int>> v;
    for (int i = 0; i < N; i++) {
        vector<int> temp;
        for (int j = 0; j < M; j++) {
            int el;
            scanf("%1d", &el);
            temp.push_back(el);
        }
        v.push_back(temp);
    }
    
    vector<vector<bool>> check(N, vector<bool>(M, true));
    int answer = BFS(v, check, 0, 0, N, M);
    printf("%d", answer);

    return 0;
}