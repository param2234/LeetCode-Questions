class Solution {
public:

    void dfs(vector<vector<int>>& rooms,int idx,vector<bool>&vis){

        vis[idx] = true;

        for(auto &neigh:rooms[idx]){
            if(!vis[neigh]){
                dfs(rooms,neigh,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        vector<bool>vis(n,false);
        dfs(rooms,0,vis);

        for(int i = 0;i<n;i++){
            if(vis[i] == false)return false;
        }

        return true;
    }
};