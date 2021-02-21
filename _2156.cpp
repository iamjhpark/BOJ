#include <iostream>
#include <vector>

using namespace std;

void solution(vector<int> &v, vector<int> &d, int n) {

    

}

int main(void) {

    int n;
    scanf("%d", &n);

    vector<int> v(n + 1, 0);
    vector<int> d(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        int el;
        scanf("%d", &el);
        v[i] = el;
    }

    

    return 0;
}