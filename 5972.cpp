#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int INF = 1000000000;

void dijkstra(priority_queue<tuple<int, int, int>> &pq, vector<vector<pair<int, int>>> &map, vector<int> &d) {

    d[1] = 0;
    while (!pq.empty()) {

        tuple<int, int, int> current = pq.top();
        pq.pop();
        int weight = -get<0>(current);
        int currentNode = get<1>(current);
        int nextNode = get<2>(current);

        if (d[nextNode] > d[currentNode] + weight) {
            d[nextNode] = d[currentNode] + weight;
            for (int i = 0; i < map[nextNode].size(); i++) {
                pair<int, int> next = map[nextNode][i];
                pq.push(make_tuple(-next.second, nextNode, next.first));
            }
        }

    }

}

int main(void) {

    int N;
    scanf("%d", &N);

    int M;
    scanf("%d", &M);

    priority_queue<tuple<int, int, int>> pq;
    vector<int> d(N + 1, INF);
    vector<vector<pair<int, int>>> map(N + 1);
    for (int i = 0; i < M; i++) {
        int start;
        scanf("%d", &start);

        int end;
        scanf("%d", &end);

        int weight;
        scanf("%d", &weight); 

        map[start].push_back(make_pair(end, weight));
        map[end].push_back(make_pair(start, weight));

        if (start == 1) { pq.push(make_tuple(-weight, start, end)); }
        else if (end == 1) { pq.push(make_tuple(-weight, end, start)); }

    }

    dijkstra(pq, map, d);

    int answer = d[N];
    printf("%d", answer);

    return 0;

}