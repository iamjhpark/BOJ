#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> answerList;

vector<vector<int>> BFS(vector<vector<char>> &map, pair<int, int> startPoint, int h, int w)
{

    int x = startPoint.first;
    int y = startPoint.second;
    vector<vector<bool>> check(h + 2, vector<bool>(w + 2, true));
    vector<vector<int>> value(h + 2, vector<int>(w + 2, 0));
    deque<pair<int, int>> dq;
    dq.push_front(startPoint);
    value[x][y] = 0;

    while (!dq.empty())
    {

        pair<int, int> current = dq.front();
        int currentX = current.first;
        int currentY = current.second;
        dq.pop_front();

        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};
        for (int i = 0; i < 4; i++)
        {
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if (nextX > -1 && nextX < h + 2 && nextY > -1 && nextY < w + 2 && check[nextX][nextY])
            {
                check[nextX][nextY] = false;
                if (map[nextX][nextY] == '.' || map[nextX][nextY] == '$')
                {
                    value[nextX][nextY] = value[currentX][currentY];
                    dq.push_front(make_pair(nextX, nextY));
                }
                else if (map[nextX][nextY] == '#')
                {
                    value[nextX][nextY] = value[currentX][currentY] + 1;
                    dq.push_back(make_pair(nextX, nextY));
                }
            }
        }
    }

    return value;
}

int main(void)
{

    int TC;
    scanf("%d", &TC);

    while (TC > 0)
    {

        int h;
        scanf("%d", &h);

        int w;
        scanf("%d", &w);

        bool first = true;
        pair<int, int> one;
        pair<int, int> another;
        vector<vector<char>> map(h + 2, vector<char>(w + 2, '.'));
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                char el;
                cin >> el;
                if (el == '$' && first)
                {
                    first = false;
                    one = make_pair(i, j);
                }
                else if (el == '$' && !first)
                {
                    another = make_pair(i, j);
                }
                map[i][j] = el;
            }
        }

        vector<vector<int>> valueForOne = BFS(map, one, h, w);
        vector<vector<int>> valueForAnother = BFS(map, another, h, w);
        vector<vector<int>> valueForThem = BFS(map, make_pair(0, 0), h, w);

        int answer = h * w;
        for (int i = 1; i < h + 1; i++)
        {
            for (int j = 1; j < w + 1; j++)
            {
                int count = h * w;
                if (map[i][j] == '#') {
                    count = valueForOne[i][j] + valueForAnother[i][j] + valueForThem[i][j] - 2;
                } else if (map[i][j] == '.' || map[i][j] == '$') {
                    count = valueForOne[i][j] + valueForAnother[i][j] + valueForThem[i][j];
                } 

                if (answer > count) { answer = count; }
            }
        }

        answerList.push_back(answer);

        TC--;
    }

    for (auto i = 0; i < answerList.size(); i++) {
        printf("%d\n", answerList[i]);
    }

    return 0;
}