#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isPossibleCase(string N, map<int, bool> &brokenButtons) {
    for (auto i = 0; i < N.size(); i++) {
        char integer = N.at(i);
        if (brokenButtons[atoi(&integer)]) { return false; }
    }
    return true;
}

int go(int N, map<int, bool> &brokenButtons) {
    int answer = abs(100 - N);
    if (brokenButtons.size() == 10) { return answer; }
    int count = 0;
    if (isPossibleCase(to_string(N), brokenButtons)) { 
        int temp = to_string(N).size(); 
        if (answer > temp) { answer = temp; }
    }
    int i = 0;
    while (true) {
        i++;
        if (isPossibleCase(to_string(N - i), brokenButtons)) { 
            int temp =  to_string(N - i).size() + i;
            if (answer > temp) { answer = temp; break; } else { break; } 
        }
        if (isPossibleCase(to_string(N + i), brokenButtons)) { 
            int temp =  to_string(N + i).size() + i;
            if (answer > temp) { answer = temp; break; } else { break; } 
        }
    }
    return answer;
}

int main(void) {

    int N;
    scanf("%d", &N);

    int M;
    scanf("%d", &M);

    map<int, bool> brokenButtons;
    for (int i = 0; i < M; i++) {
        int el;
        scanf("%d", &el);
        brokenButtons[el] = true;
    }

    int answer = go(N, brokenButtons);

    printf("%d\n", answer);

    return 0;
}