class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int freq[2] = {0};
        int left = 0;
        int right = 0;
        int ans = INT_MAX;
        int len = 0;
        int start_idx;

        while(right < s.length()){


            freq[s[right] - '0']++;
            while(freq[1] >= k){
                int len = right - left + 1;

                if(freq[1] == k){
                    
                    if(len < ans){
                        start_idx = left;
                        ans = len;
                    }

                    else if(len == ans){
                        string curr = s.substr(left,len);
                        string best = s.substr(start_idx,ans);

                        if(curr < best){
                            start_idx = left;
                        }
                    }

                }
                freq[s[left] - '0']--;
                left++; 
            }

            right++;

        }

        if(ans == INT_MAX)return "";

        return s.substr(start_idx,ans);
    }
};