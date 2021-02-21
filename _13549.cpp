#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool flag = true;

void BFS(int start, int end) {
    vector<bool> check(100001, true);
    queue<pair<int, int>> current;
    queue<pair<int, int>> next;
    current.push(make_pair(start, 0));
    check[start] = false;
    while (!current.empty() || !next.empty()) {
        pair<int, int> front;
        if (flag) { 
            front = current.front();
            current.pop();
        } else {
            front = next.front();
            next.pop();
        }

    }
}

int main(void) {

    return 0;
}