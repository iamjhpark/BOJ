#include <iostream>
#include <vector>

using namespace std;

void rotateGearWheels(vector<vector<int>> &gearWheels, vector<pair<int, int>> &rotationWays) {

    for (auto i = 0; i < rotationWays.size(); i++) {
        int gearWheel = rotationWays[i].first;
        int directiton = rotationWays[i].second;
        
    }
}

int main(void) {

    int T;
    scanf("%d", &T);

    vector<vector<int>> gearWheels(T);
    for (int i = 0; i < T; i++) {
        int el;
        scanf("%d", &el);
        gearWheels[i].push_back(el);
    }

    int K;
    scanf("%d", &K);

    vector<pair<int, int>> rotationWays;
    for (int i = 0; i < K; i++) {
        int gearWheel;
        scanf("%d", &gearWheel);
        int direction;
        scanf("%d", &direction);
        rotationWays.push_back(make_pair(gearWheel, direction));
    }


    
}