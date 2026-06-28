class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);

        int prefix1 = 0;
        int suffix1 = 0;

        
        for (int i = 1; i < n; i++) {
            prefix1 += nums[i - 1];
            prefix[i] = prefix1;
        }

        
        for (int i = n - 2; i >= 0; i--) {
            suffix1 += nums[i + 1];
            suffix[i] = suffix1;
        }

       
        for (int i = 0; i < n; i++) {
            ans[i] = abs(prefix[i] - suffix[i]);
        }

        return ans;
    }
};