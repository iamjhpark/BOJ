#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<char> v, vector<int> order) {
    int consonant = 0;
    int vowel = 0;
    for (auto i = 0; i < order.size(); i++) {
        if (order[i] == 1) {
            if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u' ) {
                vowel++;
            } else {
                consonant++;
            }
        } 
    }
    if (consonant >= 2 && vowel >= 1) {
        return true;
    } else {
        return false;
    }
}

void print(vector<char> v, vector<int> order) {
    for (auto i = 0; i < order.size(); i++) {
        if (order[i] == 1) {
            printf("%c", v[i]);
        }
    }
    printf("\n");
}

int main(void) {

    int n;
    cin >> n;

    int total;
    cin >> total;

    vector<char> v;
    vector<int> order;
    for (int i = 0; i < total; i++) {
        char el;
        cin >> el;
        v.push_back(el);
        if (i < n) { order.push_back(1); }
        else { order.push_back(0); }
    }

    sort(v.begin(), v.end());
    if (check(v, order)) { print(v, order); }
    while (prev_permutation(order.begin(), order.end())) {
        if (check(v, order)) {
            print(v, order);
        }
    }

    return 0;

}