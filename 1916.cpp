#include <iostream>
#include <vector>
#include <tuple>
#include <stack>

using namespace std;

int answer = 0;

void BFS(vector<vector<int>> &buses, int N, int start, int end) {

    stack<pair<int, int>> s;
    for (auto i = 1; i <= N; i++) {
        if (buses[start][i] != -1 && i != end) { s.push(make_pair(start, i)); }
    }

    while (!s.empty()) {
        pair<int, int> node = s.top();
        int startingPoint = node.first;
        int arrivalPoint = node.second;
        s.pop();
    }
}

int main(void) {

    int N;
    cin >> N;

    int M;
    cin >> M;

    vector<vector<int>> buses = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
    for (int i = 0; i < M; i++) {
        
        int start;
        cin >> start;

        int end;
        cin >> end;

        int cost;
        cin >> cost;

        buses[start][end] = cost;

    }

    int start;
    cin >> start;

    int end;
    cin >> end;

    BFS(buses, N, start, end);
    printf("%d", buses[start][end]);

    return 0;
}