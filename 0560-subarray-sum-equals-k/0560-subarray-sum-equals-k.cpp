class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int prefixSum = 0;
        int ans = 0;

        // Empty prefix
        mp[0] = 1;

        for (int num : nums) {
            prefixSum += num;

            // Check if a previous prefix gives sum k
            if (mp.find(prefixSum - k) != mp.end()) {
                ans += mp[prefixSum - k];
            }

            // Store current prefix sum
            mp[prefixSum]++;
        }

        return ans;
    }
};