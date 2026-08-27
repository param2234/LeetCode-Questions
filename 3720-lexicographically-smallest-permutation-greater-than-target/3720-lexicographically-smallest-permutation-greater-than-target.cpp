class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int freq[26] = {0};

        for(char ch : s)
            freq[ch - 'a']++;

        string ans = "";

        for(int i = 0; i < target.size(); i++) {

            int x = target[i] - 'a';

            if(freq[x] > 0) {
                ans += target[i];
                freq[x]--;
            }
            else {

                // Try making current position greater
                for(int c = x + 1; c < 26; c++) {

                    if(freq[c] > 0) {

                        ans += char('a' + c);
                        freq[c]--;

                        for(int k = 0; k < 26; k++) {
                            while(freq[k] > 0) {
                                ans += char('a' + k);
                                freq[k]--;
                            }
                        }

                        return ans;
                    }
                }

                // Backtrack
                for(int j = i - 1; j >= 0; j--) {

                    freq[ans[j] - 'a']++;

                    for(int c = target[j] - 'a' + 1; c < 26; c++) {

                        if(freq[c] > 0) {

                            ans[j] = char('a' + c);
                            freq[c]--;

                            ans.resize(j + 1);

                            for(int k = 0; k < 26; k++) {
                                while(freq[k] > 0) {
                                    ans += char('a' + k);
                                    freq[k]--;
                                }
                            }

                            return ans;
                        }
                    }
                }

                return "";
            }
        }

        
        
        for(int j = target.size() - 1; j >= 0; j--) {

            freq[ans[j] - 'a']++;

            for(int c = target[j] - 'a' + 1; c < 26; c++) {

                if(freq[c] > 0) {

                    ans[j] = char('a' + c);
                    freq[c]--;

                    ans.resize(j + 1);

                    for(int k = 0; k < 26; k++) {
                        while(freq[k] > 0) {
                            ans += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};