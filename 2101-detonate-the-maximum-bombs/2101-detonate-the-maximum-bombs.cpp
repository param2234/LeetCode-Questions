class Solution {
public:

    int dfs(vector<vector<int>>&graph , int sr,vector<bool>&vis){
        vis[sr] = true;
        int ans = 1;

        for(auto &neigh : graph[sr]){
            
            if(!vis[neigh]){
                ans += dfs(graph,neigh,vis);
            }
        }

        return ans;
    }

    
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        vector<vector<int>>graph(bombs.size());
        int ans = 0;

        for(int i = 0;i<bombs.size();i++){
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r1 = bombs[i][2];

            for(int j = 0 ;j<bombs.size();j++){
                if(i == j)continue;

                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];

                if((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) <= r1*r1){
                    graph[i].push_back(j);
                }
            }

        }
        
        for(int i = 0;i<graph.size();i++){
            vector<bool>vis(graph.size(),false);
            ans = max(ans,dfs(graph,i,vis));
        }

        return ans;

    }
};