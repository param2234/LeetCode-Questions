class Solution {
public:

    void dfs(vector<vector<char>>& grid, int& islands,int i,int j,int m,int n){

        grid[i][j] = '0';

        if(i>=1 && grid[i-1][j] == '1'){
            dfs(grid,islands,i-1,j,m,n);
        }

        if(j>=1 && grid[i][j - 1] == '1'){
            dfs(grid,islands,i,j-1,m,n);
        }

        if(i<= m-2 && grid[i+1][j] == '1'){
            dfs(grid,islands,i+1,j,m,n);
        }

        if(j<=n-2 && grid[i][j+1] == '1'){
            dfs(grid,islands,i,j+1,m,n);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int islands = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(grid,islands,i,j,m,n);
                }
            }
        }

        return islands;
    }
};