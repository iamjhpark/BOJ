#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    int N;
    scanf("%d", &N);

    int M;
    scanf("%d", &M);

    int K;
    scanf("%d", &K);

    vector<int> prefixSum(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        int el;
        scanf("%d", &el);
        prefixSum[i] = prefixSum[i - 1] + el;
    }

    

    return 0;
}