#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>> &graph, vector<vector<bool>> &check, vector<vector<int>> &count, int N, int M, int H, int W, int sr, int sc, int fr, int fc) {
    queue<pair<int, int>> q;
    check[sr - 1][sc - 1] = false;
    q.push(make_pair(sr - 1, sc - 1));
    while (!q.empty()) {
        int currentR = q.front().first;
        int currentC = q.front().second;
        q.pop();
        if (currentR == fr - 1 && currentC == fc - 1) { break; }
        vector<int> dx = { -1, 1, 0 ,0};
        vector<int> dy = { 0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int nextR = currentR + dx[i];
            int nextC = currentC + dy[i];
            if (nextR >= 0 && nextR < N - H + 1 && nextC >= 0 && nextC < M - W + 1 && check[nextR][nextC]) {
                check[nextR][nextC] = false;
                count[nextR][nextC] = count[currentR][currentC] + 1;
                q.push(make_pair(nextR, nextC));
            }
        }
    }
    if (count[fr - 1][fc - 1] == 0) { printf("%d", -1); } 
    else { printf("%d", count[fr - 1][fc - 1]); }
}

int main(void) {

    int N;
    scanf("%d", &N);
    int M;
    scanf("%d", &M);

    vector<vector<int>> graph(N);
    vector<vector<bool>> check(N, vector<bool>(M, true));
    vector<vector<int>> count(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int el;
            scanf("%d", &el);
            graph[i].push_back(el);
        }
    }

    int H;
    scanf("%d", &H);
    int W;
    scanf("%d", &W);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 1) {
                for (int k = j - W + 1; k <= j; k++) {
                    for (int l = i - H + 1; l <= i; l++) {
                        if (l >= 0 && l < N - H + 1 && k >= 0 && k < M - W + 1) {
                            check[l][k] = false;
                        }
                    }
                }
            }
        }
    }

    int sr;
    scanf("%d", &sr);
    int sc;
    scanf("%d", &sc);

    int fr;
    scanf("%d", &fr);
    int fc;
    scanf("%d", &fc);

    BFS(graph, check, count, N, M, H, W, sr, sc, fr, fc);

    return 0;
}