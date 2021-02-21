#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> answer;

void BFS(int A, int B, int C, vector<vector<bool>> &check) {

    int sum = C;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    check[0][0] = false;

    vector<int> from = { 0, 0, 1, 1, 2, 2  };
    vector<int> to = { 1, 2, 0, 2, 0, 1 };

    while (!q.empty()) {
        pair<int, int> current = q.front();
        int currentA = current.first;
        int currentB = current.second;
        int currentC = sum - (currentA + currentB);
        q.pop();
        if (currentA == 0) { answer.push_back(currentC); }

        for (int i = 0; i < 6; i++) {
            if (from[i] == 0 && to[i] == 1) {
                if (currentA == 0) { continue; }
                else if (currentA + currentB > B) {
                    int nextA = currentA - (B - currentB);
                    int nextB = B;
                    int nextC = sum - (nextA + nextB);
                    if (check[nextA][nextB]) {
                        check[nextA][nextB] = false;
                        q.push(make_pair(nextA, nextB));
                    }
                } else {
                    int nextA = 0;
                    int nextB = currentA + currentB;
                    int nextC = sum - (nextA + nextB);
                    if (check[nextA][nextB]) {
                        check[nextA][nextB] = false;
                        q.push(make_pair(nextA, nextB));
                    }
                }
            } else if (from[i] == 0 && to[i] == 2) {
                if (currentA == 0) { continue; }
                else if (currentA + currentC > C) {
                    int nextA = currentA - (C - currentC);
                    int nextC = C;
                    int nextB = sum - (nextA + nextC);
                    if (check[nextA][nextB]) {
                        check[nextA][nextB] = false;
                        q.push(make_pair(nextA, nextB));
                    }
                } else {
                    int nextA = 0;
                    int nextC = currentA + currentC;
                    int nextB = sum - (nextA + nextC);
                    if (check[nextA][nextB]) {
                        check[nextA][nextB] = false;
                        q.push(make_pair(nextA, nextB));
                    }
                }
            } else if (from[i] == 1 && to[i] == 0) {
                if (currentB == 0) { continue; }
                else if (currentB + currentA > A) {
                    int nextB = currentB - (A - currentA);
                    int nextA = A;
                    int nextC = sum - (nextB + nextA);
                    if (check[nextA][nextB]) {
                        check[nextA][nextB] = false;
                        q.push(make_pair(nextA, nextB));
                    }
                } else {
                    int nextB = 0;
                    int nextA = currentB + currentA;
                    int nextC = sum - (nextB + nextA);
                    if (check[nextA][nextB]) {
                        check[nextA][nextB] = false;
                        q.push(make_pair(nextA, nextB));
                    }
                }
            } else if (from[i] == 1 && to[i] == 2) {
                if (currentB == 0) { continue; }
                else if (currentB + currentC > C) {
                    int nextB = currentB - (C - currentC);
                    int nextC = C;
                    int nextA = sum - (nextB + nextC);
                    if (check[nextA][nextB]) {
                        check[nextA][nextB] = false;
                        q.push(make_pair(nextA, nextB));
                    }
                } else {
                    int nextB = 0;
                    int nextC = currentB + currentC;
                    int nextA = sum - (nextB + nextC);
                    if (check[nextA][nextB]) {
                        check[nextA][nextB] = false;
                        q.push(make_pair(nextA, nextB));
                    }
                }
            } else if (from[i] == 2 && to[i] == 0) {
                if (currentC == 0) { continue; }
                else if (currentC + currentA > A) {
                    int nextC = currentC - (A - currentA);
                    int nextA = A;
                    int nextB = sum - (nextC + nextA);
                    if (check[nextA][nextB]) {
                        check[nextA][nextB] = false;
                        q.push(make_pair(nextA, nextB));
                    }
                } else {
                    int nextC = 0;
                    int nextA = currentC + currentA;
                    int nextB = sum - (nextC + nextA);
                    if (check[nextA][nextB]) {
                        check[nextA][nextB] = false;
                        q.push(make_pair(nextA, nextB));
                    }
                }
            } else if (from[i] == 2 && to[i] == 1) {
                if (currentC == 0) { continue; }
                else if (currentC + currentB > B) {
                    int nextC = currentC - (B - currentB);
                    int nextB = B;
                    int nextA = sum - (nextC + nextB);
                    if (check[nextA][nextB]) {
                        check[nextA][nextB] = false;
                        q.push(make_pair(nextA, nextB));
                    }
                } else {
                    int nextC = 0;
                    int nextB = currentC + currentB;
                    int nextA = sum - (nextC + nextB);
                    if (check[nextA][nextB]) {
                        check[nextA][nextB] = false;
                        q.push(make_pair(nextA, nextB));
                    }
                }
            }
        }

    }
}

int main(void) {

    int A;
    scanf("%d", &A);
    int B;
    scanf("%d", &B);
    int C;
    scanf("%d", &C);

    vector<vector<bool>> check(201, vector<bool>(201, true));

    BFS(A, B, C, check);

    sort(answer.begin(), answer.end());

    for (auto i = 0; i < answer.size(); i++) {
        printf("%d ", answer[i]);
    }

    return 0;

}