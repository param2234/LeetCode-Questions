class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int prefixSum = 0;
        int ans = 0;
        mp[0] = 1;

        for (int num : nums) {
            prefixSum += num;

            
            if (mp.find(prefixSum - k) != mp.end()) {
                ans += mp[prefixSum - k];
            }

        
            mp[prefixSum]++;
        }

        return ans;
    }
};