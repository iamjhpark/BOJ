#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int getParent(int a, vector<int> &check) {
    if (a == check[a]) { return a; }
    else { return getParent(check[a], check); }
}

void unionParent(int a, int b, vector<int> &check) {
    a = getParent(a, check);
    b = getParent(b, check);
    if (a > b) { check[a] = b; }
    else { check[b] = a; }
}

bool findParent(int a, int b, vector<int> &check) {
    a = getParent(a, check);
    b = getParent(b, check);
    if (a == b) { return true; }
    else { return false; }
}

long long mst(vector<int> &check, priority_queue<tuple<long long, int, int>> &pq) {
    long long answer = 0;
    while (!pq.empty()) {
        tuple<long long, int, int> current =  pq.top();
        long long weight = -get<0>(current);
        int planet = get<1>(current);
        int anotherPlanet = get<2>(current);
        pq.pop();
        if (!findParent(planet, anotherPlanet, check)) {
            unionParent(planet, anotherPlanet, check);
            answer += weight;
        }
    }
    return answer;
}

int main(void) {

    int N;
    scanf("%d", &N);

    vector<int> check(N);
    for (auto i = 0; i < N; i++) {
        check[i] = i;
    }

    vector<tuple<long long, long long, long long>> planets(N);
    for (int i = 0; i < N; i++) {
        long long x;
        scanf("%lld", &x);
        long long y;
        scanf("%lld", &y);
        long long z;
        scanf("%lld", &z);
        planets[i] = make_tuple(x, y, z);
    }

    priority_queue<tuple<long long, int, int>> pq;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int x = abs(get<0>(planets[i]) - get<0>(planets[j]));
            int y = abs(get<1>(planets[i]) - get<1>(planets[j]));
            int z = abs(get<2>(planets[i]) - get<2>(planets[j]));
            int min = x;
            if (min > y) { min = y; }
            if (min > z) { min = z; }
            pq.push(make_tuple(-min, i, j));
        }
    }

    printf("%lld", mst(check, pq));

    return 0;
}