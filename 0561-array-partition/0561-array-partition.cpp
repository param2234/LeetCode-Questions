class Solution {
public:
    int arrayPairSum(vector<int>& nums) {

        if(nums.size() == 0)return 0;
        sort(nums.begin(),nums.end());

        int ans = 0;
        int i = 0;
        while(i<nums.size()){
            ans+= nums[i];
            i+=2;
        }

        return ans;
    }
};