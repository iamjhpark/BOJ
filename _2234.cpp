#include <iostream>
#include <bitset>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> answer;
bool check[50][50];

void BFS(vector<vector<int>> &map, int n, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (check[i][j]) {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                check[i][j] = false;
                int count = 1;
                while (!q.empty()) {
                    pair<int, int> current = q.front();
                    int currentX = current.first;
                    int currentY = current.second;
                    q.pop();
                    int direction = map[currentX][currentY];
                    bitset<4> bs = bitset<4>(direction);
                    for (int k = 0; k < 4; k++) {
                        if (bs[k] == 0) {
                            int nextX = currentX;
                            int nextY = currentY;
                            if (k == 0) {
                                nextY -= 1;
                            } else if (k == 1) {
                                nextX -= 1;
                            } else if (k == 2) {
                                nextY += 1;
                            } else if (k == 3) {
                                nextX += 1;
                            }
                            
                            if (nextX > -1 && nextX < m && nextY > -1 && nextY < n && check[nextX][nextY]) {
                                count++;
                                check[nextX][nextY] = false;
                                q.push(make_pair(nextX, nextY));
                            }
                        }
                    }
                }
                answer.push_back(count);
            }
        }
    }
}

int main(void) {

    int n;
    scanf("%d", &n);

    int m;
    scanf("%d", &m);

    memset(check, true, sizeof(check));
    vector<vector<int>> map(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int el;
            scanf("%d", &el);
            map[i][j] = el;
        }
    }

    BFS(map, n, m);

    long long count = answer.size();
    printf("%lld\n", count);

    int max = *max_element(answer.begin(), answer.end());
    printf("%d\n", max);

    answer = vector<int>();
    vector<int> walls = { 1, 2, 4, 8 };
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                if ((map[i][j] & walls[k]) == walls[k]) {
                    map[i][j] = map[i][j] & (15 - walls[k]);
                    memset(check, true, sizeof(check));
                    BFS(map, n, m);
                    map[i][j] = map[i][j] | walls[k];
                }
            }
        }
    }

    int anotherMax = *max_element(answer.begin(), answer.end());
    printf("%d\n", anotherMax);

    return 0;

}
