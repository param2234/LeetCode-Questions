class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis) {

        vis[node] = true;

        for (auto& neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(neigh, adj, vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for (auto& i : invocations) {
            adj[i[0]].push_back(i[1]);
        }

        vector<bool> vis(n, false);
        dfs(k, adj, vis);

        for (auto& i : invocations) {
            int u = i[0];
            int v = i[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;

                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }

                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};