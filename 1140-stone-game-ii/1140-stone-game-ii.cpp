class Solution {
public:

    int solve(int i,int M,vector<vector<int>>&dp,vector<int>&suffix,int n){
        if(i + 2*M >= n)return suffix[i];

        if(dp[i][M] != -1)return dp[i][M];

        int ans = 0;

        for(int X = 1;X <= 2*M;X++){

            int opponent = solve(i + X,max(M,X),dp,suffix,n);
            ans = max(ans,suffix[i] - opponent);
        }

        return dp[i][M] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        
        int n = piles.size();
        vector<int>suffix(n+1,0);
        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        for(int i = n-1;i>=0;i--){
            suffix[i] = suffix[i+1] + piles[i];
        }

        return solve(0,1,dp,suffix,n);
    }
};