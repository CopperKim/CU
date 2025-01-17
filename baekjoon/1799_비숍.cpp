#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n, res=0; 
vector<int> selectedPosIdx;
vector<pair<int, int>> V;

bool testSelectedPos() {
    for(int i=0;i<selectedPosIdx.size()-1;i++) {
        for(int j=i+1;j<selectedPosIdx.size();j++) {
            if (abs(V[i].first-V[j].first) == abs(V[i].second-V[j].second)) return false;
        }
    }
    return true;
}

void BackTrack(int startIdx) {
    for(int i=startIdx;i<V.size();i++) {
        selectedPosIdx.push_back(i);
        if (testSelectedPos()) BackTrack(i+1);
        selectedPosIdx.pop_back();
    }
    for(auto a : selectedPosIdx) cout << a << ' ';
    cout << '\n';
    res = max(res, (int)(selectedPosIdx.size()));
}

int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int input; cin >> input;
            if (input == 1) V.push_back({i, j});
        }
    }

    BackTrack(0);
    cout << res;
}