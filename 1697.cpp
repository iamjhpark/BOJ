#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<bool> check = vector<bool>(200001, true);

int BFS(pair<int, int> p, int E) {
    int count = 0;
    queue<pair<int, int>> q;
    q.push(p);
    int first = p.first;
    check[first] = false;
    while (!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();
        int x = node.first;
        if (x - 1 >= 0 && check[x - 1]) {
            if (x - 1 == E) { count = node.second + 1; break;}
            check[x - 1] = false;
            q.push(make_pair(x - 1, node.second + 1));
         } 
         if (x + 1 >= 0 && check[x + 1]) {
             if (x + 1 == E) { count = node.second + 1; break;}
             check[x + 1] = false;
             q.push(make_pair(x + 1, node.second + 1));
         } 
         if (2 * x <= 100000 && check[2 * x]) {
             if (2 * x == E) { count = node.second + 1; break;}
             check[2 * x] = false;
             q.push(make_pair(2 * x, node.second + 1));
         }
    }
    return count;
}

int main(void) {

    int S;
    cin >> S;
    
    int E;
    cin >> E;

    int answer = BFS(make_pair(S, 0), E);
    printf("%d\n", answer);

    return 0;

}