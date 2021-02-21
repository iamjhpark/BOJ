#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

long long answer = 0;

int getParent(vector<int> &nodes, int a) {
    if (nodes[a] == a) { return a; }
    else { return getParent(nodes, nodes[a]); }
}

void unionParent(vector<int> &nodes, int a, int b) {
    a = getParent(nodes, a);
    b = getParent(nodes, b);
    if (a > b) { nodes[a] = b; }
    else { nodes[b] = a; }
}

bool findParent(vector<int> &nodes, int a, int b) {
    a = getParent(nodes, a);
    b = getParent(nodes, b);
    if (a == b) { return true; }
    else { return false; }
}

void mst(vector<int> &nodes, priority_queue<tuple<int, int, int>> &pq) {
    while (!pq.empty()) {
        tuple<int, int, int> edge = pq.top();
        int weight = -get<0>(edge);
        int computer = get<1>(edge);
        int anotherComputer = get<2>(edge);
        pq.pop();
        if (!findParent(nodes, computer, anotherComputer)) {
            unionParent(nodes, computer, anotherComputer);
            answer += weight;
        }
    }
}

int main(void) {

    int N;
    scanf("%d", &N);

    int M;
    scanf("%d", &M);

    vector<int> nodes(N + 1);
    for (int i = 0; i <= N; i++) {
        nodes[i] = i;
    }

    priority_queue<tuple<int, int, int>> pq;
    for (int i = 0; i < M; i++) {
        int computer;
        int anotherComputer;
        int weight;
        scanf("%d", &computer);
        scanf("%d", &anotherComputer);
        scanf("%d", &weight);
        pq.push(make_tuple(-weight, computer, anotherComputer));
    }

    mst(nodes, pq);

    printf("%lld\n", answer);

    return 0;
}