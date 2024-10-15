#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using Graph = vector<vector<int>>;

void DFSUtil(Graph& G, bool* visited, int V);

void DFS(Graph G, int N, int S) { // 깊이 우선 탐색
    bool* visited = (bool*)malloc(sizeof(bool)*(N+1));
    for(int i=0;i<N+1;i++) visited[i]=false;
    DFSUtil(G, visited, S);
}

void DFSUtil(Graph& G, bool* visited, int V) {
    visited[V] = true;
    cout << V << ' ';
    vector<int> edge = G[V];
    for(vector<int>::iterator it=edge.begin() ; it != edge.end() ; it++) {
        if (!visited[*it]) {
            // visited[*it] = true;
            DFSUtil(G, visited, *it);
        }
    }
}

void BFS(Graph& G, int N, int S) {
    bool* visited = (bool*)malloc(sizeof(bool)*(N+1));
    for(int i=0;i<N+1;i++) visited[i] = false;
    queue<int> order;
    order.push(S);
    visited[S] = true;
    while(order.empty() == 0) {
        S = order.front();
        order.pop();
        cout << S << ' ';
        vector<int> curEdge = G[S];
        for(vector<int>::iterator it = curEdge.begin() ; it != curEdge.end() ; it++) {
            if (visited[*it] == false) {
                visited[*it] = true;
                order.push(*it);
            }
        }
    }
}

int main() {
    int N, M, S;
    cin >> N >> M >> S;
    Graph G(N+1);
    
    for(int i=0;i<M;i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    } // 그래프 표현 완료 - 인접 리스트

    for(int i=0;i<N+1;i++) {
        sort(G[i].begin(), G[i].end());
    }

    DFS(G, N, S);
    cout << '\n';
    BFS(G, N, S);
}