class Solution {
public:

    bool dfs(vector<vector<int>>&graph,int source,int des,vector<bool>&vis){

        vis[source] = true;

        if(source == des)return true;

        for(auto neigh:graph[source]){

            if(!vis[neigh]){
                if(dfs(graph,neigh,des,vis))return true;
            }
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>>graph(n);
        vector<bool>vis(n,false);

        for(auto pair:edges){
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
            
        }

        return dfs(graph,source,destination,vis);
    }
};