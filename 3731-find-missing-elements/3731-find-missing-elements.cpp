class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        int mx = *max_element(nums.begin(),nums.end());
        int mn = *min_element(nums.begin(),nums.end());

        vector<int>count(mx + 1,0);
        vector<int>ans;

        for(int i:nums){
            count[i]++;
        }

        for(int i = mn;i<=mx;i++){
            if(!count[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};