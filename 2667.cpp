#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> answer;

void go(int N, vector<vector<int>> v, vector<vector<bool>> &check) {
    vector<int> dx = { -1, 1, 0, 0 };
    vector<int> dy = { 0, 0, -1, 1 };
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (check[i][j] && v[i][j] == 1) {
                check[i][j] = false;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                while (!q.empty()) {
                    pair<int, int> node;
                    node = q.front();
                    q.pop();
                    count++;
                    int first = node.first;
                    int second = node.second;
                    for (int k = 0; k < 4; k++) {
                        int x = first + dx[k];
                        int y = second + dy[k];
                        if (x > -1 && x < N && y > -1 && y < N && check[x][y] && v[x][y] == 1) {
                            check[x][y] = false;
                            q.push(make_pair(x, y));
                        }
                    }
                }
                answer.push_back(count);
                count = 0;
            }
        }
    }
}

int main(void) {

    int N;
    cin >> N;

    vector<vector<int>> v;
    vector<vector<bool>> check(N, vector<bool>(N, true));
    for (int i = 0; i < N; i++) {
        vector<int> temp;
        for (int j = 0; j < N; j++) {
            int el;
            scanf("%1d", &el);
            temp.push_back(el);
        }
        v.push_back(temp);
    }

    go(N, v, check);

    sort(answer.begin(), answer.end());
    
    printf("%lu\n", answer.size());
    for (auto i = 0; i < answer.size(); i++) {
        printf("%d\n", answer[i]);        
    }

}