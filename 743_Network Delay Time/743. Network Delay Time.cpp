/************************************************************************
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node,
and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal?
If it is impossible, return -1.

Note:
N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.
*************************************************************************/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <windows.h>

using namespace std;


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int graph[N+1][N+1];
        memset(graph, 0x3f3f3f3f, sizeof(graph));
        for (int i = 0; i < times.size(); ++i) {
            graph[times[i][0]][times[i][1]] = times[i][2];
        }
        vector<int> dist(N+1, 0x3f3f3f3f);
        vector<bool> vis(N+1, 0);
        vis[K] = true;
        for (int i = 1; i <= N; ++i) {
            dist[i] = graph[K][i];
        }
        dist[K] = 0;
        while (1) {
            int v = -1;
            for (int u = 1; u <= N; ++u) {
                if (!vis[u] && (v == -1 || dist[u] < dist[v])) {
                    v = u;
                }
            }
            if (v == -1) {
                break;
            }
            vis[v] = 1;
            for (int u = 1; u <= N; ++u) {
                dist[u] = min(dist[u], dist[v] + graph[v][u]);
            }
        }
        int res = -1;
        for (int i = 1; i <= N; ++i) {
            //cout << "dist[" << i << "] is: " << dist[i] << endl;
            if (dist[i] == 0x3f3f3f3f) {
                res = -1;
                break;
            }
            else {
                res = max(res, dist[i]);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> times {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k = 2;
    int res = Solution().networkDelayTime(times, n, k);
    cout << res << endl;
    return 0;
}