#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int count(int sum, int n) {
    if (sum > n) { return 0; }
    else if (sum == n) { return 1; }
    return count(sum + 1, n) + count(sum + 2, n) + count(sum + 3, n);
}

int main(void) {

    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        int n;
        cin >> n;
        int answer = count(1, n) + count(2, n) + count(3, n);
        printf("%d\n", answer);        
    }

    return 0;

}