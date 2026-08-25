class Solution {
public:

    void dfs(vector<vector<int>>&graph,int idx,vector<bool>&vis){

        vis[idx] = true;

        for(auto neigh:graph[idx]){
            if(!vis[neigh]){
                dfs(graph,neigh,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<vector<int>>graph(n);

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j] == 1){
                    graph[i].push_back(j);
                }
            }
        }

        vector<bool>vis(n,false);
        int ans = 0;

        for(int i = 0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(graph,i,vis);
            }
        }


        return ans;
    }
};