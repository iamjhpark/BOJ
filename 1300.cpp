#include <iostream>

using namespace std;

int main(void) {

    long long N;
    scanf("%lld", &N);

    long long k;
    scanf("%lld", &k);

    long long count = 0;
    long long i = 0;
    while (N - i > 0) {
        int temp = count;
        temp += ((2 * (N - i)) - 1);
        if (temp > k) {
            break;
        } else {
            count = temp;
            i++;
        }
    }

    /*
    k = 8
    i = 1
    j = 5
    */

    k -= count;
    i++;
    long long j = (k / 2) + i;

    printf("%lld", i * j);

    return 0;
}