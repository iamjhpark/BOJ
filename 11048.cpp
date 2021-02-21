#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int answer = 0;

void BFS(vector<vector<int>> &maze, vector<vector<int>> count, int N, int M) {

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    count[0][0] += maze[0][0];

    while (!q.empty()) {
        pair<int, int> currentNode = q.front();
        q.pop();
        int currentX = currentNode.first;
        int currentY = currentNode.second;
        int numberOfCandies = count[currentX][currentY];
        if (currentX == N - 1 && currentY == M - 1 && numberOfCandies > answer) { answer = numberOfCandies; }
        vector<int> dx = { 1, 0 };
        vector<int> dy = { 0, 1 };
        for (int i = 0; i < 2; i++) {
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];
            if (nextX < N && nextY < M 
            && (
                count[nextX][nextY] < count[currentX][currentY] + maze[nextX][nextY]
                // TODO
                || count[nextX][nextY] + count[currentX][currentY] + maze[nextX][nextY] == 0
                )
                ) {
                q.push(make_pair(nextX, nextY));
                count[nextX][nextY] = count[currentX][currentY] + maze[nextX][nextY];
            }
        }
    }
}

int main(void) {

    int N; 
    int M; 
    cin >> N >> M;

    vector<vector<int>> maze;
    vector<vector<int>> count(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        vector<int> row;
        for (int j = 0; j < M; j++) {
            int el; 
            cin >> el;
            row.push_back(el);
        }
        maze.push_back(row);
    }

    BFS(maze, count, N, M);

    printf("%d", answer);

    return 0;
}