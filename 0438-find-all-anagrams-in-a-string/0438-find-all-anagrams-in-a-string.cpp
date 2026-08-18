class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>ans;

        vector<int>win(26,0);
        vector<int>str(26,0);

        for(char ch:p){
            str[ch - 'a']++;
        }

        int left = 0;
        int right = 0;

        while(right < s.size()){

            win[s[right] - 'a']++;

            if(right - left + 1 == p.size()){
                if(win == str){
                    ans.push_back(left);
                }

                win[s[left] - 'a']--;

                left++;
            }

            right++;

        }

        return ans;

    }
};