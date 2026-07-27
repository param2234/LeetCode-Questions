class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool>dp(nums.size(),false);
        dp[0] = true;

        for(int i = 1;i<nums.size();i++){
            for(int j= 0;j<i;j++){
                if(dp[j] && nums[j] + j >= i){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[nums.size() - 1];
    }
};