class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;

        for(char ch:word){
            mp[ch]++;
        }

        vector<int>freq;

        for(auto &i:mp){
            freq.push_back(i.second);
        }
        int n = freq.size();

        sort(freq.begin(),freq.end(),[](auto &a,auto &b){
            return a > b;
        });

        int ans = 0;
       
        for(int i = 0;i<n;i++){
            ans += freq[i] * (i/8 +1);
        }

        

        return ans;
    }
};