#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int house_count=0;
int pheight_idx=0;
int map[53][53]={};
bool house[53][53]={};
vector<int> post;
vector<int> height;

int min_reachable(int idx) {
    queue<vector<int>> Q;
    Q.push(post);
    int visited_house=0;
    bool visited[53][53]={};
    vector<int> curPos;
    while(!Q.empty()) {
        curPos=Q.front();
        Q.pop();
        if (house[curPos[0]][curPos[1]]) visited_house++;
        for(int t=-1;t<=1;t++) {
            for(int y=-1;y<=1;y++) {
                if (t == 0 && y == 0) ;
                else if (map[curPos[0]+t][curPos[1]+y] >= height[idx] && !visited[curPos[0]+t][curPos[1]+y]) {
                    visited[curPos[0]+t][curPos[1]+y] = true;
                    cout << curPos[0]+t << ' ' << curPos[1]+y << '\n';
                    Q.push({curPos[0]+t, curPos[1]+y});
                }
            }
        }
    }
    return visited_house;
}

int max_reachable(int idx) {
    queue<vector<int>> Q;
    Q.push(post);
    int visited_house=0;
    bool visited[53][53]={};
    vector<int> curPos;
    while(!Q.empty()) {
        curPos=Q.front();
        Q.pop();
        if (house[curPos[0]][curPos[1]]) visited_house++;
        for(int t=-1;t<=1;t++) {
            for(int y=-1;y<=1;y++) {
                if (t == 0 && y == 0);
                else if (0< map[curPos[0]+t][curPos[1]+y] && map[curPos[0]+t][curPos[1]+y] <= height[idx] && !visited[curPos[0]+t][curPos[1]+y]) {
                    visited[curPos[0]+t][curPos[1]+y] = true;
                    cout << curPos[0]+t << ' ' << curPos[1]+y << '\n';
                    Q.push({curPos[0]+t, curPos[1]+y});
                }
            }
        }
    }
    return visited_house;   
}

int main() {
    cin >> N;
    
    for(int r=1;r<=N;r++) {
        char* input = (char*)malloc((N+3)*sizeof(char));
        cin >> input;
        for(int c=1;c<=N;c++) {
            if(input[c-1] == 'P') post={r,c};
            else if (input[c-1] == 'K') {
                house_count++;
                house[r][c]=true;
            }
        }
        free(input);
    }

    for(int r=1;r<=N;r++) {
        for(int c=1;c<=N;c++) {
            cin >> map[r][c];
            height.push_back(map[r][c]);
        }
    }

    sort(height.begin(), height.end());
    height.erase(unique(height.begin(),height.end()), height.end());

    // for(int i=0;i<height.size();i++) cout << height[i] << ' ';

    // for(int i=1;i<=N;i++) {
    //     for(int j=1;j<=N;j++) {
    //         cout << house[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << house_count;

    cout << post[0] << ' ' << post[1] << "\n\n";

    // for(pheight_idx=0;height[pheight_idx]!=map[post[0]][post[1]];pheight_idx++);

    // cout << pheight_idx;

    int min_idx, max_idx;

    for(int min_idx=pheight_idx;min_reachable(min_idx)!=house_count;min_idx--) cout << 'b';
    cout << "asdg\n";
    for(int max_idx=pheight_idx;max_reachable(max_idx)!=house_count;max_idx++) cout << 'a';

    cout << height[max_idx]-height[min_idx];

    return 0;
}