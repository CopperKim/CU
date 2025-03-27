#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> G;
int dp[1000001][16];
int depth[1000001];
int max_depth;

int maxdigit(int n) {
    int iter = 0;
    while(n>1) {
        n = n >> 1;
        iter++;
    }
    return iter;
}

void DFS(int node, int before) {
    for(int i=0;i<G[node].size();i++) {
        int next = G[node][i];
        if (next == before) continue;
        dp[next][0] = node;
        depth[next] = depth[node]+1;
        max_depth = max(max_depth, depth[next]);
        DFS(next, node);
    }
}

int ascending(int node, int height) {
    for(int i=0;height > 0;i++) {
        if (height & 1) node = dp[node][i];
        height = height >> 1;
        cout << node << ' ';
        cout << height << ' ';
        cout << i << '\n';
    }
    return node;
}

int LCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b); // ensure that depth[a] >= depth[b];
    int diff = depth[a] - depth[b];
    a = ascending(a, diff); // depth[a] == depth[b];

    int max = maxdigit(depth[a]);
    while(max-- >= 0) {
        if (dp[a][max] == dp[b][max])
    }
}

int main() {
    int N; cin >> N;
    G = vector<vector<int>>(N+1);
    
    for(int i=0;i<N-1;i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    DFS(1, 0);
    for(int i=1;i<=max_depth;i++) {
        for(int j=2;j<=N;j++) {
            if (dp[j][i-1] != 0) dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }

    for(int i=1;i<=N;i++) cout << "node " << i << ": " << dp[i][0] << ' ' << depth[i] << '\n';

    int M; cin >> M;

    for(int i=0;i<=M;i++) {
        int a, b; cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }
}