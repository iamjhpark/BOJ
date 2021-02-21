#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int INF = 1000000000;

vector<int> dijkstra(vector<vector<pair<int, int>>> &map, int N, int start) {
    vector<int> d(N + 1, INF);
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    d[start] = 0;
    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        int weight = -current.first;
        int town = current.second;
        pq.pop();
        for (auto i = 0; i < map[town].size(); i++) {
            int nextWeight = -map[town][i].first + weight;
            int nextTown = map[town][i].second;
            if (d[nextTown] <= nextWeight) { continue; }
            else {
                d[nextTown] = nextWeight;
                pq.push(make_pair(-nextWeight, nextTown));
            }
        }
    }
    return d;
}

int main(void) {

    int N;
    scanf("%d", &N);

    int M;
    scanf("%d", &M);

    int X;
    scanf("%d", &X);

    vector<vector<pair<int, int>>> map(N + 1);
    for (int i = 0; i < M; i++) {
         
        int town;
        scanf("%d", &town);

        int anotherTown;
        scanf("%d", &anotherTown);

        int weight;
        scanf("%d", &weight);

        map[town].push_back(make_pair(-weight, anotherTown));

    }

    vector<int> d = dijkstra(map, N, X);
    vector<int> answer(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        vector<int> temp = dijkstra(map, N, i);
        answer[i] = temp[X] + d[i];
    }

    int max = *max_element(answer.begin(), answer.end());

    printf("%d\n", max);

    return 0;
}