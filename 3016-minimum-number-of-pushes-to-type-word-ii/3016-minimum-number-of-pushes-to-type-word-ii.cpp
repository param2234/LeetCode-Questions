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
        int curr = 0;
        int count = 1;

        while(n){
            int num = min(n,8);
            
            for(int i = curr;i<num + curr;i++){
                ans += freq[i] * count;
            }

            curr += num;
            n -= num;
            count++;

        }

        return ans;
    }
};