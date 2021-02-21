#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<int> answerList;

void makeTree(vector<vector<int>> &edges, vector<pair<int, int>> &nodes) {
    queue<int> q;
    q.push(1);
    nodes[1] = make_pair(1, 1);
    while (!q.empty()) {
        int node = q.front();
        int depth = nodes[node].second;
        q.pop();
        for (int i = 0; i < edges[node].size(); i++) {
            int connectedNode = edges[node][i];
            if (nodes[connectedNode].second == 0) {
                nodes[connectedNode].second = depth + 1;
                nodes[connectedNode].first = node;
                q.push(connectedNode);
            }
        }

    }

}

int LCA(vector<pair<int, int>> &nodes, int a, int b) {

    int depthA = nodes[a].second;
    int depthB = nodes[b].second;

    while (depthA != depthB) {
        if (depthA > depthB) { a = nodes[a].first; depthA = nodes[a].second; }
        else { b = nodes[b].first; depthB = nodes[b].second; }
    }

    int parent = 1;
    if (a == b) { parent = a; }
    while (a != b) {
        a = nodes[a].first;
        b = nodes[b].first;
        if (a == b) { parent = a; break;}
    }

    return parent;

}

int main(void) {

    int N;
    scanf("%d", &N);
    vector<pair<int, int>> nodes(N + 1, make_pair(0, 0));

    vector<vector<int>> edges(N + 1);
    for (int i = 0; i < N - 1; i++) {

        int a;
        scanf("%d", &a);

        int b;
        scanf("%d", &b);

        edges[a].push_back(b);
        edges[b].push_back(a);

    }

    makeTree(edges, nodes);

    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {

        int a;
        scanf("%d", &a);

        int b;
        scanf("%d", &b);

        int answer = LCA(nodes, a, b);
        answerList.push_back(answer);

    }

    for (auto i = 0; i < answerList.size(); i++) {
        printf("%d\n", answerList[i]);
    }

    return 0;
}