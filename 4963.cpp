#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int answer = 0;

void BFS(vector<vector<int>> &map, vector<vector<bool>> &check, int w, int h) {

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (check[i][j]) {
                check[i][j] = false;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                while (!q.empty()) {
                    pair<int, int> current = q.front();
                    q.pop();
                    int currentX = current.first;
                    int currentY = current.second;
                    vector<int> dx = { 0, 0, -1, 1, 1, 1, -1, -1 };
                    vector<int> dy = { -1, 1, 0, 0, 1, -1, -1, 1 };
                    for (int k = 0; k < 8; k++) {
                        int nextX = currentX + dx[k];
                        int nextY = currentY + dy[k];
                        if (nextX > -1 && nextX < h && nextY > -1 && nextY < w && check[nextX][nextY]) {
                            check[nextX][nextY] = false;
                            q.push(make_pair(nextX, nextY));
                        }
                    }
                }
                answer++;
            }
        }
    }

}

int main(void) {

    while(true) {

        int w;
        scanf("%d", &w);

        int h;
        scanf("%d", &h);

        if (w == 0 && h == 0) { break; }

        vector<vector<bool>> check(h, vector<bool>(w, true));
        vector<vector<int>> map(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int el;
                scanf("%d", &el);
                map[i][j] = el;
                if (el == 0) { check[i][j] = false; }
            }
        }

        BFS(map, check, w, h);
        printf("%d\n", answer);
        answer = 0;

    }

    return 0;
}