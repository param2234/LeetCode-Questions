class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;

        for(int x:nums){
            mp[x]++;
        }

        int count = 2;
        int temp = k;
        while(true){
            if(mp.find(temp)!=mp.end()){
                temp = k*count++;
            }
            else break;
        }

        return temp;
    }
};