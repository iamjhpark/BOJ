#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> answer;
vector<int> integerList;

void makeSegment(map<pair<int, int>, int> &segment, int start, int end) {
    if (start == end) { segment[make_pair(start, end)] = integerList[start - 1]; }
    else if (end - start == 1) {
        segment[make_pair(start, end)] = *min_element(&integerList[start - 1], &integerList[end]);
        makeSegment(segment, start, start);
        makeSegment(segment, end, end);
    }
    else {
        segment[make_pair(start, end)] = *min_element(&integerList[start - 1], &integerList[end]);
        int mid = (start + end) / 2;
        makeSegment(segment, start, mid);
        makeSegment(segment, mid + 1, end);
    }
}

int main(void) {

    int N;
    scanf("%d", &N);

    int M;
    scanf("%d", &M);

    for (int i = 0; i < N; i++) {
        int el;
        scanf("%d", &el);
        integerList.push_back(el);
    }

    map<pair<int, int>, int> segment;
    makeSegment(segment, 1, N);

    vector<pair<int, int>> rangeList;
    for (int i = 0; i < M; i++) {
        int start;
        scanf("%d", &start);
        int end;
        scanf("%d", &end);
        rangeList.push_back(make_pair(start, end));
    }

    for (auto i = 0; i < rangeList.size(); i++) {
        int start = rangeList[i].first;
        int end = rangeList[i].second;
        if (segment[make_pair(start, end)] == 0) {

            answer.push_back(segment[make_pair(start, end)]);
        } else { answer.push_back(segment[make_pair(start, end)]); }
    }

    for (auto i = 0; i < answer.size(); i++) {
        printf("%d\n", answer[i]);
    }

    return 0;

}