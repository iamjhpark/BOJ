#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string.h>

using namespace std;

int sum(string N) {
    int result;
    for (auto i = 0; i < N.size(); i++) {
        result += N[i] - '0';
    }
    return result;
}

bool desc(int a, int b) {
    return a > b;
}

int main(void) {

    string N;
    cin >> N;
    sort(N.begin(), N.end(), desc);
    bool check = true;
    if (N[N.size() - 1] == '0' && sum(N) % 3 == 0) { cout << N << '\n'; check = false; }
    while (prev_permutation(N.begin(), N.end()) && check) {
        if (N[N.size() - 1] == '0' && sum(N) % 3 == 0) { cout << N << '\n'; check = false; }
    }
    if (check) { printf("%d\n", -1); }
    
    return 0;

}