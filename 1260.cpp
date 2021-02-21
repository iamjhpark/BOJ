#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

void DFS(vector<vector<int>> graph, vector<bool> &check, int node) {
    check[node] = false;
    printf("%d ", node);
    for (int i = 0; i < graph[node].size(); i++) {
        int nextNode = graph[node][i];
        if (check[nextNode]) {
            DFS(graph, check, nextNode);
        }
    }
}

void BFS(vector<vector<int>> graph, vector<bool> &check, int node) {
    queue<int> q;
    check[node] = false;
    q.push(node);
    while (!q.empty()) {
        int currentNode = q.front();
        printf("%d ", currentNode);
        q.pop();
        for (int i = 0; i < graph[currentNode].size(); i++) {
            int nextNode = graph[currentNode][i];
            if (check[nextNode]) {
                check[nextNode] = false;
                q.push(nextNode);
            }
        }
    }
}

int main(void) {

    int N;
    cin >> N;
    vector<vector<int>> graph(N + 1);

    int M;
    cin >> M;

    int V;
    cin >> V;

    for (int i = 0; i < M; i++) {
        int startNode;
        cin >> startNode;
        int endNode;
        cin >> endNode;
        graph[startNode].push_back(endNode);
        graph[endNode].push_back(startNode);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<bool> check(N + 1, true);
    DFS(graph, check, V);
    check.clear();
    check.assign(N + 1, true);
    printf("\n");
    BFS(graph, check, V);

    return 0;
}