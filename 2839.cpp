#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int N, vector<int> &d) {

    if (N == 3 || N == 5) { d[N] = 1; }
    else {
        for (int i = 1; (5 * i) <= N; i++) {
            int A = 5 * i;
            int B = N - A;
            if (A % 5 == 0 && B % 3 == 0 && B > 0) {
                d[N] = d[A] + d[B];
            } else if (A % 5 == 0 && B == 0) {
                d[N] = (N / 5);
            }
        }
        if (d[N] == -1 && N % 3 == 0) {
            d[N] = (N / 3);
        }
    }

}

int main(void) {

    int N;
    scanf("%d", &N);

    vector<int> d(N + 1, -1);
    for (int i = 3; i <= N; i++) {
        solution(i, d);
    }

    printf("%d\n", d[N]);

    return 0;

}