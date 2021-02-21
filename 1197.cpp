#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int answer = 0;

int getParent(vector<int> &nodes, int a) {
    if (nodes[a] == a) { return a; }
    return nodes[a] = getParent(nodes, nodes[a]);
}

void unionParent(vector<int> &nodes, int a, int b) {
    a = getParent(nodes, a); //
    b = getParent(nodes, b); //
    if (a < b) { nodes[b] = a; }
    else { nodes[a] = b; }
}

bool findParent(vector<int> &nodes, int a, int b) {
    a = getParent(nodes, a); //
    b = getParent(nodes, b); //
    if (a == b) { return true; }
    else { return false; }
}

void mst(priority_queue<tuple<int, int, int>> &pq, vector<int> &nodes) {
    while (!pq.empty()) {
        int weight = -get<0>(pq.top());
        int node = get<1>(pq.top());
        int anotherNode = get<2>(pq.top());
        pq.pop();
        if (!findParent(nodes, node, anotherNode)) {
            answer += weight;
            unionParent(nodes, node, anotherNode);
        }
    }
}

int main(void) {

    int V;
    int E;
    cin >> V >> E;

    priority_queue<tuple<int, int, int>> pq;
    for (int i = 0; i < E; i++) {   
        int node;
        int anotherNode;
        int weight;
        cin >> node >> anotherNode >> weight;
        pq.push(make_tuple(-weight, node, anotherNode));
    }

    vector<int> nodes(V + 1);
    for (auto i = 0; i < nodes.size(); i++) {
        nodes[i] = i;
    }

    mst(pq, nodes);

    printf("%d", answer);

}