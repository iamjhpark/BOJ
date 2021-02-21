#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int answer = -1;

void BFS(vector<vector<char>> &map, vector<vector<bool>> &check, tuple<int, int, int> startPoint, queue<pair<int, int>> &fire, int w, int h) {

    queue<tuple<int, int, int>> q;
    q.push(startPoint);

    while (!q.empty()) {

        vector<int> dx = { -1, 1, 0, 0 };
        vector<int> dy = { 0, 0, -1, 1 };

        int fireSize = fire.size();
        for (int i = 0; i < fireSize; i++) {
            pair<int, int> current = fire.front();
            int currentX = current.first;
            int currentY = current.second;
            fire.pop();
            for (int j = 0; j < 4; j++) {
                int nextX = currentX + dx[j];
                int nextY = currentY + dy[j];
                if (nextX > -1 && nextX < h && nextY > -1 && nextY < w && map[nextX][nextY] == '.') {
                    map[nextX][nextY] = '*';
                    fire.push(make_pair(nextX, nextY));
                }
            }
        }

        int qSize = q.size();
        for (auto i = 0; i < qSize; i++) {
            tuple<int, int, int> current = q.front();
            int currentX = get<0>(current);
            int currentY = get<1>(current);
            int currentW = get<2>(current);
            q.pop();

            if (currentX == 0 || currentX == h - 1 || currentY == 0 || currentY == w - 1) {
                answer = currentW + 1;
                q = queue<tuple<int, int, int>>();
                break;
            }

            for (int j = 0; j < 4; j++) {
                int nextX = currentX + dx[j];
                int nextY = currentY + dy[j];
                if (nextX > -1 && nextX < h && nextY > -1 && nextY < w && check[nextX][nextY] && map[nextX][nextY] == '.') {
                    check[nextX][nextY] = false;
                    q.push(make_tuple(nextX, nextY, currentW + 1));
                }
            }
        }

    }
}

int main(void) {

    int c;
    scanf("%d", &c);

    while (c > 0) {
        
        int w;
        scanf("%d", &w);
        
        int h;
        scanf("%d", &h);

        vector<vector<bool>> check(h, vector<bool>(w, true));
        vector<vector<char>> map(h, vector<char>(w));
        tuple<int, int, int> startPoint;
        queue<pair<int, int>> fire;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char el;
                cin >> el;
                if (el == '@') { check[i][j] = false; startPoint = make_tuple(i, j, 0); }
                else if (el == '*') { fire.push(make_pair(i, j)); }
                map[i][j] = el;
            }
        }

        BFS(map, check, startPoint, fire, w, h);

        if (answer == -1) { printf("IMPOSSIBLE\n"); }
        else { printf("%d\n", answer); }
        answer = -1;

        c--;
    }

    return 0;

}