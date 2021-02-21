#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int INF = 1000000000;

void dijkstra(vector<vector<pair<int, int>>> &graph, vector<int> &d, int K) {

    priority_queue<pair<int, int>> pq;
    d[K] = 0;
    pq.push(make_pair(0, K));

    while (!pq.empty()) {
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (d[current] < distance) { continue; }
        else {
            for (auto i = 0; i < graph[current].size(); i++) {
                int next = graph[current][i].first;
                int nextDistance = graph[current][i].second + distance;
                if (nextDistance < d[next]) {
                    d[next] = nextDistance;
                    pq.push(make_pair(-nextDistance, next));
                }
            }
        }

    }

}

int main(void) {

    int V;
    cin >> V;

    int E;
    cin >> E;

    int K;
    cin >> K;

    vector<int> d(V + 1, INF);
    vector<vector<pair<int, int>>> graph(V + 1);
    for (int i = 0; i < E; i++) {
        int x;
        int y;
        int z;
        cin >> x >> y >> z;
        graph[x].push_back(make_pair(y, z));
    }

    dijkstra(graph, d, K);

    for (auto i = 1; i < d.size(); i++) {
        if (d[i] == INF) { printf("%s\n", "INF"); }
        else { printf("%d\n", d[i]); }
    }

    return 0;
}