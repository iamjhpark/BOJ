#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int calculate(vector<vector<int>> v, vector<int> order) {
    if (v[0][order[0]] == 0) { return -1; }
    int weight = v[0][order[0]];
    for (int i = 1; i < order.size(); i++) {
        if (v[order[i - 1]][order[i]] == 0) { return -1; }
        weight += v[order[i - 1]][order[i]];
    }
    if (v[order[order.size() - 1]][0] == 0) { return -1; }
    weight += v[order[order.size() - 1]][0];
    return weight;
}

int main(void) {

    int answer = -1;
    int n;
    cin >> n;
    vector<vector<int>> v;
    vector<int> order ;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for(int j = 0; j < n; j++) {
            int el;
            cin >> el;
            temp.push_back(el);
        }
        if (i != 0) { order.push_back(i); }
        v.push_back(temp);
    }
    answer = calculate(v, order);
    while (next_permutation(order.begin(), order.end())) {
        int weight = calculate(v, order);
        if ((answer < 0 || answer > weight) && weight > 0) { answer = weight; }
    }
    printf("%d", answer);

}