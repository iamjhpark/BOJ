#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int el;
        cin >> el;
        v.push_back(el);
    }
    sort(v.begin(), v.end());
    int max = 0;
    while (next_permutation(v.begin(), v.end())) {
        int sum = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            sum += abs(v[i] - v[i + 1]);
        }
        if (sum > max) {
            max = sum;
        }
    }
    printf("%d", max);
}