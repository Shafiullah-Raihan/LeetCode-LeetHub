

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;
        int finalMask = (1 << n) - 1;

        vector<vector<int>> dist(n, vector<int>(1 << n, -1));
        queue<pair<int,int>> q;

        for (int i = 0; i < n; ++i) {
            int m = (1 << i);
            dist[i][m] = 0;
            q.push({i, m});
        }

        while (!q.empty()) {
            auto [u, mask] = q.front(); q.pop();

            if (mask == finalMask) return dist[u][mask];

            for (int v : graph[u]) {
                int nm = mask | (1 << v);
                if (dist[v][nm] == -1) {
                    dist[v][nm] = dist[u][mask] + 1;
                    q.push({v, nm});
                }
            }
        }

        return -1; 
    }
};
