class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int target,int m,int n){

        image[sr][sc] = color;

        if(sr>=1 && image[sr-1][sc] == target){
            dfs(image,sr-1,sc,color,target,m,n);
        }

        if(sr<= m-2 && image[sr + 1][sc] == target){
            dfs(image,sr+1,sc,color,target,m,n);
        }

        if(sc<= n-2 && image[sr][sc + 1] == target){
            dfs(image,sr,sc+1,color,target,m,n);
        }

        if(sc>= 1 && image[sr][sc - 1] == target){
            dfs(image,sr,sc - 1,color,target,m,n);
        }

    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int target = image[sr][sc];
        int m = image.size();
        int n = image[0].size();

        if(target == color)return image;
        
        dfs(image,sr,sc,color,target,m,n);

        return image;
    }
};