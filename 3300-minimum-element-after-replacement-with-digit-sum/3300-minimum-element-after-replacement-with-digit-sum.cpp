class Solution {
public:
    int minElement(vector<int>& nums) {
        
        for(int i = 0;i<nums.size();i++){
            
            int ans = 0;
            int n = nums[i];

            while(n){
                int num = n % 10;
                n = n/10;
                ans += num;
            }
            nums[i] = ans;
        }

        return *min_element(nums.begin(),nums.end());
    }
};