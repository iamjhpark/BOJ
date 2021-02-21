#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(vector<vector<int>> &d, vector<vector<int>> &triangle, int n) {

    d[1][1] = triangle[1][1];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            d[i + 1][j] = max(d[i + 1][j], d[i][j] + triangle[i + 1][j]);
            d[i + 1][j + 1] = max(d[i + 1][j + 1], d[i][j] + triangle[i + 1][j + 1]);
        }
    }

}

int main(void) {

    int n;
    scanf("%d", &n);

    vector<vector<int>> d(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> triangle(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i + 1; j++) {
            int el;
            scanf("%d", &el);
            triangle[i][j] = el;
        }
    }

    solution(d, triangle, n);
    vector<int> lastRow = d[n];
    int max = *max_element(lastRow.begin(), lastRow.end());
    printf("%d\n", max);

    return 0;
}