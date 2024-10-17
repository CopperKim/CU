// https://www.acmicpc.net/problem/3190

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int N, K; 
    cin >> N;
    cin >> K;
    bool apple[105][105] = {};
    deque<vector<int>> snake;
    snake.push_back({1, 1});
    for(int i=0;i<K;i++) {
        int a, b; cin >> a >> b;
        apple[a][b] = true;
    }
    int L, time = 0; cin >> L;
    int dir = 1; // 0 : 위 1 : 오 2 : 아래 3 : 좌
    for(int i=0;i<L;i++) {
        int X;
        char C; 
        cin >> X >> C;
        X = X-time;
        for(int i=0;i<X;i++) {
            switch(dir) {
                case 0 : for(int j=0;j<X;j++) {
                    snake.push_back({snake.back()[0], snake.back()[1]-1});
                }
                case 1 : for(int j=0;j<X;j++) {
                    snake.push_back({snake.back()[0]+1, snake.back()[1]});
                }
                case 2 : for(int j=0;j<X;j++) {
                    snake.push_back({snake.back()[0], snake.back()[1]+1});
                }
                case 3 : for(int j=0;j<X;j++) {
                    snake.push_back({snake.back()[0]-1, snake.back()[1]});
                }
            }
            bool bak = false;
            if (1>snake.back()[0] || snake.back()[0] > N-1 || 1>snake.back()[1] || snake.back()[1] < N-1 ) bak = true;
            for(int j=0;j<snake.size();j++) {
                if (snake.back() == snake[j]) bak = true;
            }
            if (bak) {
                ::cout << time;
                return 0;
            }   
            if (!apple[snake.back()[0]][snake.back()[1]]) snake.pop_front();
        }
        if (C == 'D') dir = (dir + 1) % 4;
        else dir = (dir - 1) % 4;
    }
    ::cout << time;
    return 0;
}