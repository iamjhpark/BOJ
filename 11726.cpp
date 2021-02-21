#include <iostream>
#include <vector>

using namespace std;

void solution(vector<int> &d, int n) {

    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= n; i++) {
        d[i] = (d[i - 1] + d[i - 2]) % 10007;
    }

}

int main(void) {

    int n;
    scanf("%d", &n);

    vector<int> d(n + 1, 0);

    solution(d, n);
    int answer = d[n];
    printf("%d\n", answer); 

    return 0;

}