#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int el;
        cin >> el;
        v.push_back(el);
    } 

    if (next_permutation(v.begin(), v.end())) {
        for (int i = 0; i < v.size(); i++) {
            printf("%d ", v[i]);
        }
    } else {
        int answer = -1;
        printf("%d", answer);
    }
}