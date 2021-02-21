#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> makeTable(string pattern) {
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);
    int j = 0;
    for (int i = 1; i < patternSize; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }
    return table;
}

int main(void) {

    int answer = 0;

    string s;
    cin >> s;

    int sSize = s.size();
    for (int i = 0; i < sSize; i++) {
        vector<int> table = makeTable(s.substr(i, sSize - i));
        int temp = *max_element(table.begin(), table.end());
        if (temp > answer) { answer = temp; }
    }

    printf("%d\n", answer);

    return 0;
}