class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;

        for(int i:nums){
            mp[i]++;
        }

        if(nums.size() == k){

            return *max_element(nums.begin(),nums.end());
        }

        if(k == 1){

            int ans = INT_MIN;

            for(auto i:mp){
                if(i.second == 1){
                    if(i.first > ans)ans = i.first;
                }
            }

            if(ans == INT_MIN)return -1;

            return ans;
        }

        int a = nums[0];
        int b = nums[nums.size()-1];

        

        if(mp[a] != 1){
            a = INT_MIN;
        }

        if(mp[b]!=1){
            b = INT_MIN;
        }

        if(b == INT_MIN && a == INT_MIN){
            return -1;
        }

        return max(a,b);

        

    }


};