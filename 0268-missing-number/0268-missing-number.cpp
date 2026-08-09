class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        vector<int>arr(n+1,0);

        for(int x:nums){
            arr[x]++;
        }

        for(int i = 0;i<=n;i++){
            if(arr[i] == 0)return i;
        }

        return -1;
    }
};