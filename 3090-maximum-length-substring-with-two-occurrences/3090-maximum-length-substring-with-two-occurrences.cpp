class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int ans = 0;
        int left = 0;
        int right = 0;
        unordered_map<char,int>mp;

        while(right < s.length()){

            if(mp[s[right]] < 2){
                mp[s[right]]++;
                right++;
            }

            else{
                mp[s[left]]--;
                left++;
            }

            ans = max(ans,right - left);
        }

        return ans;
    }
};