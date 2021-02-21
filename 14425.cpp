#include <iostream>
#include <map>

using namespace std;

int answer = 0;

int main(void) {

    int N;
    scanf("%d", &N);

    int M;
    scanf("%d", &M);

    map<string, bool> set;
    for (int i = 0; i < N; i++) {
        string el;
        cin >> el;
        set[el] = true;
    }

    for (int i = 0; i < M; i++) {
        string el;
        cin >> el;
        if (set[el]) { answer++; }
    }

    printf("%d\n", answer);

    return 0;
}