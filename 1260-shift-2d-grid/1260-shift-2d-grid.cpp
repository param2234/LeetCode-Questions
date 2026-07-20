class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>arr;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                arr.push_back(grid[i][j]);
            }
        }

        vector<int>ans(arr.size());
        
        k = k % arr.size();

        for(int i = 0;i<arr.size();i++){
            ans[(i + k) % (arr.size())] = arr[i];
        }

        int z = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                grid[i][j] = ans[z++];
            }
        }

        return grid;

        
    }
};