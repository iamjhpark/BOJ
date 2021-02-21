#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> v, vector<int> order, int S) {
    int sum = 0;
    for (auto k = 0; k < v.size(); k++) {
        if (order[k] == 1) { sum += v[k]; }
    }
    if (sum == S) { return true; }
    else { return false; }
}

int main(void) {

    int answer = 0;

    int N;
    cin >> N;

    int S;
    cin >> S;

    vector<int> v;
    for (int i = 0; i < N; i++) {
        int el;
        cin >> el;
        v.push_back(el);
    }

    sort(v.begin(), v.end());
    vector<int> order;
    for (int i = N; i > 0; i--) {
        for (int j = 1; j <= N; j++) {
            if (j <= i) {
                order.push_back(1);
            } else {
                order.push_back(0);
            }
        }
        if(check(v, order, S)) { answer++; }
        while (prev_permutation(order.begin(), order.end())) {
            if(check(v, order, S)) { answer++; }           
        }
        order.clear();
    }

    printf("%d", answer);

    return 0;
}