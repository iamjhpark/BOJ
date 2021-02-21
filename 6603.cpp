#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> v, vector<int> order) {
    for (auto i = 0; i < order.size(); i++) {
        if (order[i] == 1) {
            printf("%d ", v[i]);
        }
    }
    printf("\n");
}

int main(void) {

    int n;
    cin >> n;
    while (n != 0) {
        int el;
        vector<int> v;
        vector<int> order;
        for (int i = 0; i < n; i++) {
            cin >> el;
            v.push_back(el);
            if (i < 6) {
                order.push_back(1);
            } else {
                order.push_back(0);
            }
        }
        print(v, order);
        while (prev_permutation(order.begin(), order.end())) {
            print(v, order);
        }
        printf("\n");
        cin >> n;
    }
    return 0;
}