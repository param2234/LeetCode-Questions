class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int mn = *min_element(nums.begin(),nums.end());

        while(mn){
            int rem = mx % mn;
            mx = mn;
            mn = rem;
        }

        return mx;
    }
};