#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

    int N;
    scanf("%d", &N);

    vector<int> d(N + 1, -1);
    d[1] = 0;
    d[2] = 1;
    d[3] = 1;
    for (int i = 4; i <= N; i++) {
        vector<int> temp;
        if (i % 3 == 0) { temp.push_back(d[i / 3] + 1); }
        if (i % 2 == 0) { temp.push_back(d[i / 2] + 1); }
        temp.push_back(d[i - 1] + 1);
        d[i] = *min_element(temp.begin(), temp.end());
    }

    printf("%d\n", d[N]);

    return 0;

}