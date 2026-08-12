class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       int n = nums.size();

       int left = 0;
       int right = 0;
       int ans = 0;

       while(left < n && right < n){

            int num = nums[right];
            if(mp[num] < k){
                mp[num]++;
                right++;
            }
            else{
                mp[nums[left]]--;
                left++;
            }

            ans = max(ans , right - left );
       }

       return ans;
    }
};