class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l = 0;
        int k = 0;

        int max = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > max){
                l = i;
                max = nums[i];
            }
        }

        max = INT_MIN;
        for(int j = 0;j<nums.size();j++){
            if(nums[j] > max && j!=l){
                k = j;
                max = nums[j];
            }
        }

        return (nums[k] - 1)*(nums[l] - 1);

        
    }
};