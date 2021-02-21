#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 1000000000;

vector<int> answer;

void Dijkstra(vector<vector<pair<int, int>>> &busesInfo, vector<int> &d, vector<int> &route, int start, int end) {

    priority_queue<pair<int, int>> pq; // make_pair(weight, nextNode);
    d[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        pair<int, int> currentNode = pq.top();
        int distance = -currentNode.first;
        int current = currentNode.second;
        pq.pop();
        if (d[current] < distance) { continue; }
        for (int i = 0; i < busesInfo[current].size(); i++) {
            pair<int, int> nextNode = busesInfo[current][i];
            int nextDistance = -nextNode.first + distance;
            int next = nextNode.second;
            if (d[next] <= nextDistance) { continue; }
            else {
                d[next] = nextDistance;
                route[next] = current;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
    
    printf("%d\n", d[end]);
    //
    int i = end;
    answer.push_back(i);
    while (i != start) {
        i = route[i];
        answer.push_back(i);
    }

    int j = answer.size();
    printf("%d\n", j);
    while (j > 0) {
        printf("%d ", answer[j - 1]);
        j--;
    }

}

int main(void) {

    int n;
    scanf("%d", &n);

    int m; 
    scanf("%d", &m);

    vector<int> d(n + 1, INF);
    vector<int> route(n + 1, 0);
    vector<vector<pair<int, int>>> busesInfo(m + 1);
    for (int i = 0; i < m; i++) {
        int start;
        scanf("%d", &start);

        int end;
        scanf("%d", &end);

        int distance;
        scanf("%lld", &distance);

        busesInfo[start].push_back(make_pair(-distance, end));
    }

    int start;
    scanf("%d", &start);

    int end;
    scanf("%d", &end);

    Dijkstra(busesInfo, d, route, start, end);

    return 0;
}