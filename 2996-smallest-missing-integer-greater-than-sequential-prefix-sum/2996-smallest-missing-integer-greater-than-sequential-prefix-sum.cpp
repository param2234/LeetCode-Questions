class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int>mp;

        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }

        int i = 0;
        int ans = 0;
        bool last = true;
        while(i<n-1){

            ans+=nums[i];

            if(nums[i+1] != nums[i] + 1){
                last = false;
                break;
            }

            i++;
        }

        if(last)ans+= nums[i];

        while(mp.find(ans) != mp.end()){
            ans++;
        }

        return ans;
    }
};