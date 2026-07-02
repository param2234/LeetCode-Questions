class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;

        int ans = 0;
        int n = s.size();
        int j = 0;

        for(int i = 0;i<n;i++){

            
            while(!(mp['a'] && mp['b'] && mp['c']) && j<n){
                mp[s[j]]++;
                j++;
            }
    
            if(mp['a'] && mp['b'] && mp['c']){
                ans += n-j+1;
            }

            mp[s[i]]--;

        }

        return ans;
    }
};