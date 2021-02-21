#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(vector<vector<int>> &d, vector<int> &w, vector<int> &v, int N, int K) {

    for (int i = 1; i <= N; i++) {

        int weight = w[i];
        int value = v[i];

        for (int j = 1; j <= K; j++) {

            if (weight <= j) {
                d[i][j] = max(d[i - 1][j], d[i - 1][j - weight] + value);
            } else {
                d[i][j] = d[i - 1][j];
            }

        }

    }

}

int main(void) {

    int N;
    scanf("%d", &N);

    int K;
    scanf("%d", &K);

    vector<vector<int>> d(N + 1, vector<int>(K + 1, 0));
    vector<int> w(N + 1, 0);
    vector<int> v(N + 1, 0);
    for (int i = 1; i <= N; i++) {

        int W;
        scanf("%d", &W);
        w[i] = W;

        int V;
        scanf("%d", &V);
        v[i] = V;

    }

    solution(d, w, v, N, K);

    int answer = d[N][1];
    for (int i = 2; i <= K; i++) {
        if (answer < d[N][i]) {
            answer = d[N][i];
        }
    }

    printf("%d\n", answer);

    return 0;
}