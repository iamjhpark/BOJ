#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

    vector<int> v;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }

    for (int i = 0; i < v.size(); i++) {
            printf("%d ", v[i]);
    }
    
    while (next_permutation(v.begin(), v.end())) {
        printf("\n");
        for (int i = 0; i < v.size(); i++) {
            printf("%d ", v[i]);
        }
    }
}