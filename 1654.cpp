#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long binarySearch(vector<long long> &cables, long long min, int N) {
    long long startIndex = 1;
    long long endIndex = min;
    long long index = 0;
    long long sum = 0;
    while (startIndex <= endIndex) {
        sum = 0;
        index = (startIndex + endIndex) / 2;
        for (auto i = 0; i < cables.size(); i++) {
            sum += (cables[i] / index);
        }
        if (N > sum) { endIndex = index - 1; }
        else { startIndex = index + 1; }
    }
    return endIndex;
}

int main(void) {

    int K;
    int N;
    cin >> K >> N;

    vector<long long> cables(N);
    long long min = 0;
    for (int i = 0; i < K; i++) {
        long long el;
        cin >> el;
        cables.push_back(el);
        if (min == 0 || min < el) { min = el; }
    }

    long long answer = binarySearch(cables, min, N);

    printf("%d\n", answer);

}