#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long answer = 0;

int main(void) {

    string expression;
    cin >> expression;

    int i = 0;
    bool minus = false;
    while (i < expression.size()) {
        
        if (expression[i] == '-') { minus = true; i++; continue; }
        if (expression[i] == '+') { i++; continue; }

        string number = "";
        while (i < expression.size() && expression[i] != '+' && expression[i] != '-') {
            number += expression[i];
            i++;
        }

        if (minus) { answer -= stoi(number); }
        else { answer += stoi(number); }
        
    }

    printf("%lld\n", answer);

    return 0;

}